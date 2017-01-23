#ifndef GATHERER_H
#define GATHERER_H

#define PERSON_APPETITE			5
#define MIN_SETTLE_FRUIT		20

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

	//int fruit_saved;

	int min_settle_fruit;	// minimum amount of fruit for the person to settle the location

	Cell* destination = NULL;

	Map* map;

	Cell* find_best_place();

	void move_to_cell(Cell* new_cell);

	void settle();

	void remain();

	void abandon();

public:
	Gatherer(Map* map_ptr, Cell* start_cell);

	Gatherer(Map* map_ptr, Cell* start_cell, int appetite);

	void free_will();
};
#endif
