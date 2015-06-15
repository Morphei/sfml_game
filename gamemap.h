#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "resourcemanager.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>


const int HEIGHT_MAP = 50;
const int WIDTH_MAP = 50;

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
    std::string path = "/home/morphei/resources/gameMap.txt";
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

    void drawWallRect(sf::RenderWindow *target, sf::Vector2f at, sf::FloatRect viewRect);
    sf::CircleShape shape;
    int countOfTiles = 32;
    int countOfRandObj;
    sf::Texture mapTexture;
    sf::Texture wallText;
    mutable sf::Sprite mapSprite;
    mutable sf::Sprite wallSprite;

    int map[HEIGHT_MAP][WIDTH_MAP];
//    {
//        {1,2,3,4,4,14,4,4,4,15},
//        {4,4,4,4,18,4,4,13,4,4},
//        {4,4,17,4,4,4,4,4,4,4},
//        {4,4,4,5,4,6,4,4,4,4},
//        {4,18,4,4,4,4,4,4,12,4},
//        {4,4,4,4,7,4,4,4,4,4},
//        {19,4,4,4,4,4,4,11,4,4},
//        {4,4,8,4,4,16,4,4,4,4},
//        {4,4,4,17,4,4,4,4,4,4},
//        {9,4,4,4,4,4,10,4,4,4}
//    };
    int map2[HEIGHT_MAP][WIDTH_MAP];
//    {
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4},
//        {4,4,4,4,4,4,4,4,4,4}
//    };
};

#endif // GAMEMAP_H
