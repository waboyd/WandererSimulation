#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Cell.h"

class Map
{
private:
	int num_rows;

	int num_cols;


public:
	void advance_time();

	Cell best_visible_cell(Cell start_cell);

};
#endif
