#include "ConquestFileReader.h"

ConquestFileReader::ConquestFileReader()
{
}

ConquestFileReader::ConquestFileReader(string fileName)
{
	fileName = fileName;
}

void ConquestFileReader::setFileName(string name)
{
	this->fileName = name;
}

void ConquestFileReader::storeContinents()
{
}

void ConquestFileReader::storeTerritories()
{
}

void ConquestFileReader::storeTerritoriesWithBorders()
{
}

string ConquestFileReader::getFileName()
{
	return this->fileName;
}

vector<Continent*> ConquestFileReader::getContinents()
{
	return this->continentVec;
}

vector<Territory*> ConquestFileReader::getTerritories()
{
	return this->territoryVec;
}

vector<Territory*> ConquestFileReader::getTerritoriesWithBorders()
{
	return this->territoryBordersVec;
}
