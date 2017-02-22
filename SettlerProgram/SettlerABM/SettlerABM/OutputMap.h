#ifndef OUTPUT_MAP_H
#define OUTPUT_MAP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#define MAX_CHARACTERS_PER_ENTRY	4

class OutputMap
{
private:
	int num_rows;

	int num_cols;

	int time;

	std::vector<std::vector<bool>> is_settled;
	
	std::vector<std::vector<int>> num_people;
	
	std::vector<std::vector<int>> num_fruit;


public:
	OutputMap(int num_rows, int num_cols, int time);

	void create_text_map(std::string file_path);

	void set_not_settled(int row_num, int col_num);

	void set_settled(int row_num, int col_num);

	void set_num_fruit(int row_num, int col_num, int number_fruit);

	void set_num_people(int row_num, int col_num, int num_people);

};
#endif
