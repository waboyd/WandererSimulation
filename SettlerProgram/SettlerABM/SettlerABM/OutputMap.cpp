#include <string>
#include <vector>
#include <list>
#include <iostream>
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
		is_occupied.push_back(newIsOccupiedRow);
		std::vector<int> newNumFruitRow(num_cols);
		newNumFruitRow.assign(num_cols, 0);
		num_fruit.push_back(newNumFruitRow);
	}
}

void OutputMap::create_text_map(std::string file_path)
{
}

void OutputMap::set_not_occupied(int row_num, int col_num)
{
	if ((row_num < 0) || (row_num > num_rows)) {
		std::cout << "OutputMap::setNotOccupied called with illegal row_num: " << row_num << std::endl;
		throw(row_num);
	}
	if ((col_num < 0) || (col_num > num_cols)) {
		std::cout << "OutputMap::setNotOccupied called with illegal col_num: " << col_num << std::endl;
		throw(col_num);
	}

	is_occupied[row_num][col_num] = false;
}

void OutputMap::set_occupied(int row_num, int col_num)
{
	if ((row_num < 0) || (row_num > num_rows)) {
		std::cout << "OutputMap::setOccupied called with illegal row_num: " << row_num << std::endl;
		throw(row_num);
	}
	if ((col_num < 0) || (col_num > num_cols)) {
		std::cout << "OutputMap::setOccupied called with illegal col_num: " << col_num << std::endl;
		throw(col_num);
	}

	is_occupied[row_num][col_num] = true;
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
