#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>

using namespace std;

class CityLines;
class Standpoints;

class BusStop {
public:

	BusStop(int k, Standpoints* sps, CityLines* ctl);

	int getBusStopNumber() const { return busStopNumber_; }
	string getBusStopName() const { return busStopName_; }
	set<string>& getBusesInBusStop() { return busesInBusStop_; }

	friend ostream& operator<<(ostream& os, const BusStop& bs);

private:
	int busStopNumber_;
	string busStopName_;
	set<string> busesInBusStop_;
};