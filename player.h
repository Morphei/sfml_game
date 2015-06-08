#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
public:

    void update(sf::Time deltaTime);

    Player();

    sf::View playerViev;

    void setSpeed(int spd);

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(mAnimation, states);
        target.draw(nicknameToDraw);
        if(gameState != States::Menu)
        target.setView(playerViev);

    }

};

#endif // PLAYER_H
