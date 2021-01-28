#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include "Standpoints.h"
#include "CityLines.h"
#include "BusStop.h"
#include "BusLine.h"

using namespace std;

int main() {
	Standpoints* sps = new Standpoints();
	cout << *sps << endl;
	CityLines* ctl = new CityLines();
	cout << *ctl << endl;
	BusStop* bs = new BusStop(1024, sps, ctl);
	cout << *bs << endl;
	cout << endl;
	bs->writeToFile();
	BusLine* bl = new BusLine("MINI1", sps, ctl);
	cout << *bl << endl;
	bl->writeToFile();
}