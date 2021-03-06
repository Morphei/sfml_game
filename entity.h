#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "resourcemanager.h"
#include "animation.h"

#include "entityconfigurator.h"
#include "object.h"

const float PI = 3.14159265;

class Entity : public Object
{

public:

    Entity();

    EntityState::stateOfObject getState();

    virtual void stop();

    virtual void attack(sf::Vector2f target);

    virtual void update(sf::Time deltaTime);

    virtual void setName(std::string name);

    virtual void setPosition(sf::Vector2f pos);

    virtual void setPosition(float vx, float vy);

    virtual void setStats(EntityState::statsOfEntity st);

    virtual void setTexture(Textures::ID_InGame id, sf::Vector2i sizeNorm, sf::Vector2i sizeAttack, sf::Vector2i sizeRun);

    virtual void initDefault();

    virtual void move(sf::Vector2f target);

    virtual void setState(EntityState::stateOfObject st, EntityState::direction dr);

    virtual void setState(EntityState::stateOfObject st, EntityState::direction dr, int norm, int att, int run);

    virtual void setType(EntityState::typeOfEntity enType);

    virtual EntityState::typeOfEntity getType();

    virtual void setSpeed(int spd);

    virtual sf::Vector2f getPosition() const;

    std::string getName();

    virtual void colourise();

    virtual void unColourise();

    virtual sf::Sprite* getSprite();

    virtual EntityState::statsOfEntity* getStats();

    virtual bool checkClick(sf::Vector2f pos);

    virtual bool isStopped();


protected:

    bool stoppedFlag = false;

    std::string nickname;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(mAnimation, states);
        target.draw(nicknameToDraw);
    }

    int mSpeed;

    EntityConfigurator initializier;

    sf::Vector2f targetCoordinates;

    float distanceToTarget;

    Animation mAnimation;

    sf::Vector2f mVelocity;

    sf::Vector2f mPosition;

    sf::Text nicknameToDraw;

    EntityState::typeOfEntity type;

    EntityState::direction dir, noWay;

    EntityState::statsOfEntity stats;

    EntityState::stateOfObject state;

};

#endif // ENTITY_H
