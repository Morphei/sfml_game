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

void World::showStats()
{
    formManager.createForm(Forms::ID::StatsForm, sf::Vector2f(100,100));
}

void World::closeStats()
{
    formManager.close();
}

void World::attackOtherEnemy(std::string attacker, std::string target)
{
    std::cout << "World::attackOtherEnemy - " << attacker << " : " << target << "\n";
    entities.findEnemy(attacker)->attack(entities.findEnemy(target)->getPosition());
}



void World::deleteEnemy(std::string nick)
{
    entities.deleteEnemy(nick);
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
    target.draw(formManager);
}
