#include "Continent.h"
using namespace std;

class Territory {
public:
	int source;
	int destination;
	Continent continent;
	Territory() {
		source = 0;
		destination = 0;
	}
	Territory(int src, int dest);
	Territory(int src, int dest, Continent c);
	friend class Map;
	friend ostream& operator<<(ostream& strm, const Territory t);
};

