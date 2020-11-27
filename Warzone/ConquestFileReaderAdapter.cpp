#include "ConquestFileReaderAdapter.h"

ConquestFileReaderAdapter::ConquestFileReaderAdapter()
{
}

ConquestFileReaderAdapter::ConquestFileReaderAdapter(ConquestFileReader* cfr)
{
	conquestFileReader = cfr;
}

void ConquestFileReaderAdapter::storeContinents()
{
	this->conquestFileReader->storeContinents();
}

void ConquestFileReaderAdapter::storeTerritories()
{
	this->conquestFileReader->storeTerritories();
}

void ConquestFileReaderAdapter::storeTerritoriesWithBorders()
{
	this->conquestFileReader->storeTerritoriesWithBorders();
}

void ConquestFileReaderAdapter::storeAllContents()
{
	this->conquestFileReader->storeAllContents();
}

vector<Continent*> ConquestFileReaderAdapter::getContinents()
{
	return this->conquestFileReader->getContinents();
}

vector<Territory*> ConquestFileReaderAdapter::getTerritories()
{
	return this->conquestFileReader->getTerritories();
}

vector<Territory*> ConquestFileReaderAdapter::getTerritoriesWithBorders()
{
	return this->conquestFileReader->getTerritoriesWithBorders();
}

string ConquestFileReaderAdapter::getFileName()
{
	return this->conquestFileReader->getFileName();
}
