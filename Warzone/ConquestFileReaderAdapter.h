#pragma once
#include "MapLoader.h"
#include "ConquestFileReader.h"

class ConquestFileReaderAdapter :
    public MapLoader
{
private:
    ConquestFileReader conquestFileReader;
public:
    ConquestFileReaderAdapter();
    ConquestFileReaderAdapter(ConquestFileReader cfr);
    void storeContinents();
    void storeTerritories();
    void storeTerritoriesWithBorders();
};

