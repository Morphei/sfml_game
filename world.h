#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "entitymanager.h"
#include "gamemap.h"

class World : public sf::Drawable
{
public:
    World();
    void movePlayer(sf::Vector2f target);
    void update(sf::Time deltaTime);

    void addEnemy(std::string nick, EntityState::typeOfEntity type, sf::Vector2f pos);
    void moveEnemy(std::string nick, sf::Vector2f target);
    void initPlayer(Player player);
    void initPlayer(EntityState::typeOfEntity id, sf::Vector2f position, EntityState::statsOfEntity stats);
    void initMap(Textures::ID_InGame id);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    EntityManager entities;
    GameMap map;
};

#endif // WORLD_H
