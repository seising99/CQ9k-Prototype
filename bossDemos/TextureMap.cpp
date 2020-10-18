#include <SFML/Graphics.hpp>
#include "TextureMap.h"
#include <map>
#include <string>

//Default Constructor -- Upon initialization, emplaces all textures into map.
TextureMap::TextureMap()
{
	EmplaceTextures();
}

//Destructor -- Upon deletion, deletes all allocated texture pointers
TextureMap::~TextureMap()
{

	for (std::map<const std::string, const sf::Texture*>::iterator i = map.begin(); i != map.end(); i++)
		delete i->second;

	delete singleton;

}

//Get Texture -- returns const & from map (address of dereferenced pointer)
const sf::Texture& TextureMap::Get(const std::string str)
{
	return *map[str];
}


//Emplace Textures -- Adds all textures to std::map
void TextureMap::EmplaceTextures()
{

	sf::Texture* tMouse = new sf::Texture();
	tMouse->loadFromFile("sprites/sMouse.png");
	map.emplace("mouse", tMouse);

	sf::Texture* tBullet = new sf::Texture();
	tBullet->loadFromFile("sprites/sBullet.png");
	map.emplace("bullet", tBullet);

	sf::Texture* tRocket = new sf::Texture();
	tRocket->loadFromFile("sprites/sRocket.png");
	map.emplace("rocket", tRocket);

	sf::Texture* tParasite = new sf::Texture();
	tParasite->loadFromFile("sprites/sParasite.png");
	map.emplace("parasite", tParasite);

	sf::Texture* tMenu = new sf::Texture();
	tMenu->loadFromFile("sprites/cq9k_menu.png");
	map.emplace("menu", tMenu);

	sf::Texture* tToaster = new sf::Texture();
	tToaster->loadFromFile("sprites/sToaster.png");
	map.emplace("toaster", tToaster);

	sf::Texture* tCD = new sf::Texture();
	tCD->loadFromFile("sprites/cd_rom.png");
	map.emplace("cd", tCD);

}