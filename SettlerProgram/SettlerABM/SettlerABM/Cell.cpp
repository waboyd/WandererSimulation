#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Cell.h"


bool Cell::isFree()
{
	if (this->owner == NULL) {
		return true;
	}
	else
		return false;
}

void Cell::occupy(Gatherer* new_owner)
{
	this->owner = new_owner;
}

void Cell::abandon()
{
	this->owner = NULL;
}

int Cell::get_num_fruit()
{
	return this->num_fruit;
}

void Cell::advance_time()
{
}

int Cell::remove_fruit(int amount)
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