#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Cell.h"

class Cell;
class Gatherer;

class Map
{
private:
	int num_rows;

	int num_cols;

public:
	Map(int rows, int cols);

	~Map();

	std::vector<std::vector<Cell*>> cells;

	void advance_time();

	//Cell* best_visible_cell(Cell start_cell);

	int get_num_rows();

	int get_num_cols();

};
#endif
