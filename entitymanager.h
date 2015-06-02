#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

#include "enemy.h"
#include "player.h"

class EntityManager : public sf::Drawable
{
public:
    EntityManager();

    void addEnemy(EntityState::typeOfEntity type, sf::Vector2f pos);

    void initPlayer();

    void movePlayer(sf::Vector2f target);

    void initDefault();

    void update(sf::Time deltaTime);

private:
    std::vector<Enemy> enemies;

    Player mPlayer;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // ENTITYMANAGER_H
