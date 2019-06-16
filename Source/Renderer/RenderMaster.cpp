
#include "RenderMaster.h"

void RenderMaster::drawQuad(const glm::vec3& pos)
{
    m_quadRenderer.add(pos);
}

void RenderMaster::finishRender(const Camera& camera)
{
    GLCall(glClearColor(0.1, 0.5, 1.0, 1.0));
    GLCall(glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));
    m_quadRenderer.renderQuads(camera);

}

