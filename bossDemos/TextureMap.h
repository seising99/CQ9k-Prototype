#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string.h>

#define TEXTURES TextureMap::instance()->Get

/*
*	TextureMap: A Singleton Global Wrapper for a std::map to hold sf::Textures
*	-- Prevents textures and names in map from being modified
*	-- Returns const &'s to textures which are used in sprites
*	-- #define used to simplify Get() function
*/

class TextureMap
{

private:

	TextureMap();
	~TextureMap();

	static TextureMap* singleton;

	std::map<const std::string, const sf::Texture*> map;

public:

	const sf::Texture& Get(const std::string str);

	void EmplaceTextures();

	//Lazy instantiation of singleton
	static TextureMap* instance()
	{
		if (!singleton)
			singleton = new TextureMap;
		return singleton;
	}

};