#pragma once

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
#include <set>

using namespace std;

class CityLines;
class Standpoints;

class BusLine {
public:
	
	BusLine(const string& s, Standpoints* sps, CityLines* ctl);

	friend ostream& operator<<(ostream& os, const BusLine& bl);

	void writeToFile() const;

	string getBusLineName() const { return busLineName_; }
	vector<pair<int, int>>& getBusStopsOfBusLine() { return busStopsOfBusLine_; }
	unordered_map<int, string>& getNamesOfBusStopsOfBusLine() { return namesOfBusStopsOfBusLine_; }

private:
	string busLineName_;
	vector<pair<int, int>> busStopsOfBusLine_;
	unordered_map<int, string> namesOfBusStopsOfBusLine_;
};