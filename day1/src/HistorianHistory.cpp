#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void firstPuzzle(std::vector<int>, std::vector<int>);
void secondPuzzle(std::vector<int>, std::vector<int>);

int main() {
	std::ifstream file("D:\\AoC2024\\day1\\resources\\realinput.txt");
	if (!file) {
		std::cerr << "Error opening the file!" << std::endl;
		return 1;
	}	

	std::vector<int> column1;
	std::vector<int> column2;


	int value1, value2;

	while (file >> value1 >> value2) {
		column1.push_back(value1);
		column2.push_back(value2);
	}
	file.close();

	std::sort(column1.begin(), column1.end());
	std::sort(column2.begin(), column2.end());

	firstPuzzle(column1, column2);

	secondPuzzle(column1, column2);

	return 0;
}


void firstPuzzle(std::vector<int> column1, std::vector<int> column2) {
	int acc=0;
	// Assuming the list are equal
	for(int i=0; i < column1.size(); i++) {
		int diff = column1[i] - column2[i];
		int dist = std::abs(diff);
		acc += dist;
	}	

	std::cout << "Distance: " << acc << std::endl;

}

void secondPuzzle(std::vector<int> column1, std::vector<int> column2) {
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