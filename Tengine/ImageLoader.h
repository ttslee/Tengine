
#include "GLTexture.h"
#include "GL/glew.h"
#include <string>
#include <vector>
//#include "SOIL\src\SOIL.h"
namespace Tengine{
	class ImageLoader
	{
	public:
		static GLTexture loadPNG(std::string filePath);
	};

}