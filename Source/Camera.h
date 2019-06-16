
#ifndef WAVEINTERFERENCE_CAMERA_H
#define WAVEINTERFERENCE_CAMERA_H

#include "Maths/glm.h"
#include "Util/Entity.h"

class Camera : public Entity
{
public:
    Camera();

    void update();
    void hookEntity(const Entity& entity);

    const glm::mat4& getViewMatrix ()           const noexcept;
    const glm::mat4& getProjMatrix ()           const noexcept;
    const glm::mat4& getProjectionViewMatrix () const noexcept;

private:
    const Entity* m_pEntity;

    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
    glm::mat4 m_projViewMatrx;


};


#endif //WAVEINTERFERENCE_CAMERA_H
