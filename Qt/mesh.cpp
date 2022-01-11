#include "mesh.h"

Mesh::Mesh(int indice)
{
    switch(indice) {

    case 0 :
        this->vertexNumber = 0;
        this->indexCount = 0;

        this->vertices = new VertexData[this->vertexNumber];
        this->indices = new GLushort[this->indexCount];

        this -> TextN=0;
        break;

  

    default:
        break;
    }
}

Mesh::Mesh(){}

Mesh::~Mesh(){}

void Mesh::transform(QMatrix4x4 mat){
    QVector4D p;
    for(unsigned int i = 0; i < vertexNumber;i++){
        QVector4D p = QVector4D(vertices[i].position[0], vertices[i].position[1], vertices[i].position[2], 1.0);
        p = mat * p;
        vertices[i].position = QVector3D(p.x(), p.y(), p.z());
    }
}
