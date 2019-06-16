
#ifndef WAVEINTERFERENCE_SHADER_H
#define WAVEINTERFERENCE_SHADER_H
#include <string>

#include "../Context.h"
#include "../Util/Unique.h"
#include "../Maths/glm.h"

class Shader : Unique
{
public:
    Shader(const std::string& vertexFile, const std::string& fragmentFile);
    ~Shader();

    void useProgram() const;

    void loadInt(GLuint location,   int value);
    void loadFloat(GLuint location, int value);

    void loadVector2(GLuint location, const glm::vec2& vect);
    void loadVector3(GLuint location, const glm::vec3& vect);
    void loadVector4(GLuint location, const glm::vec4& vect);

    void loadMatrix4(GLuint location, const glm::mat4& matrix);

protected:
    virtual void getUniforms() = 0;
    GLuint m_id;
};


#endif //WAVEINTERFERENCE_SHADER_H
