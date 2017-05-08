#pragma once
#include <GL\glew.h>
#include "Vertex.h"
#include <cstddef>
#include <iostream>
#include "GLTexture.h"
#include "ResourceManager.h"
#include <string>
namespace Tengine{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		void init(float x, float y, float width, float height, std::string texturePath);

		void draw();


	private:
		float _x;
		float _y;
		float _witdth;
		float _height;
		GLuint _vboID;
		GLTexture _texture;

	};

}