#include "entitymanager.h"

EntityManager::EntityManager()
{
    constructor = new ObjectConstructor(&objects);
//    EntityState::statsOfEntity stat;
//    initPlayer(EntityState::Amazon, "test", sf::Vector2f(-1,-1), stat);
}

void EntityManager::checkClick(sf::Vector2f cursorPos)
{
    unsigned short i = 0;
    for(auto itr = enemies.begin(); itr != enemies.end(); itr++)
    {
        if((*itr)->checkClick(cursorPos))
            {
            for(auto itr2 = enemies.begin(); itr2 != enemies.end(); itr2++)
                (*itr2)->unColourise();
            (*itr)->colourise();
            selectedEnemy = (*itr)->getName();
            selectedEnemyType = (*itr)->getType();
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
    Enemy *enemy = new Enemy;
    enemy->setType(type);
    enemy->setPosition(pos);
    enemy->setName(nickname);
    enemy->setID(countOfObjects);
    countOfObjects++;
    objects.push_back(enemy);

//    objectSprite* oSprite = new objectSprite;
//    oSprite->ID = enemy->getID();
//    oSprite->sprite = enemy->getSprite();
//    spritesToDraw.insert(std::pair<float, objectSprite*>(enemy->getPosition().y, oSprite));
}

void EntityManager::moveEnemy(std::string nick, sf::Vector2f target)
{
    for(auto it = enemies.begin(); it != enemies.end(); it++)
    {
        if((*it)->getName() == nick)
        {
            (*it)->move(target);
        }
    }
}

void EntityManager::initPlayer(Player* pl)
{
    mPlayer = pl;
}

void EntityManager::initPlayer(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos, EntityState::statsOfEntity stats)
{
    mPlayer = new Player;
    std::cout << "Setting type of player\n";
    mPlayer->setType(type);
    std::cout << "Setting position\n";
    mPlayer->setPosition(pos);
    std::cout << "Setting stats\n";
    mPlayer->setStats(stats);
    mPlayer->setName(nickname);
    std::cout << "Exit init player///////\n";
    std::cout << "\n";
    mPlayer->setID(countOfObjects);
    countOfObjects++;

    mPlayer->playerView.setCenter(pos);

    objects.push_back(mPlayer);

    hud.createHud(mPlayer);

//    constructor->drawWall(sf::Vector2f(3000,1000), 20 , sf::Vector2f(3050, 1050));

    addEnemy(EntityState::Amazon, "testEnemy", sf::Vector2f(3000,1050));
}

void EntityManager::movePlayer(sf::Vector2f target)
{
    mPlayer->move(target);
}

void EntityManager::update(sf::Time deltaTime)
{
    for(auto itr = objects.begin(); itr != objects.end(); itr ++)
    {
        (*itr)->update(deltaTime);
    }

    if(mPlayer != nullptr)
        mPlayer->playerView.setCenter(mPlayer->getPosition());
//    {
//        mPlayer->update(deltaTime);

//    }


    std::sort(objects.begin(), objects.end(), [](const Object* tempA, const Object* tempB)
    { return tempA->getPosition().y < tempB->getPosition().y;} );

}


void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    for(auto itr = objects.begin(); itr != objects.end(); itr++)
    {
        target.draw(*(*itr));
    }





//        auto itr = objects.begin();

//        while(itr!= objects.end())
//        {
//            if((*itr)->getPosition().y < mPlayer->getPosition().y)
//            {
//            target.draw(*(*itr));
//            }

//            itr++;

//        }

//        itr = objects.begin();
//        if(mPlayer != nullptr)
//        target.draw(*mPlayer);

//        while(itr!= objects.end())
//        {
//            if((*itr)->getPosition().y > mPlayer->getPosition().y)
//            {
//            target.draw(*(*itr));
//            }
//            itr++;
//        }

        if(mPlayer != nullptr)
        target.draw(hud);

}
