#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "resourceholder.hpp"

extern ResourceHolder <sf::Texture, Textures::ID_InMenu> textureHolderMenu;
extern ResourceHolder <sf::Font, Fonts::ID_InMenu> fontHolderMenu;
extern ResourceHolder <sf::SoundBuffer, Sounds::ID_InMenu> soundsHolderMenu;

extern ResourceHolder <sf::Texture, Textures::ID_InGame> textureHolder;
extern ResourceHolder <sf::Font, Fonts::ID_InGame> fontHolder;
extern ResourceHolder <sf::SoundBuffer, Sounds::ID_InGame> soundsHolder;

class ResourceManager{
public:
    void load();
};

#endif // RESOURCEMANAGER_H
