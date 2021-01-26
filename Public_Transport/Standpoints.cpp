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
		cout << "Error opening file. Shutting down..." << endl;
	}
	string line;
	while (getline(input, line)) {
		int k = 0;
		if (!line.empty()) {
			while (line[k++] != ' ');
			umap_.insert({ stoi(line.substr(0, k - 1)), line.substr(k, line.size() - 1) });
		}
	}
	input.close();
}

ostream& operator<<(ostream& os, const Standpoints& sps)
{
	stringstream p;
	for (auto itr = sps.umap_.begin(); itr != sps.umap_.end(); itr++) {
		p << itr->first << ' ' << itr->second << endl;
	}
	os << p.str();
	return os;
}
