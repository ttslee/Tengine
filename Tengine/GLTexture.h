#pragma once
#ifndef GLTEXTURE_H
#define GLTEXTURE_H
#include <GL\glew.h>
namespace Tengine{
	struct GLTexture {
		GLuint id;
		int width;
		int height;
	};
}
#endif
