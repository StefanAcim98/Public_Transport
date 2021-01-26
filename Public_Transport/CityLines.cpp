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
		vector<int> stageA;
		vector<int> stageB;
		vector<pair<int, int>> pairs;
		string nameKey;
		int k = 0;
		int numberLine = 0;
		bool first = true;
		if (!line.empty()) {
			while (line[k] != '#') {
				if (line[k] == ' ') {
					if (first) {
						nameKey = line.substr(0, k);
						first = false;
					}
					else {
						stageA.push_back(numberLine);
						numberLine = 0;
					}
				}
				else {
					if (!first) {
						numberLine *= 10;
						numberLine += line[k] - '0';
					}
				}
				k++;
			}
			stageA.push_back(numberLine);
			numberLine = 0;
			k++;
			while (k < line.size()) {
				if (line[k] == ' ') {
					stageB.push_back(numberLine);
					numberLine = 0;
				}
				else {
						numberLine *= 10;
						numberLine += line[k] - '0';
				}
				k++;
			}
			stageB.push_back(numberLine);
			for (int i = 0; i < stageA.size(); i++) {
				pairs.push_back(std::make_pair(stageA[i], stageB[i]));
			}
			cityLinesMap_.insert({ nameKey, pairs });
		}
	}
	input.close();
}

ostream& operator<<(ostream& os, const CityLines& ctl)
{
	stringstream p;
	for (auto itr = ctl.cityLinesMap_.begin(); itr != ctl.cityLinesMap_.end(); itr++) {
		p << itr->first << endl;
		p << "direction A: ";
		for (auto &number : itr->second) {
			p << to_string(number.first) << ' ';
		}
		p << endl;
		p << "direction B: ";
		for (auto &number : itr->second) {
			p << to_string(number.second) << ' ';
		}
		p << endl;
	}
	os << p.str();
	return os;
}
