#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include "resourcemanager.h"

class Object : sf::Drawable
{
public:
    Object();

    friend class EntityManager;

    virtual sf::Sprite* getSprite();

    virtual int getID() const;
    virtual void setID(int ID);

    virtual void setPosition(sf::Vector2f pos);

    virtual sf::Vector2f getPosition() const;

    virtual void update(sf::Time deltaTime);

    virtual void setTexture(Textures::ID_InGame id);
    virtual void setTextureRect(sf::IntRect rect);

//    virtual void move(sf::Vector2f target);



protected:
    sf::Vector2f position;
    int objectID;

    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite, states);
    }
};

#endif // OBJECT_H
