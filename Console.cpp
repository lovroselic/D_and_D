/*
	v 0.1
*/
#include <iostream>
#include <vector>
#include <string>
#include "Console.h"

void printArray(int* data, int length) {
	int* p = data;
	for (int x = 0; x < length; x++) {
		std::cout << p << " --> cell[" << x << "]\t= " << *p << std::endl;
		p++;
	}
	std::cout << std::endl;
}

void printVector(std::vector<int>& vct) {
	for (int v : vct) {
		std::cout << v << std::endl;
	}
}

void printVector(std::vector<std::string>& vct) {
	for (std::string v : vct) {
		std::cout << v << std::endl;
	}
}

void print2DVector(std::vector<std::vector<int>>& vct) {
	for (const auto& row : vct) {
		for (const auto& col : row) {
			std::cout << col << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}