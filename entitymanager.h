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

    void checkClick(sf::Vector2f cursorPos);

    std::string getSeectedEnemy();

    void addEnemy(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos);

    void moveEnemy(std::string nick, sf::Vector2f target);

    void initPlayer(Player pl);

    void initPlayer(EntityState::typeOfEntity type, sf::Vector2f pos, EntityState::statsOfEntity stats);

    void movePlayer(sf::Vector2f target);

    void update(sf::Time deltaTime);

private:
    std::vector<Enemy> enemies;

    std::string selectedEnemy;

    Player mPlayer;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // ENTITYMANAGER_H
