#include "enemy.h"

Enemy::Enemy()
{

}

bool Enemy::checkClick(sf::Vector2f pos)
{
    if(mAnimation.getSprite()->getGlobalBounds().contains(pos))
        return true;
    else return false;
}



