#include "world.h"
#include <iostream>

World::World()
{
}

void World::movePlayer(sf::Vector2f target)
{
    entities.movePlayer(target);
}

void World::update(sf::Time deltaTime)
{
    entities.update(deltaTime);
}

void World::initPlayer(Textures::ID_InGame id, sf::Vector2f position)
{

}

void World::initPlayer(Textures::ID_InGame id, sf::IntRect rect, sf::Vector2f position)
{

}

void World::initMap(Textures::ID_InGame id)
{
    map.setTexture(id);
}

void World::initDefaultSettings()
{
    entities.initDefault();
}

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(map);
    target.draw(entities);
}
