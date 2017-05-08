#include "ResourceManager.h"

namespace Tengine{
	GLTexture ResourceManager::getTexture(std::string texturePath) {
		return _textureCache.getTexture(texturePath);
	}

	TextureCache ResourceManager::_textureCache;


	GLuint ResourceManager::boundTexture;
}