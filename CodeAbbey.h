#pragma once
#ifndef CODEABBEY
#define CODEABBEY

std::vector<std::string> loadData(std::string name);
std::vector<std::string> splitString(std::string str, const std::string separator);
std::string joinVector(const std::vector<std::string>& data, const std::string separator);
std::string joinVector(const std::vector<int>& data, const std::string separator);
std::string joinVector(const std::vector<long long int>& data, const std::string separator);

#endif // !CODEABBEY
