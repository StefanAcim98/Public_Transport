#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class CityLines {
public:

	CityLines();

	unordered_map<string, vector<pair<int,int>>>& getCityLinesMap() { return cityLinesMap_; }

	friend ostream& operator<<(ostream& os, const CityLines& ctl);

private:
	unordered_map<string, vector<pair<int,int>>> cityLinesMap_;
};