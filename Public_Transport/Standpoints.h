#pragma once

#include <iostream>
#include <unordered_map>

using namespace std;

class Standpoints {
public:

	Standpoints();

	unordered_map<int, string>& getStandpointsMap() { return standpointsMap_; }

	friend ostream& operator<<(ostream& os, const Standpoints& sps);

protected:
	unordered_map<int, string> standpointsMap_;
};
