#include "headupdisplay.h"

HeadUpDisplay::HeadUpDisplay()
{
}

void HeadUpDisplay::createHud(Player *player)
{
      pl = player;
      hitBar.setTexture(textureHolder.get(Textures::Bars));
}

void HeadUpDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    hitBar.setTextureRect(sf::IntRect(0,6,15,6));
    hitBar.setPosition(pl->getPosition() + sf::Vector2f(-650, 350));
    target.draw(hitBar);
    hitBar.setTextureRect(sf::IntRect(0,0,15,6));
    hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-4));
    target.draw(hitBar);

    for(int i = 0; i < pl->getStats()->hitPoints; i++)
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

    for(int i = 0; i < pl->getStats()->manaPoints; i++)
    {
        hitBar.setPosition(hitBar.getPosition() + sf::Vector2f(0,-4));
        target.draw(hitBar);
    }
}
