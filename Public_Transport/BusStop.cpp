#include <sstream>
#include "BusStop.h"
#include "CityLines.h"
#include "Standpoints.h"

BusStop::BusStop(int k, Standpoints* sps, CityLines* ctl)
{	
	if (sps->getStandpointsMap().find(k) != sps->getStandpointsMap().end()) {
		busStopNumber_ = k;
		auto it = sps->getStandpointsMap().find(k);
		busStopName_ = it->second;
	}
	else
		throw exception("Bus station not found. ");
	for (auto it = ctl->getCityLinesMap().begin(); it != ctl->getCityLinesMap().end(); it++) {
		for (auto &bus : it->second) {
			if (k == bus.first || k == bus.second) {
				busesInBusStop_.insert(it->first);
				break;
			}
		}
	}
}

ostream& operator<<(ostream& os, const BusStop& bs)
{
	stringstream p;
	p << bs.busStopNumber_ << ' ' << bs.busStopName_ << " [";
	for (auto bus : bs.busesInBusStop_) {
		p << bus << ' ';
	}
	p.seekp(-1, std::ios_base::end);
	p << ']';
	os << p.str();
	return os;
}
