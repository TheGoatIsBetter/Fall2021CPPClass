#include <iostream>
#include <stdlib.h>

using namespace std;


//recursive function that searches a 1D array with a binary search
int binSearch(int toSearch[], int low, int high, int target) {
	//make sure it works for 0
	if (target == toSearch[0]) {
		return target;
	}


	//make sure high and low are right before running it to prevent crash
	if (high >= low) {
		//get middle/prediction
		int middle = ((high - low) / 2) + low;

		

		//if the middle is already it then return it
		if (toSearch[middle] == target) {
			return middle;
		}
		
		//show coordinates of the check
		int x, y;
		x = (middle % 8) + 1;
		y = (middle / 8) + 1;
		std::cout << "Checking 8x8 grid at: (" << x << ", " << y << ")" << std::endl;

		if (toSearch[middle] < target) { //if the middle is bigger than the target, then
			//std::cout << middle << " Higher\n";
			return binSearch(toSearch, middle - 1, high, target); //recursively cut down and check the second half of the initial array
		}
		//std::cout << middle << " Lower\n";
		
		//else it must be in the first half of the initial array, search there
		return binSearch(toSearch, low, middle + 1, target);
	}
}

int main() {
	//create an array of size 64 and allocate memory for each integer in the array
	int * gridarray = (int*)calloc(64, sizeof(int));

	//sorts the grid to be numbered 0-63
	for (int i = 0; i < 64; ++i) {
		gridarray[i] = i;
	}

	//loops through gridarray in 8s, printing out the numbers, adding double spaces, and appending a 0 to the 1 digit numbers for a nice formatted representation of the grid
	for (int j = 0; j < 64; j += 8) {
		for (int i = 0; i < 8; ++i) {
			int element = gridarray[i + j];
			char prefix = '\0';

			if (element < 10) {
				prefix = '0';
			}

			std::cout << prefix << element << "  ";
		}
		std::cout << std::endl;
	}

	//setup randomness with seed of time NULL
	srand(time(NULL));

	//sets a random part of the grid as the enemy rather than the other way around to keep the integrity of the sort for the binary search
	int enemy = gridarray[rand() % 64];

	std::cout << "\nTARGET: " << enemy << std::endl;

	//call to the search function giving the array as well as the lowest and highest indexes, as well as what to look for
	int enemyLocation = binSearch(gridarray, 0, 63, enemy);

	//std::cout << enemyLocation;

	//prints the array
	//for (int i = 0; i < 64; ++i) {
	//	std::cout << "\n" << gridarray[i] << "\n";
	//}

	//calculate the position on the grid the enemy is actually at.  Add 1 to make it for how humans read grids.
	int x, y;
	x = (enemyLocation % 8) + 1;
	y = (enemyLocation / 8) + 1;

	std::cout << "Found at: (" << x << ", " << y << ")" << std::endl;
	
	return 0;
}