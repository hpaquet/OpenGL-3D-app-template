

#ifndef WAVEINTERFERENCE_RENDERMASTER_H
#define WAVEINTERFERENCE_RENDERMASTER_H

#include <GL/glew.h>

#include "QuadRenderer.h"


class Camera;

class RenderMaster
{
public:

    void drawQuad(const glm::vec3& pos);

    void finishRender(const Camera& camera);

private:
    QuadRenderer m_quadRenderer;
};


#endif //WAVEINTERFERENCE_RENDERMASTER_H
