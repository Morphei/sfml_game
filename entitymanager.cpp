#include "entitymanager.h"

EntityManager::EntityManager()
{

}

void EntityManager::addEnemy(EntityState::typeOfEntity type, sf::Vector2f pos)
{
    Enemy enemy;
    enemy.setType(type);
    enemy.setPosition(pos);
    enemies.push_back(enemy);
}

void EntityManager::movePlayer(sf::Vector2f target)
{
    mPlayer.move(target);
}

void EntityManager::initDefault()
{
    mPlayer.setType(EntityState::Amazon);

    addEnemy(EntityState::Amazon, sf::Vector2f(400,400));

}

void EntityManager::update(sf::Time deltaTime)
{
    for(auto itr = enemies.begin(); itr != enemies.end(); itr ++)
    {
        (*itr).update(deltaTime);
    }

    mPlayer.update(deltaTime);

    std::sort(enemies.begin(), enemies.end(), [](const Enemy& tempA, const Enemy& tempB)
    { return tempA.getPosition().x < tempB.getPosition().x;} );

}


void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

        auto itr = enemies.begin();

        while(itr!= enemies.end())
        {
            if((*itr).getPosition().y < mPlayer.getPosition().y)
            target.draw((*itr));
            itr++;

        }

        itr = enemies.begin();
        target.draw(mPlayer);

        while(itr!= enemies.end())
        {
            if((*itr).getPosition().y > mPlayer.getPosition().y)
            target.draw((*itr));
            itr++;
        }

}
