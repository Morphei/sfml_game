#ifndef HEADUPDISPLAY_H
#define HEADUPDISPLAY_H

#include <SFML/Graphics.hpp>

#include "player.h"

class HeadUpDisplay : public sf::Drawable
{
public:
    HeadUpDisplay();
    void createHud(Player *player);

private:
    Player* pl;
    int hitPoints = 0;
    mutable sf::Sprite hitBar;
    sf::RenderTexture* textureToDraw;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // HEADUPDISPLAY_H
