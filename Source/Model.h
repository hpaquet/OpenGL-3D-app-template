
#ifndef WAVEINTERFERENCE_MODEL_H
#define WAVEINTERFERENCE_MODEL_H

#include "Context.h"
#include <vector>

#include "Util/Unique.h"


class Model : public Unique
{
public:
    Model() = default;
    Model(const std::vector<GLfloat>& vertexPositions,
          const std::vector<GLfloat>& textureCoords,
          const std::vector<GLuint>&  indices);
    ~Model();

    void addData(const std::vector<GLfloat>& vertexPositions,
                 const std::vector<GLfloat>& textureCoords,
                 const std::vector<GLuint>&  indices);

    void deleteData();

    void addVBO(int dimensions, const std::vector<GLfloat>& data);
    void bindVAO() const;

    int getIndicesCount() const;

private:
    void addEBO(const std::vector<GLuint>& indices);

    GLuint m_vao = 0;
    int m_vboCount = 0;
    int m_indicesCount = 0;
    std::vector<GLuint> m_buffers;
};


#endif //WAVEINTERFERENCE_MODEL_H
