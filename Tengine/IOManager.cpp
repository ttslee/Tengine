#include "IOManager.h"
namespace Tengine{
	bool IOManager::readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath) {
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail())
		{
			perror(filePath.c_str());
			return false;
		}
		//seek to end opf file
		file.seekg(0, std::ios::end);

		//return amount of bytes passed in file
		int fileSize = file.tellg();

		//seek back to beginning of file
		file.seekg(0, std::ios::beg);

		//Reduce size of file by any header
		fileSize -= file.tellg();

		buffer.resize(fileSize);

		file.read((char*)&buffer[0], fileSize);

		file.close();

		return true;
	}
}