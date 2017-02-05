#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MapCell.h"

std::default_random_engine rand_engine;
std::uniform_int_distribution<int> rand_rate(0, MAX_GEN_RATE);
std::uniform_int_distribution<int> rand_num_fruit(0, MAX_NUM_FRUIT);

MapCell::MapCell(int row, int col)
{
	row_num = row;
	col_num = col;
	gen_rate = rand_rate(rand_engine);
	num_fruit = rand_num_fruit(rand_engine);
}

bool MapCell::isFree()
{
	if (this->owner == NULL) {
		return true;
	}
	else
		return false;
}

void MapCell::occupy(Gatherer* new_owner)
{
	this->owner = new_owner;
}

void MapCell::abandon()
{
	this->owner = NULL;
}

int MapCell::get_num_fruit()
{
	return this->num_fruit;
}

void MapCell::advance_time()
{
	num_fruit += gen_rate;
//	if (owner == NULL) {
//		num_fruit += gen_rate;
//	}
//	else {
//		owner->remain();
//		num_fruit += gen_rate;
//	}
}

int MapCell::remove_fruit(int amount)
{
	if (amount <= this->num_fruit) {
		this->num_fruit -= amount;
		return amount;
	}
	else {
		int remaining_fruit = this->num_fruit;
		this->num_fruit = 0;
		return remaining_fruit;
	}

}

int MapCell::get_row_num()
{
	return row_num;
}

int MapCell::get_col_num()
{
	return col_num;
}
