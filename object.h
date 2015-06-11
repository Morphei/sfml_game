#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object : sf::Drawable
{
public:
    Object();

    friend class EntityManager;

    virtual sf::Sprite* getSprite();

    virtual int getId();
    virtual void setID(int ID);

    virtual void setPosition(sf::Vector2f pos);

    virtual sf::Vector2f getPosition();

//protected:
    sf::Vector2f position;
    int objectID;
    sf::Sprite sprite;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(sprite, states);
    }
};

#endif // OBJECT_H
