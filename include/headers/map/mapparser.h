#pragma once

#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>
#include <iostream>
#include "gamemap.h"
#include "tilelayer.h"
#include "tinyxml.h"
using std::string;
using std::map;

class MapParser {
public:
    bool Load(string mapname, string source);
    bool Clean();

    inline GameMap* GetMap(string id){ return m_mapdict[id]; }
    inline static MapParser* GetInstance(){ return s_instance = (s_instance != nullptr) ? s_instance : new MapParser(); }
private:
    MapParser(){};
    static MapParser* s_instance; 
    map<string, GameMap*> m_mapdict;

    bool ParseMapFromFile(string mapname, string source);
    Tileset ParseTileset(TiXmlElement* xmlTileset);
    TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, TileArray tilesets, int tilesize, int rows, int columns);

protected:
};

#endif // MAPPARSER_H