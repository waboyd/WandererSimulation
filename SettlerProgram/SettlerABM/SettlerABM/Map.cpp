#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Map.h"


Map::Map(int rows, int cols)
{
	num_rows = rows;
	num_cols = cols;
	std::vector<std::vector<Cell*>> newMap(rows, std::vector<Cell*>(cols));
	for (int rowNum = 0; rowNum < rows; rowNum++) {
		for (int colNum = 0; colNum < cols; colNum++) {
			Cell* newCell = new Cell(rowNum, colNum);
			newMap[rowNum][colNum] = newCell;
		}
	}
	cells = newMap;
}

Map::~Map()
{
	// Delete all cells of the map.
	while (!cells.empty()) {
		while (!cells.back().empty()) {
			delete (cells.back().back());
			cells.back().pop_back();
		}
		cells.pop_back();
	}
}

void Map::advance_time()
{
	for (int rowNum = 0; rowNum < num_rows; rowNum++) {
		for (int colNum = 0; colNum < num_cols; colNum++) {
			cells[rowNum][colNum]->advance_time();
		}
	}
}

Cell* Map::best_visible_cell(Cell start_cell)
{
	return 0;
}

int Map::get_num_rows() {
	return num_rows;
}

int Map::get_num_cols() {
	return num_cols;
}