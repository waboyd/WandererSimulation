#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <assert.h>

#include "OutputMap.h"


OutputMap::OutputMap(int num_rows, int num_cols, int time)
{
	this->num_rows = num_rows;
	this->num_cols = num_cols;
	this->time = time;
	int rowNum;
	for (rowNum = 0; rowNum < num_rows; rowNum++) {
		std::vector<int> newNumPeopleRow;
		newNumPeopleRow.assign(num_cols, 0);
		num_people.push_back(newNumPeopleRow);
		std::vector<bool> newIsOccupiedRow;
		newIsOccupiedRow.assign(num_cols, false);
		is_settled.push_back(newIsOccupiedRow);
		std::vector<int> newNumFruitRow(num_cols);
		newNumFruitRow.assign(num_cols, 0);
		num_fruit.push_back(newNumFruitRow);
	}
}

void OutputMap::create_text_map(std::string file_path)
{
	std::string header, body, row, entry;
	header = "State at time " + std::to_string(time) + "\n";
	header += "S = settled, X = not settled\n";
	header += "The top number (right of the letter) is the number of people at the cell.\n";
	header += "The bottom number (under the letter) is the number of fruit at the end of time " + std::to_string(time);
	header += "\n\n";

	body = "";
	for (int rowNum = 0; rowNum < num_rows; rowNum++) {
		// Make the top part of the entries: whether settled and number of people.
		row = "";
		for (int colNum = 0; colNum < num_cols; colNum++) {
			if (is_settled[rowNum][colNum])
				entry = "S";
			else
				entry = "X";
			entry += std::to_string(num_people[rowNum][colNum]);
			entry.resize(MAX_CHARACTERS_PER_ENTRY, ' ');
			row += entry + " ";
		}
		row += "\n";
		body += row;

		// Make the bottom part of the entries: number of fruit.
		row = "";
		for (int colNum = 0; colNum < num_cols; colNum++) {
			entry = std::to_string(num_fruit[rowNum][colNum]);
			entry.resize(MAX_CHARACTERS_PER_ENTRY, ' ');
			row += entry + " ";
		}
		row += "\n";
		body += row + "\n";
	}

	std::ofstream outstream;

	outstream.open(file_path, std::ofstream::out);
	outstream << header;
	outstream << body;
	outstream.close();
}

void OutputMap::set_not_settled(int row_num, int col_num)
{
	if ((row_num < 0) || (row_num > num_rows)) {
		std::cout << "OutputMap::setNotOccupied called with illegal row_num: " << row_num << std::endl;
		throw(row_num);
	}
	if ((col_num < 0) || (col_num > num_cols)) {
		std::cout << "OutputMap::setNotOccupied called with illegal col_num: " << col_num << std::endl;
		throw(col_num);
	}

	is_settled[row_num][col_num] = false;
}

void OutputMap::set_settled(int row_num, int col_num)
{
	if ((row_num < 0) || (row_num > num_rows)) {
		std::cout << "OutputMap::setOccupied called with illegal row_num: " << row_num << std::endl;
		throw(row_num);
	}
	if ((col_num < 0) || (col_num > num_cols)) {
		std::cout << "OutputMap::setOccupied called with illegal col_num: " << col_num << std::endl;
		throw(col_num);
	}

	is_settled[row_num][col_num] = true;
}

void OutputMap::set_num_fruit(int row_num, int col_num, int number_fruit)
{
	if ((row_num < 0) || (row_num > num_rows)) {
		std::cout << "OutputMap::setNumFruit called with illegal row_num: " << row_num << std::endl;
		throw(row_num);
	}
	if ((col_num < 0) || (col_num > num_cols)) {
		std::cout << "OutputMap::setNumFruit called with illegal col_num: " << col_num << std::endl;
		throw(col_num);
	}

	num_fruit[row_num][col_num] = number_fruit;
}

void OutputMap::set_num_people(int row_num, int col_num, int num_people)
{
	if ((row_num < 0) || (row_num > num_rows)) {
		std::cout << "OutputMap::setNumWanderers called with illegal row_num: " << row_num << std::endl;
		throw(row_num);
	}
	if ((col_num < 0) || (col_num > num_cols)) {
		std::cout << "OutputMap::setNumWanderers called with illegal col_num: " << col_num << std::endl;
		throw(col_num);
	}

	this->num_people[row_num][col_num] = num_people;
}
