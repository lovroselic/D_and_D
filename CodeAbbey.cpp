/*
	selection of helper functions
	v0.1
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "CodeAbbey.h"

std::vector<std::string> loadData(std::string name) {
	try {
		std::ifstream file;
		std::string line;
		std::vector<std::string> data;
		file.open(name);
		if (!file) {
			throw std::runtime_error("Could not open file: " + name);
		}
		while (std::getline(file, line)) {
			data.push_back(line);
		}

		file.close();
		return data;
	}

	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

std::vector<std::string> splitString(std::string str, const std::string separator) {
	std::vector<std::string> result;
	while (str.size()) {
		int index = str.find(separator);
		if (index != std::string::npos) {
			result.push_back(str.substr(0, index));
			str = str.substr(index + separator.size());
		}
		else {
			result.push_back(str);
			str = "";
		}
	}
	return result;
}

std::string joinVector(const std::vector<std::string>& data, const std::string separator) {
	std::string result = "";
	if (data.size() == 0) return result;
	result += data.at(0);
	if (data.size() > 1) {
		for (std::vector<int>::size_type i = 1; i != data.size(); i++) {
			result += separator;
			result += data.at(i);
		}
	}
	return result;
}

std::string joinVector(const std::vector<int>& data, const std::string separator) {
	std::string result = "";
	if (data.size() == 0) return result;
	result += std::to_string(data.at(0));
	if (data.size() > 1) {
		for (std::vector<int>::size_type i = 1; i != data.size(); i++) {
			result += separator;
			result += std::to_string(data.at(i));
		}
	}
	return result;
}
std::string joinVector(const std::vector<long long int>& data, const std::string separator) {
	std::string result = "";
	if (data.size() == 0) return result;
	result += std::to_string(data.at(0));
	if (data.size() > 1) {
		for (std::vector<int>::size_type i = 1; i != data.size(); i++) {
			result += separator;
			result += std::to_string(data.at(i));
		}
	}
	return result;
}