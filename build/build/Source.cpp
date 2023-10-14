#include <iostream>
#include <ctime>
#include <map>


int main() {
	std::map<int, std::pair<int, bool>>input;
	std::map<int, int>output;
	int n = 0, amount, counter = 1;
	srand(time(0));

	n = 3;
	amount = 25;

	for (int i = 0; i < amount; i++) {
		int y = rand() % 2;
		input.emplace(i+1, std::pair<int, bool>(y, false));
	}
	std::cout << "Input data:\n";
	for (auto item : input) {
		std::cout << "(" << item.first << ", " << item.second.first << "), "<<std::endl;
	}

	for (int i = 1; i < amount-1; i++) {

		auto &el1 = input.find(i)->second;
		auto &el2 = input.find(i+1)->second;
		auto &el3 = input.find(i+2)->second;

		if (el1.first == el2.first && el2.first == el3.first) {
			counter++;
			if (counter != n)
			el2.second = true;
		}
		else counter = 1;
	}
	for (auto item : input) {
		if (item.second.second == false)
			output.emplace(item.first, item.second.first);
	}
	std::cout << "Output data:\n";
	for (auto item : output) {
		std::cout << "(" << item.first << ", " << item.second << "), " << std::endl;
	}
	return 0;
}