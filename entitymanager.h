#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

#include "object.h"
#include "enemy.h"
#include "player.h"
#include "headupdisplay.h"
#include "objectconstructor.h"

class EntityManager : public sf::Drawable
{
public:
    EntityManager();

    EntityState::typeOfEntity getSelectedEnemyType();

    void checkClick(sf::Vector2f cursorPos);

    std::string getSeectedEnemy();

    void addEnemy(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos);

    void moveEnemy(std::string nick, sf::Vector2f target);

    void initPlayer(Player *pl);

    void initPlayer(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos, EntityState::statsOfEntity stats);

    void movePlayer(sf::Vector2f target);

    void update(sf::Time deltaTime);

private:
    int countOfObjects = 0;

    HeadUpDisplay hud;
    ObjectConstructor* constructor;


    std::vector<Enemy*> enemies;
    std::vector<Object*> objects;

    Player* mPlayer = nullptr;

    struct objectSprite{
        sf::Sprite* sprite;
        int ID;
    };

    sf::View playerView;

    std::multimap<float, objectSprite*> spritesToDraw;

    std::string selectedEnemy = "";

    EntityState::typeOfEntity selectedEnemyType;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // ENTITYMANAGER_H
