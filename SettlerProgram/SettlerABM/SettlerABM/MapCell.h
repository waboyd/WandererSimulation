#ifndef MAPCELL_H
#define MAPCELL_H

#define MAX_GEN_RATE	3
#define MAX_NUM_FRUIT	100

#define FRUIT_REGEN_RATE		3

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <random>

#include "Gatherer.h"

class Gatherer;
class MapState;
class MapCell
{
	friend class MapState;

private:
	Gatherer* owner = NULL;

	int num_fruit;

	int gen_rate;

	int row_num;

	int col_num;

	int num_gatherers;

protected:
	void advance_time();

public:
	MapCell(int row, int col);

	bool isFree();

	void occupy(Gatherer* new_owner);

	void abandon();

	int get_num_fruit();

	int remove_fruit(int amount);

	int get_row_num();

	int get_col_num();

};
#endif
