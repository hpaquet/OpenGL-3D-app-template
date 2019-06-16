
#ifndef WAVEINTERFERENCE_BASICTEXTURE_H
#define WAVEINTERFERENCE_BASICTEXTURE_H

#include "../Context.h"
#include <string>
#include "../Util/Unique.h"


class BasicTexture
{
public:
    BasicTexture() = default;

    BasicTexture(const std::string& file);

    ~BasicTexture();

    void loadFromFile (const std::string& file);

    void bindTexture() const;


private:
    GLuint m_id;
    std::string m_FilePath;
    unsigned char* m_LocalBuffer;
    int m_Width, m_Height, m_BPP;
};


#endif //WAVEINTERFERENCE_BASICTEXTURE_H
