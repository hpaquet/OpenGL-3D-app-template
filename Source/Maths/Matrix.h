
#ifndef WAVEINTERFERENCE_MATRIX_H
#define WAVEINTERFERENCE_MATRIX_H

#include "glm.h"

class Camera;
class Entity;

glm::mat4 makeModelMatrix       (const Entity& entity);
glm::mat4 makeViewMatrix        (const Camera& camera);
glm::mat4 makeProjectionMatrix  (float fov);


#endif //WAVEINTERFERENCE_MATRIX_H
