// https://www.codeabbey.com/index/task_view/dungeons-and-dragons-dice
// https://towardsdatascience.com/modelling-the-probability-distributions-of-dice-b6ecf87b24ea
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>
#include <cmath>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION 0.01

using namespace std;

string display_stat(vector<int>& data, string label);
int diceThrow(int sides);
vector<int> simulate_dice(int n_dice, int n_sides, int n_throws);

int main() {
	cout << "Dungeons And Dragons dice v" << VERSION << "!\n\n";
	srand((unsigned int)time(0));
	string path = "Test.txt";
	vector<string> raw_data = loadData(path);
	//unpack
	const size_t ROW = raw_data.size();
	const size_t COL = 100;
	vector<vector<int>> data(ROW, vector<int>(COL, 0));
	for (int i = 0; i < ROW; i++) {
		string line = raw_data[i];
		vector<string> split = splitString(line, " ");
		for (int c = 0; c < COL; c++) {
			data[i][c] = stoi(split[c]);
		}
	}

	//unpack end

	//printVector(raw_data);
	//print2DVector(data);
	string sol;
	vector<string> solution;
	for (int i = 0; i < ROW; i++) {
		sol = display_stat(data[i], to_string(i));
		solution.push_back(sol);
	}
	cout << endl;
	string finalSolution = joinVector(solution, " ");
	cout << "Solution: " << finalSolution << endl;
}

int faces(double stddev, double avg) {
	return round(((6 * stddev * stddev / avg) + 1) / 2) * 2;
}
int dice(double avg, int f) {
	return round((2 * avg) / (f + 1));
}

string display_stat(vector<int>& data, string label) {
	double avg = average(data);
	double avgc = round(2 * avg) / 2.0;
	double std = st_dev(data);
	double stdc = st_dev(data, avgc);
	int Max = *max_element(data.begin(), data.end());
	int Min = *min_element(data.begin(), data.end());
	int f = faces(stdc, avgc);
	int d = dice(avgc, f);
	cout << label << ":" << " avg: " << avg << " std: " << std;
	cout << " corrSTD " << stdc;
	cout << " min: " << Min << " max:" << Max;
	cout << " corrAvg " << avgc;
	cout << " faces " << f;
	cout << " dice " << d;
	string sol = to_string(d) + "d" + to_string(f);
	cout << " solution: " << sol;
	cout << endl;
	return sol;

}
int diceThrow(int sides) {
	int x = rand() % sides + 1;
	return x;
}
vector<int> simulate_dice(int n_dice, int n_sides, int n_throws) {
	vector<int> result;
	for (int t = 0; t < n_throws; t++) {
		int x = 0;
		for (int d = 0; d < n_dice; d++) {
			x += diceThrow(n_sides);
		}
		result.push_back(x);
	}
	return result;
}

