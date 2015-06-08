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
//    mapSprite.setTextureRect(sf::IntRect(0, 240, 160, 80));
//    for (int i = -25; i < 25; i++)
//        for(int j = -25; j < 25; j++)
//        {
//            mapSprite.setPosition(i * 160, j * 80);
//            target.draw(mapSprite);
//            mapSprite.setPosition((i-0.5) * 160, (j-0.5) * 80);
//            target.draw(mapSprite);
//        }

//    sf::View currentView = target.getView();
//    sf::FloatRect viewRect = sf::FloatRect(sf::Vector2f(currentView.getCenter().x - (currentView.getSize().x)/2,
//                                                        currentView.getCenter().y - (currentView.getSize().y)/2) , currentView.getSize());

//    for (int i = 0; i < HEIGHT_MAP; i++)
//                for (int j = 0; j < WIDTH_MAP; j++)
//                {
//                    mapSprite.setPosition(j * 160, i * 80);
//                    mapSprite.setTextureRect((sf::IntRect(0, ((map[i][j] - 1) * 80), 160, 80)));
//                    if(viewRect.intersects(mapSprite.getGlobalBounds()))
//                    target.draw(mapSprite);

//                }

//    for (int i = 0; i < HEIGHT_MAP; i++)
//                for (int j = 0; j < WIDTH_MAP; j++)
//                {
//                    mapSprite.setTextureRect((sf::IntRect(0, ((map[i][j] - 1) * 80), 160, 80)));

//                    mapSprite.setPosition((j-0.5) * 160, (i-0.5) * 80);

//                    if(viewRect.intersects(mapSprite.getGlobalBounds()))
//                    target.draw(mapSprite);
//                }

//    sf::View currentView = target.getView();
//    sf::FloatRect viewRect = sf::FloatRect(sf::Vector2f(veiw.getCenter().x - (veiw.getSize().x)/2, veiw.getCenter().y - (veiw.getSize().y)/2) , veiw.getSize());

    for (int i = 0; i < HEIGHT_MAP; i++)
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    mapSprite.setPosition(j * 160, i * 80);
                    mapSprite.setTextureRect((sf::IntRect(0, ((map[i][j] - 1) * 80), 160, 80)));
                    target.draw(mapSprite);

                }

    for (int i = 0; i < HEIGHT_MAP; i++)
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                      mapSprite.setTextureRect((sf::IntRect(0, ((map[i][j] - 1) * 80), 160, 80)));

                    mapSprite.setPosition((j-0.5) * 160, (i-0.5) * 80);
                    target.draw(mapSprite);
                }
}


