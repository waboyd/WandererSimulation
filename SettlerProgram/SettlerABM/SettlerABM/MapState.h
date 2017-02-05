#ifndef MAPSTATE_H
#define MAPSTATE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MapCell.h"

class MapCell;
class Gatherer;

class MapState
{
private:
	int num_rows;

	int num_cols;

	int time;

public:
	std::vector<std::vector<MapCell*>> cells;

	MapState(int rows, int cols);

	~MapState();

	void advance_time();

	//Cell* best_visible_cell(MapCell start_cell);

	int get_num_rows();

	int get_num_cols();

	void create_output_map();

};
#endif
