#include "objectconstructor.h"



ObjectConstructor::ObjectConstructor(std::vector<Object*> *obj)
{
    objects = obj;
}

void ObjectConstructor::drawWall(sf::Vector2f begin, int countOfSegments, sf::Vector2f dir)
{
    sf::Vector2f offset;
    Object* obj;
    short row = 0;
    bool col = 0;
    if(begin.x < dir.x)
    {
        if(begin.y < dir.y) // Up-Right
        {
            row = 1;
            offset.x = 80;
            offset.y = -40;
        }
        else // Down-Right
        {
            row = 0;
            offset.x = 80;
            offset.y = 39;
        }
    }
    else
    {
        if(begin.y < dir.y) // Up-Left
        {
            row = 0;
            offset.x = -80;
            offset.y = -39;
        }
        else // Down-Left
        {
            row = 1;
            offset.x = -80;
            offset.y = 40;
        }
    }

    sf::Vector2f pos = begin;
    obj = new Object;
    obj->setTexture(Textures::Wall);
    obj->setTextureRect(sf::IntRect(112*col, 100 * row, 112, 100));
    obj->setPosition(pos);
    objects->push_back(obj);
    col = !col;
    pos += offset;
    for(int i = 1; i < countOfSegments; i++)
    {
        obj = new Object;
        obj->setPosition(pos);
        obj->setTexture(Textures::Wall);
        obj->setTextureRect(sf::IntRect(112*col, 100 * row, 112, 100));
        objects->push_back(obj);
        col = !col;
        pos += offset;
    }
    std::cout << "Exit create wall\n";
}
