#include "Gatherer.h"
#include "MapState.h"
#include "MapCell.h"
#include "OutputMap.h"	// only for testing //////////////////////////////////////////////////////////////////

#define	NUM_ROWS				200
#define NUM_COLS				250
#define NUM_PEOPLE				10
#define START_FRUIT_PER_CELL	200
#define NUM_DAYS				10

int main() {
	// Set up the map.

	// Populate the map with gatherers.

	// Progress through the simulated days.

	// Test code.
	std::string outfile = "../../../OutputMaps/testoutput.txt";
	OutputMap testOutputMap = OutputMap(3, 2, 0);
	testOutputMap.set_num_fruit(1, 1, 13);
	testOutputMap.create_text_map(outfile);
	std::string dummy;
	std::cin >> dummy;
	// End of test code.
	return 0;
}