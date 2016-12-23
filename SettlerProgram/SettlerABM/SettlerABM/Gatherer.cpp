#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Gatherer.h"


Cell Gatherer::find_best_place()
{
	// Find the best visible cell to settle.  Return a pointer to that cell.
	int currentRow = location->get_row_num();
	int currentCol = location->get_col_num();

	int topRow, botRow;
	int leftCol, rightCol;

	topRow = currentRow - view_range;
	if (topRow < 0)
		topRow = 0;
	botRow = currentRow + view_range;
	int numRows = map->get_num_rows();
	if (botRow >= numRows)
		botRow = numRows;
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
