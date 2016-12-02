#ifndef CELL_H
#define CELL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Gatherer.h"

class Cell
{
private:
	Gatherer* owner;

	int num_fruit;


protected:
	void advance_time();

public:
	bool isFree();

	void occupy(Gatherer* new_owner);

	void abandon();

	int get_num_fruit();

	int remove_fruit(int amount);

};
#endif
