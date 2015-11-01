#include "wall.hpp"

using namespace theseus::gameobjects::map;
using namespace std;

Wall::Wall(int x, int y, Direction direction, int brickLength) {
	this->x = x;
	this->y = y;
	this->direction = direction;
	while(brickLength--) {
		BrickType brickType = direction % 2 == 0 ? VERTICAL : HORIZONAL;
		sf::Vector2f position(x * Brick::WIDTH, y * Brick::HEIGHT);
		shared_ptr<Brick> brick(new Brick(brickType, position, position));
	}
}

vector<shared_ptr<theseus::engine::GameObject> > Wall::getGameObjects() {
	vector<shared_ptr<theseus::engine::GameObject> > result;
	for(auto object: this->bricks) {
		result.push_back(object);
	}
	return result;
}

void Wall::setSpecialBrick(int x, int y, BrickType brickType) {
	if(this->x == x && y >= this->y && y < this->y + (int) this->bricks.size()) {
		this->bricks[y - this->y]->setType(brickType);
	} else if(this->y == y && x >= this->x && x < this->x + (int) this->bricks.size()) {
		this->bricks[x - this->x]->setType(brickType);
	} else {
		//Brick is not on wall.
	}
}
