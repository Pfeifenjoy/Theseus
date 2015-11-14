#include "map.hpp"
#include <math.h>
#include "../gameobjects/brick.hpp"
#include <iostream>

using namespace theseus::map;
using namespace std;

Map::Map(vector<vector<FieldStatus> >& layer) {
	this->map = vector<vector<int> > (layer.size(), vector<int> (layer[0].size()));
	int i, j;
	for(i = 0; i < (int) layer.size(); i++) {
		for(j = 0; j < (int) layer[i].size(); j++) {
			if(layer[i][j] == OCCUPIED)
				this->map[i][j] = false;
			else {
				this->map[i][j] = true;
			}
		}
	}
}

