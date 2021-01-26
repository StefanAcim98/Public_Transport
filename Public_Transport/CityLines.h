#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class CityLines {
public:

	CityLines();

	unordered_map<string, vector<int>> getCityLinesMap() const { return cityLinesMap_; }

	friend ostream& operator<<(ostream& os, const CityLines& ctl);

private:
	unordered_map<string, vector<int>> cityLinesMap_;
};