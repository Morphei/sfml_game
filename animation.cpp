#include "animation.h"

Animation::Animation()
{
}

EntityState::stateOfObject Animation::getState()
{
    return stateOfEntity;
}

void Animation::update(sf::Time dt)
{

    if(timeToChangeSprite < 0)
    {

                mSprite.setTextureRect(sf::IntRect(currentSprite.x * width, currentSprite.y, width, height));

                    if(currentSprite.x < spritesInRaw - 1)
                        currentSprite.x ++;

                    else
                    {
                        if(stateOfEntity == EntityState::Attack)
                            init(EntityState::Normal, orientation);
                        currentSprite.x = 0;
                    }


                timeToChangeSprite = 100;
    }
    else timeToChangeSprite -= dt.asMilliseconds();

}

void Animation::setCountOfSprites(int norm, int att, int run)
{
    countOfSpritesInRaw.normal = norm;
    countOfSpritesInRaw.attack = att;
    countOfSpritesInRaw.run = run;
}

void Animation::init(EntityState::stateOfObject state, EntityState::direction dir)
{

    stateOfEntity = state;

    orientation = dir;

    switch (state)
    {

    case EntityState::Run:
            {

                width = runSize.x;
                height = runSize.y;

                currentSprite.x = 0;
                currentSprite.y = normalSize.y * 16 + attackSize.y * 16 + orientation * height;

                mSprite.setTextureRect(sf::IntRect(currentSprite.x*width, currentSprite.y, width, height));

                sf::FloatRect bounds = mSprite.getLocalBounds();
                mSprite.setOrigin(bounds.width / 2.f, bounds.height);

                spritesInRaw = countOfSpritesInRaw.run;

            }
        break;

    case EntityState::Normal:
            {

                width = normalSize.x;
                height = normalSize.y;

                currentSprite.x = 0;
                currentSprite.y = 0  + orientation * height;



                mSprite.setTextureRect(sf::IntRect(currentSprite.x * width, currentSprite.y, width, height));

                sf::FloatRect bounds = mSprite.getLocalBounds();
                mSprite.setOrigin(bounds.width / 2.f, bounds.height);

                spritesInRaw = countOfSpritesInRaw.normal;

            }
        break;

    case EntityState::Attack:
            {

                width = attackSize.x;
                height = attackSize.y;

                currentSprite.x = 0;
                currentSprite.y = normalSize.y * 16 + orientation * height;

                mSprite.setTextureRect(sf::IntRect(currentSprite.x*width, currentSprite.y, width, height));

                sf::FloatRect bounds = mSprite.getLocalBounds();
                mSprite.setOrigin(bounds.width / 2.f, bounds.height);

                spritesInRaw = countOfSpritesInRaw.attack;
            }
        break;
    }
}

void Animation::setTexture(Textures::ID_InGame id)
{

    mSprite.setTexture(textureHolder.get(id));

    sf::FloatRect bounds = mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width / 2.f, bounds.height);
}


void Animation::setPosition(sf::Vector2f position)
{
    mPosition = position;
    mSprite.setPosition(mPosition);
}

void Animation::setSize(sf::Vector2i norm, sf::Vector2i att, sf::Vector2i run)
{
    normalSize = norm;
    runSize = run;
    attackSize = att;
}

sf::Sprite* Animation::getSprite()
{
    return &mSprite;
}
