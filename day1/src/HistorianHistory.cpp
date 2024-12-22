#include "HistorianHistory.h"

void firstPuzzle(std::vector<int>& column1, std::vector<int>& column2) {
	int acc=0;
	// Assuming the list are equal
	for(int i=0; i < column1.size(); i++) {
		int diff = column1[i] - column2[i];
		int dist = std::abs(diff);
		acc += dist;
	}	

	std::cout << "Distance: " << acc << std::endl;

}

void secondPuzzle(std::vector<int>& column1, std::vector<int>& column2) {
	int score=0;
	for(int i=0; i < column1.size(); i++) {
		int count=0;
		for(int j=0; j < column2.size(); j++) {
			if (column1[i] == column2[j]) {
				count++;
			}
		}
		score += column1[i] * count;
	}
	std::cout << "score: " << score << std::endl;
}
