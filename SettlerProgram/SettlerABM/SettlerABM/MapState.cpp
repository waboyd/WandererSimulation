// Created by William Boyd of Arizona State University.

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
	time = 0;
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
// Allow a time step to pass for the map.
{
	for (int rowNum = 0; rowNum < num_rows; rowNum++) {
		for (int colNum = 0; colNum < num_cols; colNum++) {
			cells[rowNum][colNum]->advance_time();
		}
	}
	time += 1;
	// Make a text file for the current state of the map.
	this->create_output_map();
}

//MapCell* Map::best_visible_cell(MapCell start_cell)
//{
//	return 0;
//}

int MapState::get_num_rows()
{
	return num_rows;
}

int MapState::get_num_cols()
{
	return num_cols;
}

void MapState::create_output_map()
// Make a text file that shows the current state of the map.
{
	std::string mapFile;
	mapFile = OUTPUT_MAP_FOLDER;
	mapFile += "state_map_time_" + std::to_string(this->time) + ".txt";

	// ToDo: complete this method definition.
	// Create a temporary OutputMap object.
	OutputMap mapObject = OutputMap(this->num_rows, this->num_cols, this->time);

	// Set the values of the OutputMap object.
	for (int rowNum = 0; rowNum < this->num_rows; rowNum++) {
		for (int colNum = 0; colNum < this->num_cols; colNum++) {
			mapObject.set_filepath(mapFile);
			mapObject.set_num_fruit(rowNum, colNum, cells[rowNum][colNum]->get_num_fruit());
			mapObject.set_num_people(rowNum, colNum, cells[rowNum][colNum]->get_num_gatherers());
			if (cells[rowNum][colNum]->isFree()) {
				mapObject.set_not_settled(rowNum, colNum);
			}
			else {
				mapObject.set_settled(rowNum, colNum);
			}
		}
	}

	// Make the map text file.
	mapObject.create_text_map();

	// mapObject should be deleted as a local object upon return from this function.
}
