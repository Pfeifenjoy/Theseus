#include "layer.hpp"
#include <cassert>
#include <time.h>
#include "../gameobjects/brick.hpp"
#include "../gameobjects/floor.hpp"
#include <math.h>
#include "parking-area.hpp"

using namespace theseus::map;
using namespace theseus::gameobjects;
using namespace std;

Layer::Layer(unique_ptr<LevelDescription> description) {
	srand(time(NULL));

	auto dimensions = description->getDimensions();
	int width = (int) (dimensions.x / Brick::WIDTH);
	int height = (int) (dimensions.y / Brick::HEIGHT);

	this->layer = vector<vector<FieldStatus> > (width, vector<FieldStatus> (height, FREE));

	//Create a walls around the layer, that no object can leave the layer.
	this->addWall(0, 0, SOUTH, height);
	this->addWall(1, 0, EAST, width);
	this->addWall(1, height - 1, EAST, width - 1);
	this->addWall(width - 1, 1, SOUTH, height - 2);

	//Get rooms which must be placed on the layer first.
	this->populateRoomObjects(description->getRooms());

	//Fill the map with the rest of the rooms.
	//This process must not garanty that the rooms are set.
	sf::Vector2f minSizeF = description->getMinRoomSize();
	sf::Vector2f maxSizeF = description->getMaxRoomSize();
	sf::Vector2<int> minSize(floor(minSizeF.x / Brick::WIDTH), floor(minSizeF.y / Brick::HEIGHT));
	sf::Vector2<int> maxSize(floor(maxSizeF.x / Brick::WIDTH), floor(maxSizeF.y / Brick::HEIGHT));
	this->fillWithRooms(minSize, maxSize, description->getMaxAmountOfStandardRooms());

	//Repeat the wall generation with a different granularity
	//to make the layer more interesting
	int granularity;
	for(granularity = 16; granularity > 1; granularity >>= 1) {
		fillWithWalls(((width / 2) + (height / 2)) / 8, ((width / 2) + (height / 2)) / 2, granularity, ((width / 2)*(height / 2)) / 4);
	}

	//Transform the layer-matrix into gameobjects.
	this->generateGameObjectField();

	//Delete restricted fields of the layer.
	this->freeRestrictions();

	//Place all Positionable objects of the level-description.
	this->populateGameObjects(description->getFreeObjects());

	this->createParkingAreas();
}

void Layer::fillWithRooms(sf::Vector2<int> minSize, sf::Vector2<int> maxSize, int numRooms) {
	assert(numRooms >= 0);
	assert(minSize.x > 0 && minSize.y > 0);
	assert(maxSize.x >= minSize.x && maxSize.y >= minSize.y);
	while(numRooms--) {
		int width = rand() % ((maxSize.x - minSize.x) == 0 ? 1 : maxSize.x - minSize.x) + minSize.x;
		int height = rand() % ((maxSize.y - minSize.y) == 0 ? 1 : maxSize.y - minSize.y) + minSize.y;
		int x = (int) this->layer.size() - width < 0 ? 0 :
				rand() % (int) (this->layer.size() - width);
        int y = (int) this->layer[x].size() - height < 0 ? 0 :
				rand() % (int) (this->layer[x].size() - height);
		if(x < 2) x = 2;
		if(y < 2) y = 2;
		if(x > (int) this->layer.size() - 2 - width) x = (int) this->layer.size() - 2 -width;
		if(y > (int) this->layer[x].size() - 2 - height) y = (int) this->layer[x].size() - 2 - height;
		this->addRoom(x, y, width, height);
	}
}


bool Layer::checkField(int x, int y, int width /* = 1 */, int height /* = 1 */) {
	assert(width > 0);
	assert(height > 0);
	assert(x >= 0);
	assert(x + width < (int) this->layer.size());
	assert(y >= 0);
	assert(y + height < (int) this->layer[x].size());
	int i, j;
	for(i = x; i < x + width; i++) {
		for(j = y; j < y + height; j++) {
			switch(layer[i][j]) {
				case FREE: break;
				case VERTICAL_RESTRICTED:
							   if(i == 0 || i == x + width - 1) return false;
							   break;
				case HORIZONTAL_RESTRICTED:
							   if(j == 0 || j == y + height - 1) return false;
							   break;
				case RESTRICTED:
				case OCCUPIED: return false;
			}
		}
	}

	return true;
}

int Layer::drawLine(int x, int y, Direction direction, int length, FieldStatus status) {
	int realLength = 0;
	while(length--) {
		if(x < 0 || y < 0 || x >= (int) layer.size() || y >= (int) this->layer[x].size())
		   	return realLength;
		if(status == VERTICAL_RESTRICTED || status == HORIZONTAL_RESTRICTED)
			this->memorizedCorridorFloors.push_back(sf::Vector2<int> (x, y));
		if(status != OCCUPIED) {
			switch(this->layer[x][y]) {
				case OCCUPIED: if(status == OCCUPIED) return realLength; break;
				case RESTRICTED: if(status == OCCUPIED) return realLength;
				case VERTICAL_RESTRICTED: if(status == HORIZONTAL_RESTRICTED)
											  {
												  layer[x][y] = RESTRICTED; break;
											  }
				case HORIZONTAL_RESTRICTED: if(status == VERTICAL_RESTRICTED)
												 {
													 layer[x][y] = RESTRICTED; break;
												 }

				case FREE: layer[x][y] = status;
			}
		} else {
			if (layer[x][y] == OCCUPIED || layer[x][y] == RESTRICTED || (layer[x][y] != FREE && realLength == 0)){
				return realLength;
			}
			layer[x][y] = status;
		}
		realLength++;
		switch(direction) {
			case NORTH: y--; break;
			case WEST: x--; break;
			case SOUTH: y++; break;
			case EAST: x++; break;
		}
	}
	return realLength;
}

void Layer::addRoom(int x, int y, int width, int height) {
	if(checkField(x, y, width, height)){
		addWall(x, y, EAST, width);
		addWall(x, y + 1, SOUTH, height - 1);
		addWall(x + width - 1, y + 1, SOUTH, height - 1);
		addWall(x + 1, y + height - 1, EAST, width - 1);
		drawLine(x - 1, y - 1, EAST, width + 2, VERTICAL_RESTRICTED);
		drawLine(x - 1, y - 1, SOUTH, height + 2, HORIZONTAL_RESTRICTED);
		drawLine(x - 1, y + height, EAST, width + 2, VERTICAL_RESTRICTED);
		drawLine(x + width , y - 1, SOUTH, height + 2, HORIZONTAL_RESTRICTED);
		int i, j;
		for(i = x + 1; i < x + width -1; i++) {
			for(j = y + 1; j < y + height -1; j++) {
				layer[i][j] = RESTRICTED;
				setFloor(i, j, ROOM);
			}
		}
		this->addDoor(x, y, width, height);
		//sf::Vector2f position((x+1)*Brick::WIDTH, (y+1)*Brick::HEIGHT);
		//sf::Vector2f size((width - 1) * Brick::WIDTH, (height-1) * Brick::HEIGHT);
		//this->gameobjects.push_back(unique_ptr<Room> (new Room(position, size)));
	}
}

void Layer::addDoor(int x, int y, int width, int height) {
	int side = rand() % 4;
	int offset = rand() % ((side % 2 ? height : width) - 2) + 1;
	switch(side) {
		case 0: x += offset; break;
		case 1: y += offset; x += width - 1; break;
		case 2: x += offset; y += height - 1; break;
		case 3: y += offset; break;
	}
	this->layer[x][y] = RESTRICTED;
	setFloor(x, y, ROOM);
	switch(side) {
		case 0: y--; break;
		case 1: x++; break;
		case 2: y++; break;
		case 3: x--; break;
	}
	this->layer[x][y] = RESTRICTED;
}

void Layer::fillWithWalls(int minLength, int maxLength, int granularity, int numWalls) {
	assert(numWalls >= 0);
	assert(granularity % 2 == 0);
	assert(minLength > 0);
	assert(maxLength >= minLength);
    while(numWalls--) {
        int x = granularity * (rand() % ((this->layer.size() - 2) / granularity));
        int y = granularity * (rand() % ((this->layer[x].size() - 2) / granularity));
        Direction dir = Direction(rand() % 4);
        int length = granularity * ((rand() % (maxLength -minLength)) + minLength) ;
        this->addWall(x, y, dir, length);
    }
}

void Layer::generateGameObjectField() {
	int i, j;
	short k;
	for(i = 0; i < (int) layer.size() ; i++) {
		for(j = 0; j < (int) layer[i].size() ; j++) {
			if(this->layer[i][j] == FREE) {
				this->setFloor(i, j, CORRIDOR);
			}
			else if(this->layer[i][j] == OCCUPIED) {
				k = 0;
				if(j-1 >= 0)
					k += this->layer[i][j - 1] == OCCUPIED ? 2 : 0;
				if(i + 1 < (int) layer.size())
					k += this->layer[i + 1][j] == OCCUPIED ? 4 : 0;
				if(j + 1 < (int) layer[i].size())
					k += this->layer[i][j + 1] == OCCUPIED ? 8 : 0;
				if(i - 1 >= 0)
					k += this->layer[i - 1][j] == OCCUPIED ? 16 : 0;
				BrickType type = HORIZONAL;
				switch(k) {
					case 2: type = BOTTOM_END; break;
					case 4: type = LEFT_END; break;
					case 8: type = TOP_END; break;
					case 16: type = RIGHT_END; break;
					case 10: type = VERTICAL; break;
					case 20: type = HORIZONAL; break;
					case 6: type = EDGE_LEFT_BOTTOM; break;
					case 12: type = EDGE_LEFT_TOP; break;
					case 24: type = EDGE_RIGHT_TOP; break;
					case 18: type = EDGE_RIGHT_BOTTOM; break;
					case 22: type = T_UPSIDEDOWN_CROSS; break;
					case 14: type = LEFT_MIDDLE; break;
					case 28: type = T_CROSS; break;
					case 26: type = RIGHT_MIDDLE; break;
					case 30: type = CROSS; break;
				}
				unique_ptr<Brick > brick(new Brick(type, i, j));
				this->gameobjects.push_back(move(brick));
			}
		}
	}
	for(auto position : this->memorizedCorridorFloors) {
		setFloor(position.x, position.y, CORRIDOR);
	}
}

void Layer::setFloor(int x, int y, FloorType type) {
	int extraWidthLeft = 0;
	int extraWidthRight = 0;
	if(x > 0 && x < (int) this->layer.size()) {
		extraWidthLeft = layer[x-1][y] == OCCUPIED ? Brick::OFFSET : 0;
		extraWidthRight = layer[x+1][y] == OCCUPIED ? Brick::OFFSET : 0;
	}
	sf::Vector2f position(Brick::WIDTH * x - extraWidthLeft, Brick::HEIGHT * y);
	sf::Vector2f size(Brick::WIDTH + extraWidthRight + extraWidthLeft, Brick::HEIGHT);
	unique_ptr<Floor> floor(new Floor(position, size, type));
	this->gameobjects.push_back(move(floor));
}

void Layer::addWall(int x, int y, Direction direction, int length) {
	assert(length > 0);
	assert(x >= 0);
	assert(x < (int) this->layer.size());
	assert(y >= 0);
	assert(y < (int) this->layer[x].size());
	int realLength = drawLine(x, y, direction, length, OCCUPIED);
	if(realLength == 0) return;
}

void Layer::freeRestrictions() {
	for(auto& column: this->layer) {
		for(auto& field: column) {
			if(field != OCCUPIED && field != FREE) {
				field = FREE;
			}
		}
	}
}

vector<sf::Vector2<int> > Layer::getPossiblePlaces(sf::Vector2<int> position, sf::Vector2<int> area, sf::Vector2<int> size) {
	vector<sf::Vector2<int> > places;
	int i, j;
	for(i = position.x; i < position.x + area.x - size.x; i++) {
		for(j = position.y; j < position.y + area.y - size.y; j++) {
			if(checkField(i, j, size.x, size.y))
				places.push_back(sf::Vector2<int> (i, j));
		}
	}
	return places;
}
vector<sf::Vector2<int> > Layer::getPossiblePlaces(int width, int height) {
	return getPossiblePlaces(sf::Vector2<int> (0, 0),
			sf::Vector2<int> (this->layer.size(), this->layer[0].size()),
			sf::Vector2<int> (width, height));
}

void Layer::occupy(int x, int y, int width, int height) {
	int i, j;
	for(i = x; i < x + width; i++) {
		for(j = y; j < y + height; j++) {
			this->layer[i][j] = RESTRICTED;
		}
	}
}

void Layer::populateGameObjects(vector<unique_ptr<theseus::engine::components::Positionable> > freeGameObjects) {
	return this->populateGameObjects(move(freeGameObjects),
		   	sf::Vector2<int> (0,0),
			sf::Vector2<int> (this->layer.size(), this->layer[0].size()));
}

void Layer::populateGameObjects(vector<unique_ptr<theseus::engine::components::Positionable> > freeGameObjects, sf::Vector2<int> position, sf::Vector2<int> area) {
	for(auto& object : freeGameObjects) {
		sf::Vector2f topLeft = object->getPosition();
		sf::Vector2f rightBottom = object->getSize();
		int width = (int) ceil((rightBottom.x - topLeft.x) / Brick::WIDTH);
		int height = (int) ceil((rightBottom.y - topLeft.y) / Brick::HEIGHT);
		auto possiblePlaces = this->getPossiblePlaces(position, area, sf::Vector2<int> (width, height));
		if(possiblePlaces.size() > 0) {
			auto field = rand() % possiblePlaces.size();
			auto coords = possiblePlaces[field];
			sf::Vector2f position(coords.x * Brick::WIDTH, coords.y * Brick::HEIGHT);
			object->setPosition(position);
			this->gameobjects.push_back(move(object));
			this->occupy(coords.x, coords.y, width, height);
		}
	}
}

void Layer::populateRoomObjects(vector<unique_ptr<RoomDescription> > rooms) {
	for(auto& room: rooms) {
		int width = ceil(room->getWidth() / Brick::WIDTH);
		int height = ceil(room->getHeight() / Brick::HEIGHT);
		auto possiblePlaces = getPossiblePlaces(width + 1, height + 1);
		assert(possiblePlaces.size() > 0);
		if(possiblePlaces.size() != 0) {
			auto startField = rand() % possiblePlaces.size();
			auto position = possiblePlaces[startField];
			auto roomObjects = room->getGameObjects();
			this->populateGameObjects(move(roomObjects),
					position, sf::Vector2<int> (width, height));
			addRoom(position.x + 1, position.y + 1, width, height);
		}
	}
}

vector<unique_ptr<theseus::engine::GameObject> > Layer::getGameObjects() {
	return move(this->gameobjects);
}

unique_ptr<theseus::engine::Scene> Layer::toScene() {
	unique_ptr<theseus::engine::Scene> scene(new theseus::engine::Scene());
	auto objects = this->getGameObjects();
	for(auto& object: objects) {
		scene->addGameObject(move(object));
	}
	return scene;
}
void Layer::createParkingAreas() {
	sf::Vector2f position;
	sf::Vector2f size(128, 128);
	int i, j;
	for(i = -10; i < (int) this->layer.size() + 10; i++) {
		for(j = -10; j < 0; j++) {
			position = sf::Vector2f(i * size.x, j *size.y);
			this->gameobjects.push_back(unique_ptr<Floor> (new Floor(position, size, GRAS)));
		}
	}
	for(i = -10; i < (int) this->layer.size() + 10; i++) {
		for(j = 0; j <  10; j++) {
			position = sf::Vector2f(i * size.x, this->layer[0].size() * Brick::HEIGHT + j * size.y);
			this->gameobjects.push_back(unique_ptr<Floor> (new Floor(position, size, GRAS)));
		}
	}
	for(i = -10; i < 0; i++) {
		for(j = -10; j < (int) this->layer[0].size() + 10; j++) {
			position = sf::Vector2f(i * size.x + Brick::OFFSET, j *size.y);
			this->gameobjects.push_back(unique_ptr<Floor> (new Floor(position, size, GRAS)));
		}
	}
	for(i = 0; i < 10; i++) {
		for(j = -10; j < (int) this->layer[0].size() + 10; j++) {
			position = sf::Vector2f(this->layer.size() * Brick::WIDTH + i* size.x - Brick::OFFSET, j * size.y);
			this->gameobjects.push_back(unique_ptr<Floor> (new Floor(position, size, GRAS)));
		}
	}
	ParkingArea p1(sf::Vector2f (12, -5 * Brick::HEIGHT), sf::Vector2<int> (this->layer.size() * Brick::WIDTH, 4 * Brick::HEIGHT));
	auto slots = p1.getSlots();
	for(auto& slot : slots) {
		this->gameobjects.push_back(move(slot));
	}
	ParkingArea p2(sf::Vector2f (12, (this->layer[0].size()+1) * Brick::HEIGHT), sf::Vector2<int> (this->layer.size() * Brick::WIDTH, 4 * Brick::HEIGHT));
	slots = p2.getSlots();
	for(auto& slot : slots) {
		this->gameobjects.push_back(move(slot));
	}
}

ostream& theseus::map::operator<<(ostream& os, const Layer& layer) {
	int i = 0, j = 0;

	for(i = 0; i < (int) layer.layer[0].size(); i++) {
		for(j = 0; j < (int) layer.layer.size(); j++) {
			switch(layer.layer[j][i]) {
				case OCCUPIED: os <<"\x1B[33m"; break; //Yellow
				case FREE: os << "\x1B[34m"; break; //Blue
				case RESTRICTED: os << "\x1b[31m"; break; //Red
				case VERTICAL_RESTRICTED: os << "\x1b[32m"; break; //Green
				case HORIZONTAL_RESTRICTED: os << "\x1b[35m"; break; //Magenta
			}
			os << "\u2588";
		}
		os << endl;
	}
	os << "\x1B[0m";


	return os;
}
