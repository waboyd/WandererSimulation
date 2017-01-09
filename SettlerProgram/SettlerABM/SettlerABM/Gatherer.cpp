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
	Cell* bestCell = location;
	int maxFruit = location->get_num_fruit();

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
	if (location->get_num_fruit() < 4 * appetite) {
		abandon();
	}
}

void Gatherer::abandon()
{
	location->abandon();
	isSettled = false;
}
