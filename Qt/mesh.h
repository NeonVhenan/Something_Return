#ifndef MESH_H
#define MESH_H


#include <QOpenGLFunctions_3_1>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QVector3D>
#include <QVector2D>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
};

class Mesh
{
public:
    Mesh();
    Mesh(int type);
    ~Mesh();
    void transform(QMatrix4x4 mat);

    unsigned int vertexNumber;
    VertexData *vertices;
    unsigned int indexCount;
    GLushort *indices;
    int TextN;
};

#endif // MESH_H
