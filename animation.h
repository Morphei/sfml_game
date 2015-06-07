#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include "resourcemanager.h"
#include "gamestates.h"

#include <iostream>

class Animation : public sf::Drawable
{

public:

    Animation();
    void update(sf::Time dt);
    void init(EntityState::stateOfObject state, EntityState::direction dir);

    void setTexture(Textures::ID_InGame id);

    void setPosition(sf::Vector2f position);

    void setState(EntityState::stateOfObject state);

    void setSize(sf::Vector2i norm, sf::Vector2i att, sf::Vector2i run);

    void setSprite(sf::Sprite sprite);

    sf::Sprite *getSprite();

private:

    sf::Vector2f mPosition;

    sf::Vector2i normalSize, runSize, attackSize;

    sf::Sprite mSprite;

    EntityState::direction orientation;

    int countOfSpritesInRaw = 14;

    sf::Vector2i currentSprite;

    int timeToChangeSprite = 10;

    int width, height;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(mSprite, states);
    }

};

#endif // ANIMATION_H
