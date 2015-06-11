#include "object.h"

Object::Object()
{

}

sf::Sprite *Object::getSprite()
{
    return &sprite;
}

int Object::getId()
{
    return objectID;
}

void Object::setID(int ID)
{
    objectID = ID;
}

void Object::setPosition(sf::Vector2f pos)
{
    position = pos;
}

sf::Vector2f Object::getPosition()
{
    return position;
}
