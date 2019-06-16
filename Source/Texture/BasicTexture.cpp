
#include "BasicTexture.h"
#include <iostream>

#include "../stb_image/stb_image.h"


BasicTexture::BasicTexture(const std::string& file) : m_id(0), m_FilePath(file), m_LocalBuffer(nullptr), m_Width(0), m_Height(0), m_BPP(0)
{
    loadFromFile(file);
}

void BasicTexture::loadFromFile(const std::string& file)
{
    stbi_set_flip_vertically_on_load(1);
    std::string path = "../Texture/" + file + ".jpg";
    m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);


    if(!m_LocalBuffer)
    {
        ///@TODO Throw error
    }

    GLCall(glGenTextures(1, &m_id));
    GLCall(glBindTexture(GL_TEXTURE_2D, m_id));

    GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

    if (m_LocalBuffer){
        stbi_image_free(m_LocalBuffer);
    }
}

BasicTexture::~BasicTexture()
{
    GLCall(glDeleteTextures(1, &m_id));
}

void BasicTexture::bindTexture() const
{
    GLCall(glBindTexture(GL_TEXTURE_2D, m_id));
}

