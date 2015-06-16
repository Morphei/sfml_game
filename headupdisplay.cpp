#include "headupdisplay.h"

HeadUpDisplay::HeadUpDisplay()
{
}

void HeadUpDisplay::createHud(Player *player)
{
      pl = player;
      hitBar.setTexture(textureHolder.get(Textures::Bars));
//    pl = player;
//    sf::Sprite hitBar;
//    hitBar.setTexture(textureHolder.get(Textures::Bars));
//    hitBar.setTextureRect(sf::IntRect(0,6,15,6));
//    hitBar.setPosition(sf::Vector2f(1200, 100));
//    textureToDraw.draw(hitBar);
//    hitBar.setTextureRect(sf::IntRect(0,0,15,6));
//    hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-4));
//    textureToDraw.draw(hitBar);
//    for(int i = 0; i < pl->getStats().hitPoints; i++)
//    {
//        hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-6));
//        textureToDraw.draw(hitBar);
//    }
}

void HeadUpDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
//    sf::Sprite hitBar;
    hitBar.setTextureRect(sf::IntRect(0,6,15,6));
    hitBar.setPosition(pl->getPosition() + sf::Vector2f(-650, 350));
    target.draw(hitBar);
    hitBar.setTextureRect(sf::IntRect(0,0,15,6));
    hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-4));
    target.draw(hitBar);
    for(int i = 0; i < pl->getStats().hitPoints; i++)
    {
        hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-4));
        target.draw(hitBar);
    }

    hitBar.setTextureRect(sf::IntRect(15,6,15,6));
    hitBar.setPosition(pl->getPosition() + sf::Vector2f(650, 350));
    target.draw(hitBar);
    hitBar.setTextureRect(sf::IntRect(15,0,15,6));
    hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-4));
    target.draw(hitBar);
    for(int i = 0; i < pl->getStats().manaPoints; i++)
    {
        hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-4));
        target.draw(hitBar);
    }
}
