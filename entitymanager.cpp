#include "entitymanager.h"

EntityManager::EntityManager()
{
    constructor = new ObjectConstructor(&objects);
    EntityState::statsOfEntity stat;
    stat.hitPoints = 50;
    stat.manaPoints = 60;

    initPlayer(EntityState::Amazon, "test", sf::Vector2f(3000,1000), stat);
    addEnemy(EntityState::typeOfEntity::Amazon, "meat", sf::Vector2f(3100, 1200));
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

std::string EntityManager::getSelectedEnemy()
{
    return selectedEnemy;
}

void EntityManager::deleteEnemy(std::string nick)
{
    std::cout << nick << " is deleting\n";

    int ID;

    for(auto itr = enemies.begin(); itr != enemies.end(); itr++)
    {
        if(!enemies.empty())
        {
            if((*itr)->getName() == nick)
            {
                ID = (*itr)->getID();
                enemies.erase(itr);
                break;
                std::cout << "Delete in enemies\n";
            }
        }
        else itr = enemies.end();
    }

    std::cout << "ID to delete: " << ID << "\n";


    for(auto itr = objects.begin(); itr != objects.end(); itr++)
        if(!objects.empty())
        {
            if((*itr)->getID() == ID)
            {
                objects.erase(itr);
                break;
                std::cout << "Delete in objects\n";
            }
        }
}

EntityState::typeOfEntity EntityManager::getSelectedEnemyType()
{
    return selectedEnemyType;
}

Player *EntityManager::getPlayer()
{
    return mPlayer;
}

Entity *EntityManager::findEnemy(std::string nick)
{
    std::cout << "Searching enemy\n";
    for(auto itr = enemies.begin(); itr != enemies.end(); itr++)
    {
            if((*itr)->getName() == nick)
            {
                return (*itr);
            }
    }
}

void EntityManager::addEnemy(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos)
{
    Enemy *enemy = new Enemy;
    enemy->setType(type);
    enemy->setPosition(pos);
    enemy->setName(nickname);
    enemy->setID(countOfObjects);
    std::cout << "Add enemy with ID = " << enemy->getID() << "\n";
    countOfObjects++;

    objects.push_back(enemy);
    enemies.push_back(enemy);

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


void EntityManager::initPlayer(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos, EntityState::statsOfEntity stats)
{
    mPlayer = new Player;
    mPlayer->setType(type);
    mPlayer->setPosition(pos);
    mPlayer->setStats(stats);
    mPlayer->setName(nickname);
    mPlayer->setID(countOfObjects);
    countOfObjects++;

    mPlayer->playerView.setCenter(pos);

    objects.push_back(mPlayer);

    enemies.push_back(mPlayer);

    hud.createHud(mPlayer);

    constructor->drawWall(&objects, sf::Vector2f(3000,1000), 20 , sf::Vector2f(3050, 1050));
    constructor->drawWall(&objects, sf::Vector2f(4550,1750), 20 , sf::Vector2f(4250, 1850));

    constructor->drawWall(&objects, sf::Vector2f(2930,2500), 20 , sf::Vector2f(2800, 2300));
    constructor->drawWall(&objects, sf::Vector2f(1450,1750), 20 , sf::Vector2f(1500, 1200));

//    addEnemy(EntityState::Amazon, "testEnemy", sf::Vector2f(3000,1050));
}

void EntityManager::playerClick(sf::Vector2f target)
{
    bool isAtt = false;

    for(auto itr = enemies.begin(); itr != enemies.end(); itr++)
    {
        if((*itr)->getSprite()->getGlobalBounds().contains(target))
        {
            isAtt = true;

            if(mPlayer->getState() != EntityState::Attack)
            {
                std::cout << "Enter if playerState != Attack\n";

                mPlayer->attack(target);
                sender.attackEnemy((*itr)->getName());
            }
        }

    }

    if(!isAtt)
    {
    mPlayer->move(target);
    sender.sendMouseClick(target);
    }
}

void EntityManager::update(sf::Time deltaTime)
{
    for(auto itr = objects.begin(); itr != objects.end(); itr ++)
    {
        (*itr)->update(deltaTime);
    }

    if(mPlayer != nullptr)
        mPlayer->playerView.setCenter(mPlayer->getPosition());
}


void EntityManager::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(mPlayer != nullptr)
    target.setView(mPlayer->playerView);

    sf::View currentView = target.getView();
    sf::FloatRect viewRect = sf::FloatRect(sf::Vector2f(currentView.getCenter().x - (currentView.getSize().x)/2,currentView.getCenter().y -
                                                        (currentView.getSize().y)/2) , currentView.getSize());

    std::sort(objects.begin(), objects.end(), [](const Object* tempA, const Object* tempB)
    { return tempA->getPosition().y < tempB->getPosition().y;} );

    for(auto itr = objects.begin(); itr != objects.end(); itr++)
    {
        if(viewRect.intersects((*itr)->getSprite()->getGlobalBounds()))
            target.draw(*(*itr));
    }
    i = false;

        if(mPlayer != nullptr)
        target.draw(hud);
}
