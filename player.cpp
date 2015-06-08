#include "player.h"
#include "iostream"

Player::Player()
{
    playerViev.reset(sf::FloatRect(0,0,1366,768));
}

void Player::setSpeed(int spd)
{
    mSpeed = spd;
}

void Player::update(sf::Time deltaTime)
{
    if(state == EntityState::stateOfObject::Run)
            {
            distanceToTarget = sqrt( ( (targetCoordinates.x - mPosition.x)*(targetCoordinates.x - mPosition.x) ) +
                                 ( (targetCoordinates.y - mPosition.y)*(targetCoordinates.y - mPosition.y) ) );

                if(distanceToTarget > 5)
                    {

                    mPosition.x += ((targetCoordinates.x - mPosition.x)/distanceToTarget) * mSpeed * deltaTime.asSeconds();
                    mPosition.y += ((targetCoordinates.y - mPosition.y)/distanceToTarget) * mSpeed * deltaTime.asSeconds();

                    nicknameToDraw.setPosition(mPosition.x, mPosition.y - mAnimation.getSprite()->getGlobalBounds().height * 1.1);

                    mAnimation.setPosition(mPosition);
                    mAnimation.update(deltaTime);

                    }

                else
                    {
                        setState(EntityState::Normal, dir);
                    }


            }
    else
        mAnimation.update(deltaTime);

    playerViev.setCenter(mPosition);

}
