#include <fstream>
#include <string>
#include <sstream>
#include "Standpoints.h"

/*ostream& operator<<(ostream& os, const Standpoint& sp)
{
    os << sp.number_ << ' ' << sp.name_;
    return os;
}*/

Standpoints::Standpoints()
{
	ifstream input("stajalista.txt");
	if (!input)
	{
		throw exception("Error opening file. Shutting down...");
	}
	string line;
	while (getline(input, line)) {
		int k = 0;
		if (!line.empty()) {
			while (line[k++] != ' ');
			standpointsMap_.insert({ stoi(line.substr(0, k - 1)), line.substr(k, line.size() - 1) });
		}
	}
	input.close();
}

ostream& operator<<(ostream& os, const Standpoints& sps)
{
	stringstream p;
	for (auto itr = sps.standpointsMap_.begin(); itr != sps.standpointsMap_.end(); itr++) {
		p << itr->first << ' ' << itr->second << endl;
	}
	os << p.str();
	return os;
}
