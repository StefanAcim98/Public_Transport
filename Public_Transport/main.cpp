#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "Standpoints.h"
#include "CityLines.h"

using namespace std;

int main() {
	Standpoints* sps = new Standpoints();
	cout << *sps << endl;
	CityLines* ctl = new CityLines();
	cout << *ctl << endl;
}