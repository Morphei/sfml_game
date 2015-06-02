#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
public:

    Player();

    void setSpeed(int spd);

    void initDefault();

private:

};

#endif // PLAYER_H
