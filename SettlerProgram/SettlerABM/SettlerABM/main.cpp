#include "Gatherer.h"
#include "MapState.h"
#include "MapCell.h"
#include "OutputMap.h"	// only for testing //////////////////////////////////////////////////////////////////

#define	NUM_ROWS				10
#define NUM_COLS				25
#define NUM_PEOPLE				3
#define START_FRUIT_PER_CELL	200
#define NUM_DAYS				10
#define APPETITE_PER_PERSON		5

int main() {
	// Set up the map.
	MapState current_map = MapState(NUM_ROWS, NUM_COLS);

	// Populate the map with gatherers.
	std::vector<Gatherer*> gatherers(NUM_PEOPLE);
	std::default_random_engine rand_engine;
	std::uniform_int_distribution<int> rand_row(0, NUM_ROWS - 1);
	std::uniform_int_distribution<int> rand_col(0, NUM_COLS - 1);
	int thisRow, thisCol;
	MapCell* thisCell;
	for (int i = 0; i < NUM_PEOPLE; i++) {
		// Set random coordinates for each gatherer.
		thisRow = rand_row(rand_engine);
		thisCol = rand_col(rand_engine);
		thisCell = current_map.cells[thisRow][thisCol];
		gatherers[i] = new Gatherer(&current_map, thisCell, APPETITE_PER_PERSON);
	}

	// Show the initial state of the map.
	current_map.create_output_map();

	// Progress through the simulated days.
	int time;
	for (time = 1; time <= NUM_DAYS; time++) {
		for (int i = 0; i < NUM_PEOPLE; i++) {
			gatherers[i]->free_will();
		}
		current_map.advance_time();
	}

	//// Test code.
	//std::string outfile = "../../../OutputMaps/testoutput.txt";
	//OutputMap testOutputMap = OutputMap(3, 2, 0);
	//testOutputMap.set_num_fruit(1, 1, 13);
	//testOutputMap.create_text_map(outfile);
	//std::string dummy;
	//std::cin >> dummy;
	//// End of test code.
	return 0;
}