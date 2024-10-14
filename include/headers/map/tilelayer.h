#pragma once

#ifndef TILELAYER_H
#define TILELAYER_H

#include "layer.h"
#include <iostream>
#include <vector>
using std::string;
using std::vector;

struct Tileset {
    int firstid; int lastid;
    string name;
    int tilesize;
    int tilecount;
    int columns;
    int rows;
    int width;
    int height;
    string source;
};

using TileMap = vector<vector<int> >; //!!!DONT EDIT THIS LINE!!! //for some reason that space is needed and it wont work without the space.
using TileArray = vector<Tileset>;

class TileLayer : public Layer {
public:
    TileLayer(int tilesize, int rows, int columns, TileMap tilemap, TileArray tilesets);

    virtual void Draw();
    virtual void Update();
    inline TileMap GetTilemap() { return m_tilemap; }
    inline TileArray GetTilesets() { return m_tilesets; }

private:
    int m_tilesize;
    int m_rows; int m_columns;

    TileMap m_tilemap;
    TileArray m_tilesets;

protected:
};

#endif // TILELAYER_H