#pragma once
#include <vector>
#include <string>
#include <fstream>
namespace Tengine{
	class IOManager
	{
	public:
		static bool readFileToBuffer(std::vector<unsigned char>& buffer, std::string filePath);
	};

}