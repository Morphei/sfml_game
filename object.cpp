#include "object.h"

Object::Object()
{

}

sf::Sprite *Object::getSprite()
{
    return &sprite;
}

int Object::getID() const
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

sf::Vector2f Object::getPosition() const
{
    return position;
}

void Object::update(sf::Time deltaTime)
{

}

void Object::setTexture(Textures::ID_InGame id)
{
    sprite.setTexture(textureHolder.get(id));
}

void Object::setTextureRect(sf::IntRect rect)
{
    sprite.setTextureRect(rect);
}

//void Object::move(sf::Vector2f target)
//{

//}
