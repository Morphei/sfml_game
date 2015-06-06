#include "entitymanager.h"

EntityManager::EntityManager()
{

}

void EntityManager::checkClick(sf::Vector2f cursorPos)
{
    unsigned short i = 0;
    for(auto itr = enemies.begin(); itr != enemies.end(); itr++)
    {
        if((*itr).checkClick(cursorPos))
            {
            (*itr).colourise();
            selectedEnemy = (*itr).getName();
            }
        else (*itr).unColourise();
        i++;
    }
}

std::string EntityManager::getSeectedEnemy()
{
    return selectedEnemy;
}

void EntityManager::addEnemy(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos)
{
    Enemy enemy;
    enemy.setName(nickname);
    enemy.setType(type);
    enemy.setPosition(pos);
    enemies.push_back(enemy);
}

void EntityManager::moveEnemy(std::string nick, sf::Vector2f target)
{
    for(auto it = enemies.begin(); it != enemies.end(); it++)
    {
        if((*it).getName() == nick)
        {
            (*it).move(target);
        }
    }
}

void EntityManager::initPlayer(Player pl)
{
    mPlayer = pl;
}

void EntityManager::initPlayer(EntityState::typeOfEntity type, sf::Vector2f pos, EntityState::statsOfEntity stats)
{
    mPlayer.setType(type);
    mPlayer.setPosition(pos);
    mPlayer.setStats(stats);
}

void EntityManager::movePlayer(sf::Vector2f target)
{
    mPlayer.move(target);
}

void EntityManager::update(sf::Time deltaTime)
{
    for(auto itr = enemies.begin(); itr != enemies.end(); itr ++)
    {
        (*itr).update(deltaTime);
    }

    mPlayer.update(deltaTime);

    std::sort(enemies.begin(), enemies.end(), [](const Enemy& tempA, const Enemy& tempB)
    { return tempA.getPosition().y < tempB.getPosition().y;} );

}


void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

        auto itr = enemies.begin();

        while(itr!= enemies.end())
        {
            if((*itr).getPosition().y < mPlayer.getPosition().y)
            {
            target.draw((*itr));
            }

            itr++;

        }

        itr = enemies.begin();
        target.draw(mPlayer);

        while(itr!= enemies.end())
        {
            if((*itr).getPosition().y > mPlayer.getPosition().y)
            {
            target.draw((*itr));
            }
            itr++;
        }

}
