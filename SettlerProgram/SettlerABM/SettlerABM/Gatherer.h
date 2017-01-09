#ifndef GATHERER_H
#define GATHERER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Cell.h"
#include "Map.h"

class Cell;
class Map;

class Gatherer
{
private:
	int view_range;

	Cell* location;

	bool isSettled;

	int appetite;

	int fruit_saved;

	Cell* destination;

	Map* map;

public:
	Gatherer(Map* map_ptr, Cell* start_cell);

	Gatherer(Map* map_ptr, Cell* start_cell, int appetite);

	Cell* find_best_place();

	void move_to_cell(Cell* new_cell);

	void settle();

	void remain();

	void abandon();
};
#endif
