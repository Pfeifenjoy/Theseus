#include "seeker.hpp"
#include "../../gameobjects/brick.hpp"
#include <map>
#include <limits.h>
#include <cmath>

using namespace theseus::engine::components;
using namespace theseus::gameobjects;
using namespace theseus::map;
using namespace std;

const short TOLERANCE = 11;

void Seeker::setMap(Map *map) {
	this->map = map;
}

sf::Vector2<int> Seeker::nextDirection(sf::Vector2f target, int radius) {
	auto positiont = Position::getPosition() + getCollisionAreaTopLeft() + (getCollisionAreaBottomRight() - getCollisionAreaTopLeft()) / (float)2;
	sf::Vector2<int> position(floor(positiont.x / theseus::gameobjects::Brick::WIDTH), floor(positiont.y / theseus::gameobjects::Brick::HEIGHT));

	//The position which shell be reached
	goal = getPosition_(sf::Vector2<int> (floor(target.x / theseus::gameobjects::Brick::WIDTH), floor(target.y / theseus::gameobjects::Brick::HEIGHT)));
	//The current position of the seeker
	position = getPosition_(position);

	//Check weather the seeker is in the middle of a field on the grid.
	//If not the seeker will be directed there to prevent collisions with doors.
	if(this->map->map[position.x][position.y]) {
		auto fieldMiddle = sf::Vector2f(position.x * Brick::WIDTH + Brick::WIDTH / 2, position.y * Brick::HEIGHT + Brick::HEIGHT / 2);
		if(lastField != position) {
			if(abs(positiont.x - fieldMiddle.x) > TOLERANCE || abs(positiont.y - fieldMiddle.y) > TOLERANCE) {
				int x = fieldMiddle.x - positiont.x > 0 ? 1 : -1;
				int y = fieldMiddle.y - positiont.y > 0 ? 1 : -1;
				return sf::Vector2<int>(x, y);
			} else {
				lastField = position;
			}
		}
	}

	//Data which is needed later. These are aliases
	int size = this->map->map.size();

	//change the identifier of a field from a tuple/vector (x, y) to a unique id.
	//The id is calculated like: x + size*y
	int source = position.x + position.y * size;
	int aim = goal.x + goal.y * size;

	//Distances from position to fields.
	std::map<int, float> dist;
	//Obviously the distance to the source is 0.
	dist[source] = 0;
	//Remembers all shortest paths. Saves the field where the seeker has to go depending on a
	//given location.
	std::map<int, int> backlink;
	//All fields which have not been checked for the shortest path.
	std::set<int> nodes;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < (int) this->map->map[0].size(); j++) {
			if(this->map->map[i][j])
				nodes.insert(i + j*size);
		}
	}

	//Here starts the shortest path calculation. This is basically a dijkstra algorithm.
	while(!nodes.empty()) {
		//Get the nearest field which has not been visited yet.
		std::map<int, int> intersection;
		for(auto x: dist)
			if(nodes.find(x.first) != nodes.end())
				intersection.insert(x);

		pair<int, int> smallest(0, INT_MAX);
		for(auto x: intersection)
			if(x.second < smallest.second)
				smallest = x;
		nodes.erase(smallest.first);

		//Check if the goal is reached or the search radius is exited.
		if(smallest.second == INT_MAX || dist[smallest.first] > radius || smallest.first == aim) {
			break;
		}

		//Get the nearest neighbor.
		auto edges = getEdges(smallest.first);
		for(auto e : edges) {
			if(dist.find(e.first) == dist.end() || smallest.second + 1 < dist[e.first]) {
				//Save the distance.
				dist[e.first] = smallest.second + e.second;
				//Save the path.
				backlink[e.first] = smallest.first;
			}
		}
	}

	//Calculate the path from the goal to the seeker.
	//This path is the invert of the path which needs to be found.
	int pos = aim;
	vector<int> backPath;
	while(pos != source) {
		if(pos == 0) break;
		backPath.push_back(pos);
		pos = backlink[pos];
	}


	if(backPath.size() > 0) {//If the goal has been reached.
		//return the next move, if it is on the map.
		auto next = getPosition_(backPath.back()) - position;
		if(next.x <= 1 && next.x >= -1 && next.y <= 1 && next.y >= -1) {
			if(this->map->map[position.x + next.x][position.y + next.y]) {
				return next;
			}
		}
	}

	//If no prediction can be made return the 0 vector.
	sf::Vector2i next(0, 0);
	return next;
}

std::set<pair<int, float> > Seeker::getEdges(int node) {
	std::set<pair<int, float> > edges;
	int size = this->map->map.size();
	int x = node % size;
	int y = node / size;

	sf::Vector2<int> d;
	if(goal.x - x > 0)
	   d.x = 1;
	else if (goal.x - x < 0)
		d.x = -1;
	else d.x = 0;

	if(goal.y - y > 0)
		d.y = 1;
	else if(goal.y - y < 0)
		d.y = -1;
	else d.y = 0;

	for(int i = 0; i < 8; i++) {
		if(x + d.x >= 0 && x + d.x < size && y + d.y >= 0 && y + d.y < size && this->map->map[x + d.x][y+d.y]){
			float length = abs(d.x) + abs(d.y) > 1 ? 1.4 : 1;
			edges.insert(pair<int,int>(x+d.x + (y+d.y)*size, length));
		}
		d = next(d);
	}
	return edges;
}

sf::Vector2<int> Seeker::getPosition_(int position) {
	return sf::Vector2<int> (position % this->map->map.size(), position / this->map->map.size());
}

sf::Vector2<int> Seeker::next(sf::Vector2<int> c) {
	if(c.x == -1 && c.y == -1)
		return sf::Vector2<int> (0, -1);
	if(c.x == 0 && c.y == -1)
		return sf::Vector2<int> (1, -1);
	if(c.x == 1 && c.y == -1)
		return sf::Vector2<int> (1, 0);
	if(c.x == 1 && c.y == 0)
		return sf::Vector2<int> (1,1);
	if(c.x == 1 && c.y == 1)
		return sf::Vector2<int> (0, 1);
	if(c.x == 0 && c.y == 1)
		return sf::Vector2<int> (-1, 1);
	if(c.x == -1 && c.y == 1)
		return sf::Vector2<int> (-1, 0);
	if(c.x == -1 && c.y == 0)
		return sf::Vector2<int> (-1,-1);
	return sf::Vector2<int>(0,0); //This will never happen
}

sf::Vector2<int> Seeker::getPosition_(sf::Vector2<int> position) {
	if(this->map->map[position.x][position.y] == false) {
		position.y--;
	}
	return position;
}
