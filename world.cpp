#include "world.h"
#include <iostream>

World::World()
{
}

void World::clickPlayer(sf::Vector2f target)
{
    entities.playerClick(target);
}

void World::update(sf::Time deltaTime)
{
    entities.update(deltaTime);
}

void World::addEnemy(std::string nick, EntityState::typeOfEntity type, sf::Vector2f pos)
{
    entities.addEnemy(type, nick, pos);
}

void World::moveEnemy(std::string nick, sf::Vector2f target)
{
    entities.moveEnemy(nick, target);
}

//void World::initPlayer(Player* player)
//{
//    entities.initPlayer(player);
//}

void World::initPlayer(EntityState::typeOfEntity id, std::string nick, sf::Vector2f position, EntityState::statsOfEntity stats)
{
    entities.initPlayer(id, nick, position, stats);
}

void World::initMap(Textures::ID_InGame id)
{
    map.setTexture(id);
}

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(map);
    target.draw(entities);
}
