#pragma once

#ifndef OBJECTLAYER_H
#define OBJECTLAYER_H

#include <iostream>
#include <tileson.hpp>

#define MAP std::unique_ptr<tson::Map>& map

class ObjectLayer {
public:
    inline static ObjectLayer* GetInstance(){ return s_instance = (s_instance != nullptr) ? s_instance : new ObjectLayer(); }

    void LoadDoors(MAP);
    void LoadWalls(MAP);
private:
    ObjectLayer(){};
    static ObjectLayer* s_instance;
protected:
};

#endif // OBJECTLAYER_H