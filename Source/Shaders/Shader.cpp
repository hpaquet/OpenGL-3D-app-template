
#include "Shader.h"

#include "ShaderLoader.h"
#include <iostream>

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
        :   m_id(loadShaders(vertexFile, fragmentFile))
{
    useProgram();
}


void Shader::loadInt(GLuint location, int value)
{
    GLCall(glUniform1i(location, value));
}

void Shader::loadFloat(GLuint location, int value)
{
    GLCall(glUniform1f(location, value));
}

void Shader::loadVector2(GLuint location, const glm::vec2& vect)
{
    GLCall(glUniform2f(location, vect.x, vect.y));
}

void Shader::loadVector3(GLuint location, const glm::vec3& vect)
{
    GLCall(glUniform3f(location, vect.x, vect.y, vect.z));
}

void Shader::loadVector4(GLuint location, const glm::vec4& vect)
{
    GLCall(glUniform4f(location, vect.x, vect.y, vect.z, vect.w));
}

void Shader::loadMatrix4(GLuint location, const glm::mat4& matrix)
{
    GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix)));
}

Shader::~Shader()
{
    GLCall(glDeleteProgram(m_id));
}

void Shader::useProgram() const
{
    GLCall(glUseProgram(m_id));
}