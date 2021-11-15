#include "mesh.h"

Mesh::Mesh(int indice)
{
    switch(indice){
    case 1 :
        this->vertexNumber = 4;
        this->indexCount = 6;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( 2.0f, 0.0f, -20.0f), QVector2D(1.0f, 0.0f)};
        vertices[1] =   {QVector3D( 2.0f, 4.0f, -20.0f), QVector2D(0.0f, 0.0f)};
        vertices[2] =   {QVector3D( 2.0f, 4.0f, 0.0f), QVector2D(0.0f, 1.0f)};
        vertices[3] =   {QVector3D( 2.0f, 0.0f, 0.0f), QVector2D(1.0f, 1.0f)};

        this->indices = new GLushort[this->indexCount];

        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;
        indices[3] = 0;
        indices[4] = 3;
        indices[5] = 2;
        break;
    case 2 :
        this->vertexNumber = 4;
        this->indexCount = 6;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -2.0f, 0.0f, -20.0f), QVector2D(0.0f, 0.0f)};
        vertices[1] =   {QVector3D( -2.0f, 4.0f, -20.0f), QVector2D(0.0f, 1.0f)};
        vertices[2] =   {QVector3D( -2.0f, 4.0f, 0.0f), QVector2D(1.0f, 1.0f)};
        vertices[3] =   {QVector3D( -2.0f, 0.0f, 0.0f), QVector2D(1.0f, 0.0f)};


        this->indices = new GLushort[this->indexCount];

        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;
        indices[3] = 0;
        indices[4] = 3;
        indices[5] = 2;
        break;
    case 3 :
        this->vertexNumber = 4;
        this->indexCount = 6;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -2.0f, 4.0f, 0.0f), QVector2D(0.0f, 0.0f)};
        vertices[1] =   {QVector3D( -2.0f, 4.0f, -20.0f), QVector2D(1.0f, 0.0f)};
        vertices[2] =   {QVector3D( 2.0f, 4.0f, -20.0f), QVector2D(1.0f, 0.0f)};
        vertices[3] =   {QVector3D( 2.0f, 4.0f, 0.0f), QVector2D(0.0f, 0.0f)};



        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 0;
        indices[4] = 2;
        indices[5] = 3;
        break;
    case 4 :
        this->vertexNumber = 4;
        this->indexCount = 6;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -2.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)};
        vertices[1] =   {QVector3D( -2.0f, 0.0f, -20.0f), QVector2D(1.0f, 0.0f)};
        vertices[2] =   {QVector3D( 2.0f, 0.0f, -20.0f), QVector2D(1.0f, 0.0f)};
        vertices[3] =   {QVector3D( 2.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)};


        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 0;
        indices[4] = 2;
        indices[5] = 3;
        break;
    default:
        break;
    }
}

Mesh::Mesh(){}

Mesh::~Mesh(){}
