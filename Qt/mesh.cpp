#include "mesh.h"

Mesh::Mesh(int indice)
{
    switch(indice){
    case 0 :
        this->vertexNumber = 0;
        this->indexCount = 0;

        this->vertices = new VertexData[this->vertexNumber];
        this->indices = new GLushort[this->indexCount];

        break;
    case 1 :
        this->vertexNumber = 12;
        this->indexCount = 18;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( 4.0f, 0.0f, -20.0f), QVector2D(1.0f, 1.0f)};
        vertices[1] =   {QVector3D( 4.0f, 6.0f, -20.0f), QVector2D(1.0f, 1.0f)};
        vertices[2] =   {QVector3D( 4.0f, 6.0f, 0.0f), QVector2D(1.0f, 1.0f)};
        vertices[3] =   {QVector3D( 4.0f, 0.0f, 0.0f), QVector2D(1.0f, 1.0f)};

        vertices[4] =   {QVector3D( -4.0f, 6.0f, 0.0f), QVector2D(0.0f, 1.0f)};
        vertices[5] =   {QVector3D( -4.0f, 6.0f, -20.0f), QVector2D(0.0f, 1.0f)};
        vertices[6] =   {QVector3D( 4.0f, 6.0f, -20.0f), QVector2D(0.0f, 1.0f)};
        vertices[7] =   {QVector3D( 4.0f, 6.0f, 0.0f), QVector2D(0.0f, 1.0f)};

        vertices[8] =   {QVector3D( -4.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)};
        vertices[9] =   {QVector3D( -4.0f, 0.0f, -20.0f), QVector2D(0.0f, 0.0f)};
        vertices[10] =   {QVector3D( 4.0f, 0.0f, -20.0f), QVector2D(0.0f, 0.0f)};
        vertices[11] =   {QVector3D( 4.0f, 0.0f, 0.0f), QVector2D(0.0f, 0.0f)};


        this->indices = new GLushort[this->indexCount];

        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;
        indices[3] = 0;
        indices[4] = 3;
        indices[5] = 2;

        indices[6] = 4;
        indices[7] = 5;
        indices[8] = 6;
        indices[9] = 4;
        indices[10] = 6;
        indices[11] = 7;

        indices[12] = 8;
        indices[13] = 9;
        indices[14] = 10;
        indices[15] = 8;
        indices[16] = 10;
        indices[17] = 11;
        break;
    case 2 :
        this->vertexNumber = 12;
        this->indexCount = 18;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -20.0f, 0.0f, -28.0f), QVector2D(0.5f, 0.5f)};
        vertices[1] =   {QVector3D( -20.0f, 6.0f, -28.0f), QVector2D(0.5f, 0.5f)};
        vertices[2] =   {QVector3D( 0.0f, 6.0f, -28.0f), QVector2D(0.5f, 0.5f)};
        vertices[3] =   {QVector3D( 0.0f, 0.0f, -28.0f), QVector2D(0.5f, 0.5f)};

        vertices[4] =   {QVector3D( 0.0f, 6.0f, -28.0f), QVector2D(0.0f, 0.5f)};
        vertices[5] =   {QVector3D( -20.0f, 6.0f, -28.0f), QVector2D(0.0f, 0.5f)};
        vertices[6] =   {QVector3D( -20.0f, 6.0f, -20.0f), QVector2D(0.0f, 0.5f)};
        vertices[7] =   {QVector3D( 0.0f, 6.0f, -20.0f), QVector2D(0.0f, 0.5f)};

        vertices[8] =   {QVector3D( 0.0f, 0.0f, -28.0f), QVector2D(0.0f, 0.0f)};
        vertices[9] =   {QVector3D( -20.0f, 0.0f, -28.0f), QVector2D(0.0f, 0.0f)};
        vertices[10] =   {QVector3D( -20.0f, 0.0f, -20.0f), QVector2D(0.0f, 0.0f)};
        vertices[11] =   {QVector3D( 0.0f, 0.0f, -20.0f), QVector2D(0.0f, 0.0f)};


        this->indices = new GLushort[this->indexCount];

        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;
        indices[3] = 0;
        indices[4] = 3;
        indices[5] = 2;

        indices[6] = 4;
        indices[7] = 5;
        indices[8] = 6;
        indices[9] = 4;
        indices[10] = 6;
        indices[11] = 7;

        indices[12] = 8;
        indices[13] = 9;
        indices[14] = 10;
        indices[15] = 8;
        indices[16] = 10;
        indices[17] = 11;
        break;
    case 3 :
        this->vertexNumber = 4;
        this->indexCount = 6;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -4.0f, 0.0f, -20.0f), QVector2D(1.0f, 0.0f)};
        vertices[1] =   {QVector3D( -4.0f, 6.0f, -20.0f), QVector2D(1.0f, 0.0f)};
        vertices[2] =   {QVector3D( -4.0f, 6.0f, 0.0f), QVector2D(1.0f, 0.0f)};
        vertices[3] =   {QVector3D( -4.0f, 0.0f, 0.0f), QVector2D(1.0f, 0.0f)};

        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;
        indices[3] = 0;
        indices[4] = 3;
        indices[5] = 2;
        break;
    case 4 :
        this->vertexNumber = 4;
        this->indexCount = 6;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -20.0f, 0.0f, -20.0f), QVector2D(0.5f, 0.0f)};
        vertices[1] =   {QVector3D( -20.0f, 6.0f, -20.0f), QVector2D(0.5f, 0.0f)};
        vertices[2] =   {QVector3D( -4.0f, 6.0f, -20.0f), QVector2D(0.5f, 0.0f)};
        vertices[3] =   {QVector3D( -4.0f, 0.0f, -20.0f), QVector2D(0.5f, 0.0f)};

        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 2;
        indices[2] = 1;
        indices[3] = 0;
        indices[4] = 3;
        indices[5] = 2;
        break;
    default:
        break;
    }
}

Mesh::Mesh(){}

Mesh::~Mesh(){}
