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
            for(auto itr2 = enemies.begin(); itr2 != enemies.end(); itr2++)
                (*itr2).unColourise();
            (*itr).colourise();
            selectedEnemy = (*itr).getName();
            selectedEnemyType = (*itr).getType();
            }
    }
}

std::string EntityManager::getSeectedEnemy()
{
    return selectedEnemy;
}

EntityState::typeOfEntity EntityManager::getSelectedEnemyType()
{
    return selectedEnemyType;
}

void EntityManager::addEnemy(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos)
{
    Enemy enemy;
    enemy.setType(type);
    enemy.setPosition(pos);
    enemy.setName(nickname);
    enemy.setID(countOfObjects);
    countOfObjects++;
    enemies.push_back(enemy);

    objectSprite oSprite;
    oSprite.ID = enemy.getId();
    oSprite.sprite = enemy.getSprite();
    spritesToDraw.insert(std::pair<float, objectSprite>(enemy.getPosition().y, oSprite));
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

void EntityManager::initPlayer(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos, EntityState::statsOfEntity stats)
{
    std::cout << "Setting type of player\n";
    mPlayer.setType(type);
    std::cout << "Setting position\n";
    mPlayer.setPosition(pos);
    std::cout << "Setting stats\n";
    mPlayer.setStats(stats);
    mPlayer.setName(nickname);
    std::cout << "Exit init player///////\n";
    std::cout << "\n";
    mPlayer.setID(countOfObjects);
    countOfObjects++;

    objectSprite oSprite;
    oSprite.ID = mPlayer.getId();
    oSprite.sprite = mPlayer.getSprite();
    spritesToDraw.insert(std::pair<float, objectSprite>(mPlayer.getPosition().y, oSprite));
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

    for(auto itr = spritesToDraw.begin(); itr != spritesToDraw.end(); itr++)
    {
        target.draw(*(*itr).second.sprite);
    }

//        auto itr = enemies.begin();

//        while(itr!= enemies.end())
//        {
//            if((*itr).getPosition().y < mPlayer.getPosition().y)
//            {
//            target.draw((*itr));
//            }

//            itr++;

//        }

//        itr = enemies.begin();
//        target.draw(mPlayer);

//        while(itr!= enemies.end())
//        {
//            if((*itr).getPosition().y > mPlayer.getPosition().y)
//            {
//            target.draw((*itr));
//            }
//            itr++;
//        }

}
