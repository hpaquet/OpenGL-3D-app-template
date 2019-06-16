
#include "Model.h"


Model::Model(const std::vector<GLfloat>& vertexPositions,
             const std::vector<GLfloat>& textureCoords,
             const std::vector<GLuint>&  indices)
{
    addData(vertexPositions, textureCoords, indices);
}

Model::~Model()
{
    deleteData();
}

void Model::bindVAO() const
{
    GLCall(glBindVertexArray(m_vao));
}

void Model::addData(const std::vector<GLfloat>& vertexPositions,
                    const std::vector<GLfloat>& textureCoords,
                    const std::vector<GLuint>&  indices)
{
    if (m_vao != 0)
        deleteData();

    m_indicesCount = indices.size();

    GLCall(glGenVertexArrays(1, &m_vao));
    GLCall(glBindVertexArray(m_vao));

    addVBO(3, vertexPositions);
    addVBO(2, textureCoords);
    addEBO(indices);
}

void Model::addVBO(int dimensions, const std::vector<GLfloat>& data)
{
    GLuint vbo;
    GLCall(glGenBuffers(1, &vbo));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, vbo));
    GLCall(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), GL_STATIC_DRAW));

    GLCall(glVertexAttribPointer(m_vboCount, dimensions, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0));

    GLCall(glEnableVertexAttribArray(m_vboCount++));

    m_buffers.push_back(vbo);
}

void Model::addEBO(const std::vector<GLuint>& indices)
{
    GLuint ebo;
    GLCall(glGenBuffers(1, &ebo));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW));
}

void Model::deleteData()
{
    GLCall(glDeleteVertexArrays(1, &m_vao));
    GLCall(glDeleteBuffers(m_buffers.size(), m_buffers.data()));

    m_buffers.clear();

    m_vboCount      = 0;
    m_vao           = 0;
    m_indicesCount  = 0;
}

int Model::getIndicesCount() const
{
    return m_indicesCount;
}