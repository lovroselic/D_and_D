// https://www.codeabbey.com/index/task_view/dungeons-and-dragons-dice
//

#include <iostream>
#include <vector>
#include <string>
#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h";
#define VERSION 0.01

using namespace std;

int main() {
	cout << "Dungeons And Dragonc dice v" << VERSION << "!\n\n";
	string path = "Data.txt";
	vector<string> raw_data = loadData(path);

	printVector(raw_data);
}

