#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "entitymanager.h"
#include "gamemap.h"
#include "formmanager.h"

class World : public sf::Drawable
{
public:
    World();


    void clickPlayer(sf::Vector2f target);
    void update(sf::Time deltaTime);

    void showStats();
    void closeStats();
    void attackOtherEnemy(std::string attacker, std::string target);
    void deleteEnemy(std::string nick);
    void addEnemy(std::string nick, EntityState::typeOfEntity type, sf::Vector2f pos);
    void moveEnemy(std::string nick, sf::Vector2f target);
//    void initPlayer(Player *player);
    void initPlayer(EntityState::typeOfEntity id, std::string nick, sf::Vector2f position, EntityState::statsOfEntity stats);
    void initMap(Textures::ID_InGame id);
        EntityManager entities;

private:
    FormManager formManager;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    GameMap map;
};

#endif // WORLD_H
