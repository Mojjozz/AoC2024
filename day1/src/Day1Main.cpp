#include "HistorianHistory.h"

int main() {
	namespace fs = std::filesystem;
	fs::path projectRoot = fs::current_path().parent_path().parent_path();
	fs::current_path(projectRoot);
	std::ifstream file("day1/resources/Example.txt");
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