#include "objectlayer.h"

void ObjectLayer::LoadDoors(MAP)
{
    tson::Layer *layer = map->getLayer("doors");
    if(layer->getType() == tson::LayerType::ObjectGroup)
    {
        std::cout << "Loading doors..." << std::endl;

        //If you want to just go through every existing object in the layer:
        for(auto &obj : layer->getObjects())
        {
            tson::Vector2i position = obj.getPosition();
            tson::Vector2i size = obj.getSize();
            tson::ObjectType objType = obj.getObjectType();

            // std::cout << "[" << obj.getId() << "] ";
            // std::cout << "X: " << position.x << " ";
            // std::cout << "Y: " << position.y << std::endl;

            int gotoX = obj.get<int>("gotoX");
            int gotoY = obj.get<int>("gotoY");
            std::string room = obj.get<std::string>("room");
            bool locked = obj.get<bool>("locked");

            // std::cout << "gotoX: " << gotoX << std::endl;
            // std::cout << "gotoY: " << gotoY << std::endl;
            // std::cout << "room: " << room << std::endl;
            // std::cout << "locked: " << locked << std::endl;
        }
    }
}

void ObjectLayer::LoadWalls(MAP)
{
    tson::Layer *layer = map->getLayer("walls");
    if(layer->getType() == tson::LayerType::ObjectGroup)
    {
        std::cout << "Loading walls..." << std::endl;

        //If you want to just go through every existing object in the layer:
        for(auto &obj : layer->getObjects())
        {
            tson::Vector2i position = obj.getPosition();
            tson::Vector2i size = obj.getSize();
            tson::ObjectType objType = obj.getObjectType();

            // std::cout << "[" << obj.getId() << "] ";
            // std::cout << "X: " << position.x << " ";
            // std::cout << "Y: " << position.y << std::endl;
        }
    }
}