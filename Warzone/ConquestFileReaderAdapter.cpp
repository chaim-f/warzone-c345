#include "ConquestFileReaderAdapter.h"

ConquestFileReaderAdapter::ConquestFileReaderAdapter()
{
}

ConquestFileReaderAdapter::ConquestFileReaderAdapter(ConquestFileReader cfr)
{
	conquestFileReader = cfr;
}

void ConquestFileReaderAdapter::storeContinents()
{
	this->conquestFileReader.storeContinents();
}

void ConquestFileReaderAdapter::storeTerritories()
{
	this->conquestFileReader.storeTerritories();
}

void ConquestFileReaderAdapter::storeTerritoriesWithBorders()
{
	this->conquestFileReader.storeTerritoriesWithBorders();
}
