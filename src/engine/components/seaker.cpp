#include "seaker.hpp"
#include "../../gameobjects/brick.hpp"
#include <map>
#include <iostream>
#include <limits.h>

using namespace theseus::engine::components;
using namespace theseus::map;
using namespace std;

void Seaker::setMap(Map *map) {
	this->map = map;
}

sf::Vector2<int> Seaker::nextDirection() {
//--------------------------------------------------
	auto positiont = Position::getPosition() + getCollisionAreaTopLeft();
	sf::Vector2<int> position(round(positiont.x / theseus::gameobjects::Brick::WIDTH), round(positiont.y / theseus::gameobjects::Brick::HEIGHT));
	auto goal = this->map->getGoal();
	int size = this->map->map.size();
	int source = position.x + position.y * size;
	int aim = goal.x + goal.y * size;
	cout << "Player: " << goal.x << ", " << goal.y << endl;
	cout << "Prof: " << position.x << ", " << position.y << endl;
	std::vector<int> path;


	std::map<int, int> dist;
	dist[source] = 0;

	std::map<int, int> backlink;

	std::set<int> nodes;

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < (int) this->map->map[0].size(); j++) {
			if(this->map->map[i][j])
				nodes.insert(i + j*size);
		}
	}

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

		if(smallest.second == INT_MAX || dist[smallest.first] == 10) {
			break;
		}

		auto edges = getEdges(smallest.first);
		for(auto e : edges) {
			if(dist.find(e.second) == dist.end() || smallest.second + 1 < dist[e.second]) {
				dist[e.second] = smallest.second + 1;
				//cout << "ja: " << e.second % size << ", " << e.second / size << endl;
				backlink[e.second] = smallest.first;
			}

		}
	}

	int pos = aim;
	vector<int> backPath;
	while(pos != source) {
		if(pos == 0) break;
		backPath.push_back(pos);
		cout << " -> (" << pos % size << ", " << pos / size  << ")";
		pos = backlink[pos];
	}
	cout << endl;

	if(backPath.size() > 0) {
		auto next = getPosition(backPath.back()) - position;
		cout << "next: " << next.x << ", " << next.y << endl;
		if(next.x <= 1 && next.x >= -1 && next.y <= 1 && next.y >= -1) {
			if(this->map->map[position.x + next.x][position.y + next.y]) {
				return next;
			}
		}
	}

	sf::Vector2i next(0, 0);
	while (this->map->map[position.x + next.x][position.y + next.y] == false) {
		cout << "next: " << next.x << ", " << next.y << endl;
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
	}

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

std::set<pair<int, int> > Seaker::getEdges(int node) {
	std::set<pair<int, int> > edges;
	int size = this->map->map.size();
	int x = node % size;
	int y = node / size;

	if(y-1 > 0 && x - 1 > 0 && this->map->map[x-1][y-1])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x-1 + (y-1) * this->map->map.size()));
	if(y-1 > 0 && this->map->map[x][y-1])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x + (y-1) * this->map->map.size()));
	if(y-1 > 0 && x + 1 < size && this->map->map[x+1][y-1])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x+1 + (y-1) * this->map->map.size()));
	if(x - 1 > 0 && this->map->map[x-1][y])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x-1 + (y) * this->map->map.size()));
	if(x + 1 < size && this->map->map[x+1][y])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x+1 + (y) * this->map->map.size()));
	if(y + 1 < size && x - 1 > 0 && this->map->map[x-1][y+1])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x-1 + (y+1) * this->map->map.size()));
	if(y + 1 < size && this->map->map[x][y+1])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x + (y+1) * this->map->map.size()));
	if(y + 1 < size && x + 1 < size && this->map->map[x+1][y+1])
		edges.insert(pair<int, int> (x + y * this->map->map.size(), x+1 + (y+1) * this->map->map.size()));
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
