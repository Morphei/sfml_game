#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

#include "object.h"
#include "enemy.h"
#include "player.h"
#include "headupdisplay.h"
#include "messagesender.h"
#include "objectconstructor.h"

class EntityManager : public sf::Drawable
{
public:
    EntityManager();

    void setKillText(std::string killer, std::string killed);

    EntityState::typeOfEntity getSelectedEnemyType();

    Player *getPlayer();

    Entity *findEnemy(std::string nick);

    void checkClick(sf::Vector2f cursorPos);

    std::string getSelectedEnemy();

    void deleteEnemy(std::string nick);

    void addEnemy(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos);

    void moveEnemy(std::string nick, sf::Vector2f target);

    void initPlayer(EntityState::typeOfEntity type, std::string nickname, sf::Vector2f pos, EntityState::statsOfEntity stats);

    void playerClick(sf::Vector2f target);

    void update(sf::Time deltaTime);

    //
        mutable bool i = true;
    //

private:
    int timer = 20000;

    bool drawKill = false;

    int countOfObjects = 0;

    HeadUpDisplay hud;
    ObjectConstructor* constructor;


    std::vector<Entity*> enemies;
    mutable std::vector<Object*> objects;

    Player* mPlayer = nullptr;

    struct objectSprite{
        sf::Sprite* sprite;
        int ID;
    };

    MessageSender sender;

    sf::Text killText;

    sf::View playerView;

    std::multimap<float, objectSprite*> spritesToDraw;

    std::string selectedEnemy = "";

    EntityState::typeOfEntity selectedEnemyType;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // ENTITYMANAGER_H
