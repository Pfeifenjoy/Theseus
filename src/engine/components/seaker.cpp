#include "seaker.hpp"
#include "../../gameobjects/brick.hpp"
#include <map>
#include <iostream>
#include <limits.h>

using namespace theseus::engine::components;
using namespace theseus::gameobjects;
using namespace theseus::map;
using namespace std;

void Seaker::setMap(Map *map) {
	this->map = map;
}

sf::Vector2<int> Seaker::nextDirection(sf::Vector2f target, int radius) {
//--------------------------------------------------
	auto positiont = Position::getPosition() + getCollisionAreaTopLeft() + (getCollisionAreaBottomRight() - getCollisionAreaTopLeft()) / (float)2;

	sf::Vector2<int> position(floor(positiont.x / theseus::gameobjects::Brick::WIDTH), floor(positiont.y / theseus::gameobjects::Brick::HEIGHT));
	goal = getPosition(sf::Vector2<int> (floor(target.x / theseus::gameobjects::Brick::WIDTH), floor(target.y / theseus::gameobjects::Brick::HEIGHT)));
	position = getPosition(position);


	if(this->map->map[position.x][position.y]) {
		auto fieldMiddle = sf::Vector2f(position.x * Brick::WIDTH + Brick::WIDTH / 2, position.y * Brick::HEIGHT + Brick::HEIGHT / 2);
		if(lastField != position) {
			if(abs(positiont.x - fieldMiddle.x) > 11 || abs(positiont.y - fieldMiddle.y) > 11) {
				cout << fieldMiddle.x - positiont.x << ", " << fieldMiddle.y - positiont.y << endl;
				int x = fieldMiddle.x - positiont.x > 0 ? 1 : -1;
				int y = fieldMiddle.y - positiont.y > 0 ? 1 : -1;
				return sf::Vector2<int>(x, y);
			} else {
				lastField = position;
			}
		}
	}

	int size = this->map->map.size();
	int source = position.x + position.y * size;
	int aim = goal.x + goal.y * size;
	//cout << "Player: " << goal.x << ", " << goal.y << endl;
	//cout << "Prof: " << position.x << ", " << position.y << endl;
	std::vector<int> path;


	std::map<int, float> dist;
	dist[source] = 0;

	std::map<int, int> backlink;

	std::set<int> nodes;

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < (int) this->map->map[0].size(); j++) {
			if(this->map->map[i][j])
				nodes.insert(i + j*size);
		}
	}
//	int i = 0, j = 0;
//
//	for(i = 0; i < (int) this->map->map[0].size(); i++) {
//		for(j = 0; j < (int) this->map->map.size(); j++) {
//			if(j == position.x && i == position.y)
//				cout << "\x1b[31m";
//			else if(j == goal.x && i == goal.y)
//				cout << "\x1b[32m";
//			else if(this->map->map[j][i]) {
//				cout << "\x1B[34m";//Blue
//			} else
//				cout <<"\x1B[33m"; //Yellow
//			cout << "\u2588";
//		}
//		cout << endl;
//	}
//	cout << "\x1B[0m";

	while(!nodes.empty()) {
		std::map<int, int> intersection;
		for(auto x: dist)
			if(nodes.find(x.first) != nodes.end())
				intersection.insert(x);

		pair<int, int> smallest(0, INT_MAX);
		for(auto x: intersection)
			if(x.second < smallest.second)
				smallest = x;

		nodes.erase(smallest.first);

//		auto distance = getPosition(smallest.first) - goal;
//		cout << distance.x << ", " << distance.y << endl;
//		if(distance.x <= 1 && distance.x >= -1 && distance.y <= 1 && distance.y >= -1)
//			break;

		if(smallest.second == INT_MAX || dist[smallest.first] > radius) {
			break;
		}

		auto edges = getEdges(smallest.first);
		for(auto e : edges) {
			if(dist.find(e.first) == dist.end() || smallest.second + 1 < dist[e.first]) {
				//dist[e.first] = smallest.second + 1;
				dist[e.first] = smallest.second + e.second;
				//cout << "ja: " << e.first % size << ", " << e.first / size << endl;
				backlink[e.first] = smallest.first;
			}

		}
	}

	int pos = aim;
	vector<int> backPath;
	while(pos != source) {
		if(pos == 0) break;
		backPath.push_back(pos);
		//cout << " -> (" << pos % size << ", " << pos / size  << ")";
		pos = backlink[pos];
	}
	//cout << endl;

	if(backPath.size() > 0) {
		auto next = getPosition(backPath.back()) - position;
		//cout << "next: " << next.x << ", " << next.y << endl;
		if(next.x <= 1 && next.x >= -1 && next.y <= 1 && next.y >= -1) {
			if(this->map->map[position.x + next.x][position.y + next.y]) {
				return next;
			}
		}
	}

	sf::Vector2i next(0, 0);
	do {
		//cout << "next: " << next.x << ", " << next.y << endl;
		int number = rand() % 9;

		switch (number)
		{
			case 0: next = sf::Vector2i( 0, 0); break; // NPC is not moving
			case 1: next = sf::Vector2i(-1, 0); break; // NPC is moving left
			case 2: next = sf::Vector2i( 1, 0); break; // NPC is moving right
			case 3: next = sf::Vector2i(0, -1); break; // NPC is moving up
			case 4: next = sf::Vector2i( 0, 1); break; // NPC is moving down
			case 5: next = sf::Vector2i(-1,-1); break; // NPC is moving left up
			case 6: next = sf::Vector2i(1, -1); break; // NPC is moving right up
			case 7: next = sf::Vector2i(-1, 1); break; // NPC is moving left down
			case 8: next = sf::Vector2i( 1, 1); break; // NPC is moving right down
		}
		//cout << "ja" << next.x << next.y<< endl;
	} while (this->map->map[position.x + next.x][position.y + next.y] == false);

	return next;
//----------------------------------------------------------------------------------------------------

//	for(auto x: backPath)
//		cout << x << endl;


//	std::map<int, int> dist;
//	std::map<int, int> fringe;
//	std::map<int, int> backEdge;
//	dist[source] = 0;
//	fringe.insert(pair<int, int> (0, source));
//
//	while (!fringe.empty()) {
//
//		cout << 2 << endl;
//		std::map<int, int> results;
//		for(auto x : fringe) {
//			auto q = getEdges(x.first);
//			for(auto y: q) {
//				if(y.second == x.first)
//					results.insert(x);
//			}
//		}
//
//		auto smallest = min_element(results.begin(), results.end(), results.value_comp());
//		auto distU = smallest->second;
//		auto u = smallest->first;
//
//		cout << u << endl;
//		if(smallest == results.end() || u == aim) {
//			path = constructPath(source, aim, backEdge);
//			break;
//		}
//		dist.erase(smallest);
//		for(auto edge : getEdges(u)) {
//			int v = edge.second;
//			if(dist.find(v) == dist.end()) {
//				int d = distU + 1;
//				dist[v] = d;
//				fringe.insert(pair<int, int> (d, v));
//				backEdge[v] = u;
//			}
//			else {
//				int oldDist = dist[v];
//				int newDist = dist[u] + 1;
//				if(newDist < oldDist) {
//					dist[v] = newDist;
//					fringe[newDist] = v;
//				}
//				backEdge[v] = u;
//			}
//		}
//	}
//
//	for(auto x : path) {
//		cout << " -> (" << x % size << ", " << x / size << ")";
//	}
//	cout << endl;

//	std::map<int, int> d;
//	std::map<int, int> prev;
//	d[source] = 0;
//
//	std::set<int> q;
//	for(int i = position.x - 10; i < position.x + 10; i++)
//		for(int j = position.y- 10; j < position.y + 10; j++)
//			if(j <0 || j >= size || i < 0 || i >= size) {
//				continue;
//			}
//			else if(this->map->map[i][j]) {
//				q.insert(i + j*size);
//			}
//
//
//	while(!q.empty()) {
//		std::map<int, int> results;
//		for(auto x : d) {
//			if(q.find(x.first) != q.end())
//				results.insert(x);
//		}
//		auto smallest = min_element(results.begin(), results.end(), results.value_comp());
//		auto u = smallest->first;
//		if(smallest == results.end() || u == aim) break;
//		q.erase(u);
//		auto neighbors = getEdges(u);
//		//cout << "Found neighbors: " << neighbors.size() << endl;
//		for(auto n : neighbors) {
//			if(d.find(n.second) == d.end() || d[u] + 1 < d[n.second]) {
//				d[n.second] = d[u] + 1;
//				prev[n.second] = u;
//			}
//		}
//	}

//	for(auto x : d)
//		cout << x.first << ", " << x.second <<  " - ";
//	cout << endl;

//	for(auto x : prev)
//		cout << "(" << x.first % size << ", " << x.first / size << ") -> (" << x.second % size << ", " << x.second / size << ") | ";
//	cout << endl;




//	vector<int> min_distance( graph.size(), INT_MAX );
//	min_distance[ position.x + position.y * this->map->map.size()] = 0;
//	set< pair<int,int> > active_vertices;
//	active_vertices.insert( {0,position.x + position.y * this->map->map.size()} );
//
//	while (!active_vertices.empty()) {
//        int where = active_vertices.begin()->second;
//        if (where == goal.x + goal.y * (int)this->map->map.size()) return min_distance[where];
//        active_vertices.erase( active_vertices.begin() );
//        for (auto edge : getEdges(where))
//            if (min_distance[edge.second] > min_distance[where] + 1) {
//                active_vertices.erase( { min_distance[edge.second], edge.second } );
//                min_distance[edge.second] = min_distance[where] + 1;
//                active_vertices.insert( { min_distance[edge.second], edge.second } );
//            }
//    }
//	return INT_MAX;



//	sf::Vector2<int> position(ceil(pos.x / theseus::gameobjects::Brick::WIDTH), ceil(pos.y / theseus::gameobjects::Brick::HEIGHT));
//	auto goal = this->map->getGoal();
//	int x, y;
//	if(goal.x - position.x > 0)
//	   x = 1;
//	else if (goal.x - position.x < 0)
//		x = -1;
//	else x = 0;
//
//	if(goal.y - position.y > 0)
//		y = 1;
//	else if(goal.y - position.y < 0)
//		y = -1;
//	else y = 0;
//	return sf::Vector2<int>(x, y);

	return sf::Vector2<int> (0, 0);
}

std::set<pair<int, float> > Seaker::getEdges(int node) {
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



//	if(y-1 > 0 && x - 1 > 0 && this->map->map[x-1][y-1])
//		edges.insert(pair<int, int> (x-1 + (y-1) * this->map->map.size(), 1.4));
//	if(y-1 > 0 && this->map->map[x][y-1])
//		edges.insert(pair<int, int> (x + (y-1) * this->map->map.size(), 1));
//	if(y-1 > 0 && x + 1 < size && this->map->map[x+1][y-1])
//		edges.insert(pair<int, int> (x+1 + (y-1) * this->map->map.size(), 1.4));
//	if(x - 1 > 0 && this->map->map[x-1][y])
//		edges.insert(pair<int, int> (x-1 + (y) * this->map->map.size(), 1));
//	if(x + 1 < size && this->map->map[x+1][y])
//		edges.insert(pair<int, int> (x+1 + (y) * this->map->map.size(), 1));
//	if(y + 1 < size && x - 1 > 0 && this->map->map[x-1][y+1])
//		edges.insert(pair<int, int> (x-1 + (y+1) * this->map->map.size(), 1.4));
//	if(y + 1 < size && this->map->map[x][y+1])
//		edges.insert(pair<int, int> (x + (y+1) * this->map->map.size(), 1.4));
//	if(y + 1 < size && x + 1 < size && this->map->map[x+1][y+1])
//		edges.insert(pair<int, int> (x+1 + (y+1) * this->map->map.size(), 1.4));
	return edges;
}

std::vector<int> Seaker::constructPath(int source, int goal, std::map<int, int> backEdge) {
	vector<int> result;
	if(source == goal) {
		result.push_back(source);
		return result;
	}
	int n = backEdge[goal];
	result = constructPath(source, n, backEdge);
	result.push_back(goal);
	return result;
}

sf::Vector2<int> Seaker::getPosition(int position) {
	return sf::Vector2<int> (position % this->map->map.size(), position / this->map->map.size());
}

sf::Vector2<int> Seaker::next(sf::Vector2<int> c) {
//	if(c.x == 0 && c.y == -1)
//		return sf::Vector2<int> (1, 0);
//	if(c.x == 1 && c.y == 0)
//		return sf::Vector2<int> (0, 1);
//	if(c.x == 0 && c.y == 1)
//		return sf::Vector2<int> (-1, 0);
//	if(c.x == -1 && c.y == 0)
//		return sf::Vector2<int> (0, -1);

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

sf::Vector2<int> Seaker::getPosition(sf::Vector2<int> position) {
	if(this->map->map[position.x][position.y] == false) {
		position.y--;
	}
//	if(this->map->map[position.x][position.y] == false) {
//		auto positiont = Position::getPosition() + getCollisionAreaTopLeft();
//		positiont.x += theseus::gameobjects::Brick::OFFSET;
//		position = sf::Vector2<int>(floor(positiont.x / theseus::gameobjects::Brick::WIDTH), floor(positiont.y / theseus::gameobjects::Brick::HEIGHT));
//	}
	return position;
}
