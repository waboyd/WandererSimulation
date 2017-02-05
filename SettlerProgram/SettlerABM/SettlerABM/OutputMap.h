#ifndef OUTPUT_MAP_H
#define OUTPUT_MAP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class OutputMap
{
private:
	int num_rows;

	int num_cols;

	int time;

	std::vector<bool> is_occupied;
	
	std::vector<int> num_people;
	
	int num_fruit[];


public:
	void create_text_map(std::string file_path);

	void setNotOccupied(int row_num, int col_num);

	void setOccupied(int row_num, int col_num);

	void setNumFruit(int row_num, int col_num, int number_fruit);

	void setNumWanderers(int row_num, int col_num, int num_wanderers);

};
#endif
