#ifndef OBJECTCONSTRUCTOR_H
#define OBJECTCONSTRUCTOR_H

#include <SFML/Graphics.hpp>
#include "object.h"
#include "iostream"

class ObjectConstructor
{

public:

    ObjectConstructor(std::vector<Object*> *obj);

    void drawWall(sf::Vector2f begin, int countOfSegments, sf::Vector2f dir);


private:

    std::vector<Object*> *objects;
};
#endif // OBJECTCONSTRUCTOR_H
