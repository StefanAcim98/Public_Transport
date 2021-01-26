#include <fstream>
#include <sstream>
#include "CityLines.h"

CityLines::CityLines()
{
	ifstream input("linije.txt");
	if (!input)
	{
		throw exception("Error opening file. Shutting down...");
	}
	string line;
	while (getline(input, line)) {
		vector<int> allNumbers;
		string nameKey;
		int k = 0;
		int numberLine = 0;
		bool first = true;
		if (!line.empty()) {
			while (k < line.size()) {
				if (line[k] == ' ') {
					if (first) {
						nameKey = line.substr(0, k);
						first = false;
					}
					else {
						allNumbers.push_back(numberLine);
						numberLine = 0;
					}
				}
				else if (line[k] == '#') {
					cityLinesMap_.insert({ nameKey, allNumbers });
					break;
				}
				else {
					if (!first) {
						numberLine *= 10;
						numberLine += line[k] - '0';
					}
				}
				k++;
			}
		}
	}
	input.close();
}

ostream& operator<<(ostream& os, const CityLines& ctl)
{
	stringstream p;
	for (auto itr = ctl.cityLinesMap_.begin(); itr != ctl.cityLinesMap_.end(); itr++) {
		p << itr->first << ' ';
		for (auto number : itr->second) {
			p << to_string(number) << ' ';
		}
		p << endl;
	}
	os << p.str();
	return os;
}
