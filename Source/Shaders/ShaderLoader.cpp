
#include "ShaderLoader.h"
#include <stdexcept>
#include <iostream>
#include "../Util/FileUtil.h"


namespace
{
    GLuint compileShader(const GLchar* source, GLenum shaderType)
    {
        GLCall(GLuint shaderID = glCreateShader(shaderType));
        GLCall(glShaderSource(shaderID, 1, &source, nullptr));
        GLCall(glCompileShader(shaderID));
        GLint isSuccess = 0;
        GLchar infoLog[512];

        GLCall(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isSuccess));
        if(!isSuccess)
        {
            GLCall(glGetShaderInfoLog(shaderID, 512, nullptr, infoLog));
            throw std::runtime_error ("Unable to load a shader: " + std::string(infoLog));
        }

        return shaderID;
    }

    GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
    {
        GLCall(auto id = glCreateProgram());

        GLCall(glAttachShader(id, vertexShaderID));
        GLCall(glAttachShader(id, fragmentShaderID));

        GLCall(glLinkProgram(id));

        return id;
    }
}

GLuint loadShaders(const std::string& vertexShader, const std::string& fragmentShader)
{
    auto vertexSource   = getFileContents("../Shaders/" + vertexShader     + ".glsl");
    auto fragmentSource = getFileContents("../Shaders/" + fragmentShader   + ".glsl");

    auto vertexShaderID     = compileShader(vertexSource.c_str(),   GL_VERTEX_SHADER);
    auto fragmentShaderID   = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

    auto shaderID = linkProgram(vertexShaderID, fragmentShaderID);

    GLCall(glDeleteShader(vertexShaderID));
    GLCall(glDeleteShader(fragmentShaderID));

    return shaderID;

}
