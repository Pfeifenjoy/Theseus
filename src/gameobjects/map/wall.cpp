#include "wall.hpp"
#include <iostream>

using namespace theseus::gameobjects::map;
using namespace std;

Wall::Wall(int x, int y, Direction direction, int brickLength) {
	this->x = x;
	this->y = y;
	this->direction = direction;
	int tx = 0;
	int ty = 0;
	while(brickLength--) {
		BrickType brickType = direction == NORTH || direction == SOUTH ? VERTICAL : HORIZONAL;
		sf::Vector2f position((x + tx) * Brick::WIDTH, (y + ty) * Brick::HEIGHT);
		sf::Vector2f size(Brick::WIDTH, Brick::HEIGHT);
		unique_ptr<Brick> brick(new Brick(brickType, position, size));
		this->bricks.push_back(move(brick));
		switch(direction) {
			case NORTH: y--; break;
			case WEST: x--; break;
			case SOUTH: y++; break;
			case EAST: x++; break;
		}
	}
}

vector<unique_ptr<theseus::engine::GameObject> > Wall::getGameObjects() {
	vector<unique_ptr<theseus::engine::GameObject> > result;
	for(auto& object: this->bricks) {
		result.push_back(move(object));
	}
	return result;
}

void Wall::setSpecialBrick(int x, int y, BrickType brickType) {
	switch(this->direction) {
		case NORTH: if(this->x == x && y <= this->y && y > this->y - (int) this->bricks.size())
						this->bricks[this->y - y]->setType(brickType); break;
		case EAST: if(this->y == y && x >= this->x && x < this->x + (int) this->bricks.size())
					   this->bricks[x - this->x]->setType(brickType);break;
		case SOUTH: if(this->x == x && y >= this->y && y < this->y + (int) this->bricks.size())
						this->bricks[y - this->y]->setType(brickType);
		case WEST: if(this->y == y && x <= this->x && x > this->x - (int) this->bricks.size())
					   this->bricks[this->x - x]->setType(brickType); break;
	}
}
