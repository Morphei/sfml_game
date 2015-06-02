#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

#include "entitymanager.h"
#include "gamemap.h"

class World : public sf::Drawable
{
public:
    World();
    void movePlayer(sf::Vector2f target);
    void update(sf::Time deltaTime);

    void initPlayer(Textures::ID_InGame id, sf::Vector2f position);
    void initPlayer(Textures::ID_InGame id, sf::IntRect rect, sf::Vector2f position);
    void initMap(Textures::ID_InGame id);
    void initDefaultSettings();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    EntityManager entities;
    GameMap map;
};

#endif // WORLD_H
