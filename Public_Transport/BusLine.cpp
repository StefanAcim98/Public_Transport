#include <sstream>
#include <fstream>
#include "BusLine.h"
#include "CityLines.h"
#include "Standpoints.h"

BusLine::BusLine(const string& s, Standpoints* sps, CityLines* ctl)
{
	auto it = ctl->getCityLinesMap().find(s);
	this->busLineName_ = s;
	this->busStopsOfBusLine_ = it->second;
	for (auto& stop : busStopsOfBusLine_) {
		auto itr = sps->getStandpointsMap().find(stop.first);
		this->namesOfBusStopsOfBusLine_.insert({itr->first, itr->second});
		itr = sps->getStandpointsMap().find(stop.second);
		this->namesOfBusStopsOfBusLine_.insert({ itr->first, itr->second });
	}
}

void BusLine::writeToFile() const
{
	fstream file("linija_" + this->busLineName_ + ".txt", ios::out);
	file << *this;
	file.close();
}

ostream& operator<<(ostream& os, const BusLine& bl)
{
	stringstream p;
	stringstream k;
	auto it1 = bl.namesOfBusStopsOfBusLine_.find(bl.busStopsOfBusLine_[0].first);
	auto it2 = bl.namesOfBusStopsOfBusLine_.find(bl.busStopsOfBusLine_[bl.busStopsOfBusLine_.size()-1].first);
	p << bl.busLineName_ << ' ' << it1->second << "->" << it2->second << endl;
	for (int i = 0; i < bl.busStopsOfBusLine_.size(); i++) {
		auto it = bl.namesOfBusStopsOfBusLine_.find(bl.busStopsOfBusLine_[i].first);
		p << it->first << ' ' << it->second << endl;
		it = bl.namesOfBusStopsOfBusLine_.find(bl.busStopsOfBusLine_[i].second);
		k << it->first << ' ' << it->second << endl;
	}
	p << k.str();
	os << p.str();
	return os;
}
