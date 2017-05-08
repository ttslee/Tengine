#include "ImageLoader.h"
#include "PicoPNG.h"
#include "IOManager.h"
#include "Errors.h"
namespace Tengine{
	GLTexture ImageLoader::loadPNG(std::string filePath) {
		GLTexture texture = {};

		std::vector<unsigned char> in;

		std::vector<unsigned char> out;

		if (IOManager::readFileToBuffer(in, filePath) == false)
		{
			fatalError("Failed to load PNG file to buffer!");
		}

		unsigned long width, height;
		int errorCode = decodePNG(out, width, height, &in[0], in.size());
		if (errorCode != 0)
		{
			fatalError("decode PNG failed with error: " + std::to_string(errorCode));
		}

		glGenTextures(1, &texture.id);
		glBindTexture(GL_TEXTURE_2D, texture.id); // select our current texture
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &out[0]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

		texture.width = width;
		texture.height = height;
		return texture;
	}



	//GLuint ImageLoader::loadPNG(std::string& filePath, int width, int height) {
	//	GLuint texture = SOIL_load_OGL_texture
	//		(
	//		filePath.c_str(),
	//		SOIL_LOAD_AUTO,
	//		SOIL_CREATE_NEW_ID,
	//		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	//		);
	//
	//	/* check for an error during the load process */
	//	if (0 == texture)
	//	{
	//		printf("SOIL loading error: '%s'\n", SOIL_last_result());
	//	}
	//
	//glBindTexture(GL_TEXTURE_2D, texture); // select our current texture
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);  // when texture area is small, bilinear filter the closest mipmap
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // when texture area is large, bilinear filter the first mipmap
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  // texture should tile
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data); // build our texture mipmaps

	//free(data);  // free buffer
	//
	//	return texture;
	//}
}