#pragma once

#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "layer.h"
using std::vector;

class GameMap {
public:

    //Draw all map layers
    void Draw(){
        for (unsigned int i=0; i<m_mapLayers.size(); i++){
            m_mapLayers[i]->Draw();
        }
    }    

    //Update all map layers
    void Update(){
        for (unsigned int i=0; i<m_mapLayers.size(); i++){
            m_mapLayers[i]->Update();
        }
    }    

    vector<Layer*> GetMapLayers() { return m_mapLayers; }
private:
    friend class MapParser;
    std::vector<Layer*> m_mapLayers;
protected:
};

#endif // GAMEMAP_H