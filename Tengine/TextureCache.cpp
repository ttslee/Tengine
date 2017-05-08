#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
namespace Tengine{
	TextureCache::TextureCache()
	{
	}

	TextureCache::~TextureCache()
	{
	}

	GLTexture TextureCache::getTexture(std::string texturePath) {
		//lookup the texture and see if its in the map
		auto mit = _textureMap.find(texturePath);

		//check if you found it
		if (mit == _textureMap.end())
		{
			GLTexture newTexture = ImageLoader::loadPNG(texturePath);
			std::cout << "loading texture" << std::endl;
			std::pair<std::string, GLTexture> newPair(texturePath, newTexture);

			_textureMap.insert(make_pair(texturePath, newTexture));

			return newTexture;
		}
		return mit->second;
	}
}