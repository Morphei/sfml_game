#include "gamemap.h"


GameMap::GameMap()
{

    std::ifstream gameMapStream;
    std::vector<unsigned short> v;

    gameMapStream.open(path);

    std::vector<std::vector<unsigned short>> matrix;

    for (std::string line; std::getline(gameMapStream, line); )
    {
         std::istringstream iss(line);

         std::vector<unsigned short> row;

         for (unsigned short d; iss >> d; )
         {
             row.push_back(d);
         }

         matrix.push_back(row);
    }

    int i = 0, j = 0;

    for(auto it = matrix.begin(); it != matrix.end(); it++)
    {
        for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            map2[i][j] = (*it2);
            j++;
        }

        it++;

        j = 0;

        for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
        {
            map[i][j] = (*it2);
            j++;
        }

        i++;

    }

    std::cout << "Exit\n";
}

void GameMap::setTexture(Textures::ID_InGame id)
{
    mapTexture = textureHolder.get(id);
    mapSprite.setTexture(mapTexture);

    wallText = textureHolder.get(Textures::Wall);

    wallSprite.setPosition(8000, 4000);
    wallSprite.setTexture(wallText);

    vectors.push_back(downRight);
    vectors.push_back(downLeft);
    vectors.push_back(UpLeft);
    vectors.push_back(UpRight);

}

void GameMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::View currentView = target.getView();
    sf::FloatRect viewRect = sf::FloatRect(sf::Vector2f(currentView.getCenter().x - (currentView.getSize().x)/2,currentView.getCenter().y -
                                                        (currentView.getSize().y)/2) , currentView.getSize());


    int x = 0;
    for (int i = 0; i < HEIGHT_MAP; i++)
                for (int j = 0; j < WIDTH_MAP; j++)
                {
                    mapSprite.setPosition(j * 160, i * 80);

                    if(viewRect.intersects(mapSprite.getGlobalBounds()))
                    {
                        mapSprite.setTextureRect((sf::IntRect(0, ((map[i][j] - 1) * 80), 160, 80)));
                        target.draw(mapSprite);
                        x++;
                    }

                }

    x = 0;
    for (int i = 0; i < HEIGHT_MAP; i++)
                for (int j = 0; j < WIDTH_MAP; j++)
                {

                    mapSprite.setPosition((j-0.5) * 160, (i-0.5) * 80);

                    if(viewRect.intersects(mapSprite.getGlobalBounds()))
                    {
                        mapSprite.setTextureRect((sf::IntRect(0, ((map2[i][j] - 1) * 80), 160, 80)));
                        target.draw(mapSprite);
                    }

                }

    wallSprite.setPosition(3000,1000);

    bool n = false;
    bool dir = true;

    for (int i = 0; i < 4; i++)
    {
        sf::Vector2f currentVector = (vectors.at(i));

        for(int j = 0; j < 30; j++)
        {
            if(viewRect.intersects(wallSprite.getGlobalBounds()))
            {
                if(dir)
                {
                        if(n)
                        {
                             wallSprite.setTextureRect(sf::IntRect(0,0,124,100));
                        }

                        else
                        {
                             wallSprite.setTextureRect(sf::IntRect(124,0,124,100));
                        }

                }
                else
                {
                        if(n)
                        {
                             wallSprite.setTextureRect(sf::IntRect(0,100,112,101));
                        }

                        else
                        {
                             wallSprite.setTextureRect(sf::IntRect(112,100,112,101));
                        }
                }
                target.draw(wallSprite);
            }
            n = !n;
            wallSprite.setPosition(wallSprite.getPosition() + currentVector);
        }
        dir = !dir;
    }

//    drawWallRect(target, sf::Vector2f(8000, 4000), viewRect);


//void GameMap::drawWallRect(sf::RenderWindow* target, sf::Vector2f at, sf::FloatRect viewRect)
//{


//    for(int i = 0; i < 50; i++)
//    {

//        if(n)
//        {
//             wallSprite.setTextureRect(sf::IntRect(0,0,124,100));
//             n = false;
//        }

//        else
//        {
//             wallSprite.setTextureRect(sf::IntRect(124,0,124,100));
//             n = true;
//        }

//        if(viewRect.intersects(wallSprite.getGlobalBounds()))
//        {
//            target.draw(wallSprite);
//        }

//            //std::cout << wallSprite.getPosition().x << " " << wallSprite.getPosition().y << "\n";

//        wallSprite.setPosition(sf::Vector2f(wallSprite.getPosition().x + 80, wallSprite.getPosition().y + 38));
//    }

//    wallSprite.setPosition(8000, 4000);
//    for(int i = 0; i < 50; i++)
//    {
//        if(n)
//        {
//             wallSprite.setTextureRect(sf::IntRect(0,100,112,100));
//             n = false;
//        }

//        else
//        {
//             wallSprite.setTextureRect(sf::IntRect(112,100,112,100));
//             n = true;
//        }

//        if(viewRect.intersects(wallSprite.getGlobalBounds()))
//        {
//            target.draw(wallSprite);
//        }

//            //std::cout << wallSprite.getPosition().x << " " << wallSprite.getPosition().y << "\n";

//            wallSprite.setPosition(sf::Vector2f(wallSprite.getPosition().x - 80, wallSprite.getPosition().y + 43));
//    }
//    wallSprite.setPosition(8000, 4000);
}


