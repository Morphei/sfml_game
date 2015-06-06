#include "entityconfigurator.h"
#include "entity.h"

EntityConfigurator::EntityConfigurator()
{
}

void EntityConfigurator::init(EntityState::typeOfEntity type, Entity *target)
{

    switch (type) {
    case EntityState::Amazon:
    {
        //Run - 88x82
        //Normal - 76x80
        //Attack - 85x105

        std::cout << "Init amazon: " << "\n";
            target->setTexture(Textures::Amazon, sf::Vector2i(76,80), sf::Vector2i(85,105), sf::Vector2i(88,82));
            std::cout << "setTexture\n";
            target->setState(EntityState::Normal, EntityState::direction::DownLeftDown);
            std::cout << "setState\n";
            target->setSpeed(200);
//            target->setPosition(200,200);
            std::cout << "Exit init EntityConfig\n";

    }
        break;

    case EntityState::EagleRat:

        break;

    case EntityState::Paladin:
    {
        //62x80 - Normal
        //168x116 - Attack
        //94x103 - Run
        target->setTexture(Textures::Paladin, sf::Vector2i(62,80), sf::Vector2i(168,116), sf::Vector2i(94,103));
        target->setState(EntityState::Normal, EntityState::DownLeftDown);
        target->setSpeed(200);
//        target->setPosition(200,200);

    }
        break;

    case EntityState::Sorcerer:

        break;
    }


}
