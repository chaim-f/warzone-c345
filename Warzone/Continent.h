#include <string>
#include <ostream>
using namespace std;

class Continent
{
	string continentName;
	int continentBunos = 0;
	int source;
	int destination;
public:
	Continent() {
		source = -1; // if not set
		destination = -1;
	};
	Continent(int src, int dest, string name, int bunos);
	int getSource();
	friend class Map;
	friend int getSource(Continent c);
	friend int getDestination(Continent d);
	friend ostream& operator<<(ostream& strm, const Continent c);
};