
#ifndef WAVEINTERFERENCE_QUADRENDERER_H
#define WAVEINTERFERENCE_QUADRENDERER_H

#include <vector>

#include "../Model.h"
#include "../Shaders/BasicShader.h"
#include "../Texture/BasicTexture.h"
#include "../Maths/glm.h"

class Camera;

class QuadRenderer
{
public:
    QuadRenderer();

    void add(const glm::vec3& position);

    void renderQuads(const Camera& camera);

private:
    std::vector<glm::vec3> m_quads;

    Model m_quadModel;
    BasicShader m_shader;
    BasicTexture m_basicTexture;
};


#endif //WAVEINTERFERENCE_QUADRENDERER_H
