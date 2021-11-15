#include "mesh.h"

Mesh::Mesh(int indice)
{
    int nH, nW, k, c;
    float dim, pas;
    switch(indice){
    case 1:
        this->vertexNumber = 8;
        this->indexCount = 36;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( 1.0f, 0.0f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[1] =   {QVector3D( 1.0f, 2.0f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[2] =   {QVector3D( 1.0f, 2.0f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[3] =   {QVector3D( 1.0f, 0.0f, 20.0f), QVector2D(1.0f, 0.0f)};

        vertices[4] =   {QVector3D( 1.5f, 0.0f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[5] =   {QVector3D( 1.5f, 2.0f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[6] =   {QVector3D( 1.5f, 2.0f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[7] =   {QVector3D( 1.5f, 0.0f, 20.0f), QVector2D(1.0f, 0.0f)};



        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 0;
        indices[4] = 2;
        indices[5] = 3;
        indices[6] = 3;
        indices[7] = 2;
        indices[8] = 6;
        indices[9] = 3;
        indices[10] = 6;
        indices[11] = 7;
        indices[12] = 7;
        indices[13] = 6;
        indices[14] = 5;
        indices[15] = 7;
        indices[16] = 5;
        indices[17] = 8;
        indices[18] = 8;
        indices[19] = 7;
        indices[20] = 4;
        indices[21] = 4;
        indices[22] = 3;
        indices[23] = 7;
        indices[24] = 1;
        indices[25] = 2;
        indices[26] = 6;
        indices[27] = 1;
        indices[28] = 6;
        indices[29] = 5;
        indices[30] = 1;
        indices[31] = 4;
        indices[32] = 5;
        indices[33] = 4;
        indices[34] = 5;
        indices[35] = 8;
        break;
    case 2:
        this->vertexNumber = 8;
        this->indexCount = 36;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -1.0f, 0.0f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[1] =   {QVector3D( -1.0f, 2.0f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[2] =   {QVector3D( -1.0f, 2.0f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[3] =   {QVector3D( -1.0f, 0.0f, 20.0f), QVector2D(1.0f, 0.0f)};

        vertices[4] =   {QVector3D( -1.5f, 0.0f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[5] =   {QVector3D( -1.5f, 2.0f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[6] =   {QVector3D( -1.5f, 2.0f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[7] =   {QVector3D( -1.5f, 0.0f, 20.0f), QVector2D(1.0f, 0.0f)};



        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 0;
        indices[4] = 2;
        indices[5] = 3;
        indices[6] = 3;
        indices[7] = 2;
        indices[8] = 6;
        indices[9] = 3;
        indices[10] = 6;
        indices[11] = 7;
        indices[12] = 7;
        indices[13] = 6;
        indices[14] = 5;
        indices[15] = 7;
        indices[16] = 5;
        indices[17] = 8;
        indices[18] = 8;
        indices[19] = 7;
        indices[20] = 4;
        indices[21] = 4;
        indices[22] = 3;
        indices[23] = 7;
        indices[24] = 1;
        indices[25] = 2;
        indices[26] = 6;
        indices[27] = 1;
        indices[28] = 6;
        indices[29] = 5;
        indices[30] = 1;
        indices[31] = 4;
        indices[32] = 5;
        indices[33] = 4;
        indices[34] = 5;
        indices[35] = 8;

    case 3 :
        this->vertexNumber = 8;
        this->indexCount = 36;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -1.5f, 2.0f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[1] =   {QVector3D( -1.5f, 2.0f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[2] =   {QVector3D( 1.5f, 2.0f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[3] =   {QVector3D( 1.5f, 2.0f, 20.0f), QVector2D(1.0f, 0.0f)};

        vertices[4] =   {QVector3D( -1.5f, 2.5f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[5] =   {QVector3D( -1.5f, 2.5f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[6] =   {QVector3D( 1.5f, 2.5f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[7] =   {QVector3D( 1.5f, 0.5f, 20.0f), QVector2D(1.0f, 0.0f)};



        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 0;
        indices[4] = 2;
        indices[5] = 3;
        indices[6] = 3;
        indices[7] = 2;
        indices[8] = 6;
        indices[9] = 3;
        indices[10] = 6;
        indices[11] = 7;
        indices[12] = 7;
        indices[13] = 6;
        indices[14] = 5;
        indices[15] = 7;
        indices[16] = 5;
        indices[17] = 8;
        indices[18] = 8;
        indices[19] = 7;
        indices[20] = 4;
        indices[21] = 4;
        indices[22] = 3;
        indices[23] = 7;
        indices[24] = 1;
        indices[25] = 2;
        indices[26] = 6;
        indices[27] = 1;
        indices[28] = 6;
        indices[29] = 5;
        indices[30] = 1;
        indices[31] = 4;
        indices[32] = 5;
        indices[33] = 4;
        indices[34] = 5;
        indices[35] = 8;
        break;
    case 4 :
        this->vertexNumber = 8;
        this->indexCount = 36;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] =   {QVector3D( -1.5f, 0.0f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[1] =   {QVector3D( -1.5f, 0.0f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[2] =   {QVector3D( 1.5f, 0.0f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[3] =   {QVector3D( 1.5f, 0.0f, 20.0f), QVector2D(1.0f, 0.0f)};

        vertices[4] =   {QVector3D( -1.5f, -0.5f, -5.0f), QVector2D(0.0f, 0.0f)};
        vertices[5] =   {QVector3D( -1.5f, -0.5f, -5.0f), QVector2D(0.0f, 1.0f)};
        vertices[6] =   {QVector3D( 1.5f, -0.5f, 20.0f), QVector2D(1.0f, 1.0f)};
        vertices[7] =   {QVector3D( 1.5f, -0.5f, 20.0f), QVector2D(1.0f, 0.0f)};



        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 0;
        indices[4] = 2;
        indices[5] = 3;
        indices[6] = 3;
        indices[7] = 2;
        indices[8] = 6;
        indices[9] = 3;
        indices[10] = 6;
        indices[11] = 7;
        indices[12] = 7;
        indices[13] = 6;
        indices[14] = 5;
        indices[15] = 7;
        indices[16] = 5;
        indices[17] = 8;
        indices[18] = 8;
        indices[19] = 7;
        indices[20] = 4;
        indices[21] = 4;
        indices[22] = 3;
        indices[23] = 7;
        indices[24] = 1;
        indices[25] = 2;
        indices[26] = 6;
        indices[27] = 1;
        indices[28] = 6;
        indices[29] = 5;
        indices[30] = 1;
        indices[31] = 4;
        indices[32] = 5;
        indices[33] = 4;
        indices[34] = 5;
        indices[35] = 8;
        break;
    default:
        break;
    }
}

Mesh::Mesh(){}

Mesh::~Mesh(){}
