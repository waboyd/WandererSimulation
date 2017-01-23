#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Gatherer.h"

Gatherer::Gatherer(Map* map_ptr, Cell* start_cell) {
	map = map_ptr;
	location = start_cell;
}

Gatherer::Gatherer(Map* map_ptr, Cell* start_cell, int appetite) {
	map = map_ptr;
	location = start_cell;
	this->appetite = appetite;
}

Cell* Gatherer::find_best_place()
{
	// Find the best visible unoccupied cell to settle.  Return a pointer to that cell.
	int numRows = map->get_num_rows();
	int numCols = map->get_num_cols();

	int currentRow = location->get_row_num();
	int currentCol = location->get_col_num();

	int topRow, botRow;
int leftCol, rightCol;

// The best cell is the one with the most fruit;
int fruitHere = location->get_num_fruit();
Cell* bestCell = NULL;
int maxFruit = 0;

// Get the north and south boundaries of the search.
topRow = currentRow - view_range;
if (topRow < 0)
	topRow = 0;
botRow = currentRow + view_range;
if (botRow >= numRows)
botRow = numRows;

for (int checkRow = topRow; checkRow <= botRow; checkRow++) {
	// Get boundaries for square search area, with corners at North, South, East, West.
	int yDist = abs(checkRow - currentRow);
	int xDist = view_range - yDist;
	leftCol = currentCol - xDist;
	if (leftCol < 0)
		leftCol = 0;
	rightCol = currentCol + xDist;
	if (rightCol >= numCols)
		rightCol = numCols - 1;

	// Search this row for the best unoccupied cell.
	for (int checkCol = leftCol; checkCol <= rightCol; checkCol++) {
		Cell* checkCell = map->cells[checkRow][checkCol];
		int checkNumFruit = checkCell->get_num_fruit();
		if (checkNumFruit > maxFruit) {
			bestCell = checkCell;
			maxFruit = checkNumFruit;
		}
	}

}

// If there is not much difference between this cell and the best cell, staying here looks better.
if ((maxFruit <= fruitHere + appetite) && (location->isFree())) {
	destination = location;
	return location;
}

destination = bestCell;
return bestCell;
}

void Gatherer::move_to_cell(Cell* new_cell)
{
	location = new_cell;
}

void Gatherer::settle()
{
	location->occupy(this);
	isSettled = true;
}

void Gatherer::remain()
{
	if (location == NULL) {
		return;
	}
	location->remove_fruit(appetite);
	//if (location->get_num_fruit() < min_settle_fruit) {
	//	abandon();
	//}
}

void Gatherer::abandon()
{
	location->abandon();
	isSettled = false;
}

void Gatherer::free_will()
{
	// Choose and do an action based on the situation.
	if (isSettled) {
		// Stay at this location unless there is insufficient fruit here.
		if (location->get_num_fruit() >= min_settle_fruit) {
			remain();
		}
		else {
			abandon();
		}
	}
	else {
		// If the person plans to move, spend the day doing that.
		location->remove_fruit(appetite);	// Eat before moving.
		if ((destination != NULL) && (destination != location)) {
			move_to_cell(destination);
			destination = find_best_place();
		}
		else {
			// Look for the best visible place.  If the best place is here, settle.
			destination = find_best_place();
			if ((destination == location) && (location->isFree()) && 
					(location->get_num_fruit() >= min_settle_fruit)) {
				settle();
			}
		}
	}
}
