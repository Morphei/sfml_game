#include "gamemap.h"
#include <iostream>

GameMap::GameMap()
{
}

void GameMap::setTexture(Textures::ID_InGame id)
{
    mapTexture = textureHolder.get(id);
    mapSprite.setTexture(mapTexture);
}

void GameMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    for (int i = 0; i < HEIGHT_MAP; i++)
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    for(int n = 1; n <= countOfTiles; n++)
                        if(map[i][j] == n) mapSprite.setTextureRect(sf::IntRect(0,0+80*(n-1),160,80*n));

                    mapSprite.setPosition(j * 160, i * 80);
                    target.draw(mapSprite);
                }

    for (int i = 0; i < HEIGHT_MAP; i++)
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    for(int n = 1; n <= countOfTiles; n++)
                        if(map2[i][j] == n) mapSprite.setTextureRect(sf::IntRect(0,0+80*(n-1),160,80*n));

                    mapSprite.setPosition((j-0.5) * 160, (i-0.5) * 80);
                    target.draw(mapSprite);
                }
}


