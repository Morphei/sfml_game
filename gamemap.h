#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "resourcemanager.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>

const int HEIGHT_MAP = 10;//5
const int WIDTH_MAP = 10;//7,6

//          TODO List
//  1. Отриманна із сервера карти
//
//
//
//
//

class GameMap : public sf::Drawable
{
public:
    GameMap();
    void setTexture(Textures::ID_InGame id);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::CircleShape shape;
    int countOfTiles = 32;
    int countOfRandObj;
    sf::Texture mapTexture;
    mutable sf::Sprite mapSprite;

    int map[HEIGHT_MAP][WIDTH_MAP]
    {
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,6,4,4,9,4},
        {4,4,4,4,5,4,4,4,4,4},
        {4,4,4,4,1,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,8,4},
        {4,4,4,7,4,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4}
    };
    int map2[HEIGHT_MAP][WIDTH_MAP]
    {
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,12,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,14,4,4,4,4,16,4,4},
        {4,4,4,4,4,4,4,4,4,4},
        {4,4,4,4,4,17,4,4,4,4},
        {4,19,4,4,4,4,4,4,4,4}
    };
};

#endif // GAMEMAP_H
