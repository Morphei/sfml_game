#include "object.h"

Object::Object()
{
    classType = ObjectType::Object;
}

sf::Sprite *Object::getSprite()
{
    return &sprite;
}

ObjectType::ID Object::getClassName()
{
    return classType;
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
    sprite.setPosition(pos);
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

    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height/2.f);
}

void Object::setTextureRect(sf::IntRect rect)
{
    sprite.setTextureRect(rect);
}

//void Object::move(sf::Vector2f target)
//{

//}
