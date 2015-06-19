#include "entitymanager.h"

EntityManager::EntityManager()
{
    constructor = new ObjectConstructor(&objects);
    EntityState::statsOfEntity stat;
    stat.hitPoints = 50;
    stat.manaPoints = 60;
    killText.setCharacterSize(20);
    killText.setFont(fontHolderMenu.get(Fonts::MainFontMenu));
//    initPlayer(EntityState::Amazon, "test", sf::Vector2f(3100,1100), stat);
    //    addEnemy(EntityState::typeOfEntity::Amazon, "meat", sf::Vector2f(3100, 1200));
}

void EntityManager::setKillText(std::string killer, std::string killed)
{
    killText.setPosition(mPlayer->playerView.getCenter() - sf::Vector2f(mPlayer->playerView.getSize().x / 2.1,
                                                                        mPlayer->playerView.getSize().y / 2.3));
    timer = 20000;
    std::string str;
    str = killer + " just killed " + killed;
    std::cout << killer << " killed " << killed << std::endl;
    killText.setString(str);
    drawKill = true;
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
        bool canMove = true;
        for(auto itr = objects.begin(); itr != objects.end(); itr++)
        {
            if((*itr)->getSprite()->getGlobalBounds().contains(target))
            {
               if((*itr)->getClassName() == ObjectType::Object)
               {
                    canMove = false;
               }

            }

        }
        if(canMove)
        {
            mPlayer->move(target);
            sender.sendMouseClick(target);
        }

    }
}
void EntityManager::update(sf::Time deltaTime)
{
    timer--;

    if (timer <= 0)
    {
        drawKill = false;
    }

        sf::FloatRect playerRect;
    if(mPlayer != nullptr)
    playerRect = sf::FloatRect(mPlayer->getPosition().x - 10, mPlayer->getPosition().y - 10, 10, 10);

    for(auto itr = objects.begin(); itr != objects.end(); itr ++)
    {
        (*itr)->update(deltaTime);

        if((*itr)->getClassName() == ObjectType::Object)
        {
            if((*itr)->getSprite()->getGlobalBounds().intersects(playerRect) /*&& !mPlayer->isStopped()*/)
            {
                sf::Vector2f temp;
                temp.x = mPlayer->getPosition().x - (*itr)->getPosition().x;
                temp.y = mPlayer->getPosition().y - (*itr)->getPosition().y;

                mPlayer->stop();

                mPlayer->move(mPlayer->getPosition() + sf::Vector2f(temp.x + 20 , temp.y + 20));

//                mPlayer->stop();
//                mPlayer->stop();
//                mPlayer->setPosition(mPlayer->getPosition().x + );
            }

        }
    }

    if(mPlayer != nullptr)
        mPlayer->playerView.setCenter(mPlayer->getPosition());

    if(drawKill)
    killText.setPosition(mPlayer->playerView.getCenter() - sf::Vector2f(mPlayer->playerView.getSize().x / 2.1,
                                                                        mPlayer->playerView.getSize().y / 2.3));

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

        if(drawKill)
        {

            target.draw(killText);
        }
}
