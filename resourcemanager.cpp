#include "resourcemanager.h"

ResourceHolder <sf::Texture, Textures::ID_InMenu> textureHolderMenu;
ResourceHolder <sf::Font, Fonts::ID_InMenu> fontHolderMenu;
ResourceHolder <sf::SoundBuffer, Sounds::ID_InMenu> soundsHolderMenu;


ResourceHolder <sf::Texture, Textures::ID_InGame> textureHolder;
ResourceHolder <sf::Font, Fonts::ID_InGame> fontHolder;
ResourceHolder <sf::SoundBuffer, Sounds::ID_InGame> soundsHolder;

void ResourceManager::load(){

textureHolder.load(Textures::Amazon, "AmazonTexture.png");
textureHolder.load(Textures::Paladin, "PaladinTexture.png");
textureHolder.load(Textures::Landscape, "map2.png");
textureHolder.load(Textures::Wall, "wall.png");

fontHolder.load(Fonts::MainFontGame, "MainFont.ttf");

textureHolderMenu.load(Textures::Button, "ButtonNormal.png");
textureHolderMenu.load(Textures::ButtonPressed, "ButtonPressed.png");
textureHolderMenu.load(Textures::LoginForm, "LoginForm.png");
textureHolderMenu.load(Textures::ChooseForm, "CharsForm2.png");
textureHolderMenu.load(Textures::RegisterForm, "RegisterForm.png");
textureHolderMenu.load(Textures::MenuBackground, "MenuBackground.png");
textureHolderMenu.load(Textures::LoginButton, "LoginButtonNormal.png");
textureHolderMenu.load(Textures::LoginButtonPressed, "LoginButtonPressed.png");
textureHolderMenu.load(Textures::RegisterButton, "RegisterButtonNormal.png");
textureHolderMenu.load(Textures::RegisterButtonPressed, "RegisterButtonPressed.png");
textureHolderMenu.load(Textures::ExitButton, "exit.bmp");
textureHolderMenu.load(Textures::ExitButtonPressed, "exit.bmp");
textureHolderMenu.load(Textures::CloseButton, "CloseButton.png");
textureHolderMenu.load(Textures::CloseButtonPressed, "CloseButtonPressed.png");
textureHolderMenu.load(Textures::TextBox, "TextBox2.png");

fontHolderMenu.load(Fonts::MainFontMenu, "MainFont.ttf");

}


