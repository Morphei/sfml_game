#include "entity.h"

Entity::Entity()
{
}

void Entity::attack(sf::Vector2f target)
{
//    state = EntityState::Attack;
    targetCoordinates = target;

    float dx = targetCoordinates.x - mPosition.x;
    float dy = targetCoordinates.y - mPosition.y;
    float rotation = (atan2(dy, dx) + PI) * 180 / PI;
    int direct = rotation/22.5;

    dir = static_cast<EntityState::direction>(direct);

    setState(EntityState::Attack, dir);

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

}

void Entity::setName(std::string name)
{
    nickname = name;
    nicknameToDraw.setString(nickname);

//    if(gameState == States::Menu)
//    nicknameToDraw.setFont(fontHolderMenu.get(Fonts::MainFontMenu));

//    if (gameState == States::Game)
    nicknameToDraw.setFont(fontHolder.get(Fonts::MainFontGame));

    nicknameToDraw.setCharacterSize(20);
    sf::FloatRect bounds = nicknameToDraw.getLocalBounds();
    nicknameToDraw.setOrigin(bounds.width / 2.f, bounds.height);
    nicknameToDraw.setPosition(mPosition.x, mPosition.y - mAnimation.getSprite()->getGlobalBounds().height * 1.1);
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

void Entity::setStats(EntityState::statsOfEntity st)
{
    stats = st;
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

sf::Sprite* Entity::getSprite()
{
    return mAnimation.getSprite();
}

EntityState::statsOfEntity Entity::getStats()
{
    return stats;
}

void Entity::setTexture(Textures::ID_InGame id, sf::Vector2i sizeNorm, sf::Vector2i sizeAttack, sf::Vector2i sizeRun)
{
    mAnimation.setTexture(id);
    mAnimation.setSize(sizeNorm, sizeAttack, sizeRun);
}

void Entity::initDefault()
{
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

EntityState::typeOfEntity Entity::getType()
{
    return type;
}

void Entity::setSpeed(int spd)
{
    mSpeed = spd;
}
