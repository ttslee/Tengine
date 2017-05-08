#pragma once
#include <GL\glew.h>
#include "Errors.h"
#include <fstream>
#include <vector>
namespace Tengine{
	class GLSLProgram
	{
	public:
		GLSLProgram();
		~GLSLProgram();

		void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);

		void linkShaders();

		void addAttribute(const std::string& attributeName);

		GLint getUniformLocation(const std::string& uniformName);

		void use();

		void unuse();
	private:
		int _numAttr;
		void compileShader(const std::string& filePath, GLuint shaderID);
		GLuint _programID;
		GLuint _vertexShaderID;
		GLuint _fragmentShaderID;

	};

}