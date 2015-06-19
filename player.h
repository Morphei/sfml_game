#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
public:

    void update(sf::Time deltaTime);

    Player();

    sf::View playerView;

    void setSpeed(int spd);

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(mAnimation, states);
        target.draw(nicknameToDraw);
        if(gameState != States::Menu)
        target.setView(playerView);
    }

};

#endif // PLAYER_H
