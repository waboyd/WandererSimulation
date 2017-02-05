#ifndef GATHERER_H
#define GATHERER_H

#define PERSON_APPETITE			5
#define MIN_SETTLE_FRUIT		20

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MapCell.h"
#include "MapState.h"

class MapCell;
class MapState;

class Gatherer
{
private:
	int view_range;

	MapCell* location;

	bool isSettled;

	int appetite;

	//int fruit_saved;

	int min_settle_fruit;	// minimum amount of fruit for the person to settle the location

	MapCell* destination = NULL;

	MapState* map;

	MapCell* find_best_place();

	void move_to_cell(MapCell* new_cell);

	void settle();

	void remain();

	void abandon();

public:
	Gatherer(MapState* map_ptr, MapCell* start_cell);

	Gatherer(MapState* map_ptr, MapCell* start_cell, int appetite);

	void free_will();

	MapCell* get_location();
};
#endif
