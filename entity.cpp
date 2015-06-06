#include "entity.h"

Entity::Entity()
{
}

void Entity::update(sf::Time deltaTime)
{
    if(state == EntityState::stateOfObject::Run)
            {
            distanceToTarget = sqrt( ( (targetCoordinates.x - mPosition.x)*(targetCoordinates.x - mPosition.x) ) +
                                 ( (targetCoordinates.y - mPosition.y)*(targetCoordinates.y - mPosition.y) ) );

                if(distanceToTarget > 5)
                    {

                    mPosition.x += ((targetCoordinates.x - mPosition.x)/distanceToTarget) * mSpeed * deltaTime.asSeconds();
                    mPosition.y += ((targetCoordinates.y - mPosition.y)/distanceToTarget) * mSpeed * deltaTime.asSeconds();

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

}

void Entity::setName(std::string name)
{
    nickname = name;
}

std::string Entity::getName()
{
    return nickname;
}

void Entity::setPosition(sf::Vector2f pos)
{
    mPosition = pos;
    mAnimation.setPosition(pos);
}

void Entity::setPosition(float vx, float vy)
{
    mPosition.x = vx;
    mPosition.y = vy;
    mAnimation.setPosition(mPosition);
}

void Entity::setStats(EntityState::statsOfEntity stats)
{
    statsOfEntity = stats;
}

sf::Vector2f Entity::getPosition() const
{
    return mPosition;
}

void Entity::colourise()
{
   sf::Sprite* sprite = mAnimation.getSprite();
   sprite->setColor(sf::Color::Green);
}

void Entity::unColourise()
{
    sf::Sprite* sprite = mAnimation.getSprite();
    sprite->setColor(sf::Color::White);
}

void Entity::setTexture(Textures::ID_InGame id, sf::Vector2i sizeNorm, sf::Vector2i sizeAttack, sf::Vector2i sizeRun)
{
    mAnimation.setTexture(id);
    mAnimation.setSize(sizeNorm, sizeAttack, sizeRun);
    std::cout << "setting texture&size to animation\n";
}

void Entity::initDefault()
{
    std::cout << "Entity::initDefault" << std::endl;
    mPosition = sf::Vector2f(200,200);
}

void Entity::move(sf::Vector2f target)
{

    targetCoordinates = target;

    float dx = targetCoordinates.x - mPosition.x;
    float dy = targetCoordinates.y - mPosition.y;
    float rotation = (atan2(dy, dx) + PI) * 180 / PI;
    int direct = rotation/22.5;

    dir = static_cast<EntityState::direction>(direct);

    setState(EntityState::Run, dir);
}


void Entity::setState(EntityState::stateOfObject st, EntityState::direction dr)
{
    state = st;
    dir = dr;
    mAnimation.init(state, dir);
}

void Entity::setType(EntityState::typeOfEntity enType)
{
    type = enType;
    initializier.init(type, this);
}

void Entity::setSpeed(int spd)
{
    mSpeed = spd;
}
