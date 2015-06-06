#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy();

    bool checkClick(sf::Vector2f pos);

private:

};

#endif // ENEMY_H
