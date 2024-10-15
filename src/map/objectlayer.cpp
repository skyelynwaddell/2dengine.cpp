#include "objectlayer.h"

void ObjectLayer::LoadDoors(std::unique_ptr<tson::Map>& map)
{
    tson::Layer *doorLayer = map->getLayer("doors");
 
    if(doorLayer->getType() == tson::LayerType::ObjectGroup)
    {
        //If you want to just go through every existing object in the layer:
        for(auto &obj : doorLayer->getObjects())
        {
            tson::Vector2i position = obj.getPosition();
            tson::Vector2i size = obj.getSize();
            tson::ObjectType objType = obj.getObjectType();

            std::cout << "X: " << position.x << std::endl;
            std::cout << "Y: " << position.y << std::endl;

            int gotoX = obj.get<int>("gotoX");
            int gotoY = obj.get<int>("gotoY");
            std::string room = obj.get<std::string>("room");
            bool locked = obj.get<bool>("locked");

            std::cout << "gotoX: " << gotoX << std::endl;
            std::cout << "gotoY: " << gotoY << std::endl;
            std::cout << "room: " << room << std::endl;
            std::cout << "locked: " << locked << std::endl;
        }
    }
}