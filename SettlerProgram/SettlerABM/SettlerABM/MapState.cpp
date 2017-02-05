#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "MapState.h"


MapState::MapState(int rows, int cols)
{
	num_rows = rows;
	num_cols = cols;
	std::vector<std::vector<MapCell*>> newMap(rows, std::vector<MapCell*>(cols));
	for (int rowNum = 0; rowNum < rows; rowNum++) {
		for (int colNum = 0; colNum < cols; colNum++) {
			MapCell* newCell = new MapCell(rowNum, colNum);
			newMap[rowNum][colNum] = newCell;
		}
	}
	cells = newMap;
}

MapState::~MapState()
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

void MapState::advance_time()
{
	for (int rowNum = 0; rowNum < num_rows; rowNum++) {
		for (int colNum = 0; colNum < num_cols; colNum++) {
			cells[rowNum][colNum]->advance_time();
		}
	}
}

//MapCell* Map::best_visible_cell(MapCell start_cell)
//{
//	return 0;
//}

int MapState::get_num_rows() {
	return num_rows;
}

int MapState::get_num_cols() {
	return num_cols;
}