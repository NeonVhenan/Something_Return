#include "mesh.h"

Mesh::Mesh(int indice)
{
    int nH, nW, k, c;
    float dim, pas;
    switch(indice){
    case 1:
        nH = 16;
        nW = 16;

        this->vertexNumber = 4*nH*nW;
        this->indexCount = 6*nH*nW;

        this->vertices = new VertexData[this->vertexNumber];
        dim = 16.0;
        pas = 1.0/dim;
        k = 0;
        for(int i = 0; i < nH ; i++){
            for(int j = 0; j < nW; j++){
                vertices[k] =   {QVector3D( i* pas-0.5, -1.0f, j* pas-0.5), QVector2D(i* pas *0.33, j* pas *0.5+0.5)};
                vertices[k+2] = {QVector3D( (i+1)* pas-0.5, -1.0f, j* pas-0.5), QVector2D((i+1)* pas *0.33, j* pas *0.5+0.5)};
                vertices[k+1] = {QVector3D( i* pas-0.5, -1.0f, (j+1)* pas-0.5), QVector2D(i* pas *0.33, (j+1)* pas *0.5+0.5)};
                vertices[k+3] = {QVector3D( (i+1)* pas-0.5, -1.0f, (j+1)* pas-0.5), QVector2D((i+1)* pas *0.33, (j+1)* pas *0.5+0.5)};
                k+=4;
            }
        }



        this->indices = new GLushort[this->indexCount];
        k = 0;
        c = 0;
        for(int i = 0; i < nH ; i++){
            for(int j = 0; j < nW; j++){
                indices[k] = c;
                indices[k+1] = c+1;
                indices[k+2] = c+2;
                indices[k+3] = c+1;
                indices[k+4] = c+2;
                indices[k+5] = c+3;
                c+=4;
                k+=6;
            }
        }
        break;
    case 2:
        this->vertexNumber = 5;
        this->indexCount = 6*3;

        this->vertices = new VertexData[this->vertexNumber];
        vertices[0] = {QVector3D( -0.05f, 0.0f, -0.05f), QVector2D(0.0f, 1.0f)};
        vertices[1] = {QVector3D( -0.05f, 0.0f, 0.05f), QVector2D(0.0f, 0.0f)};
        vertices[2] = {QVector3D( 0.05f, 0.0f, 0.05f), QVector2D(1.0f, 0.0f)};
        vertices[3] = {QVector3D( 0.05f, 0.0f, -0.05f), QVector2D(1.0f, 1.0f)};
        vertices[4] = {QVector3D( 0.0f, 0.2f, 0.0f), QVector2D(0.5f, 0.5f)};

        this->indices = new GLushort[this->indexCount];
        indices[0] = 0;
        indices[1] = 4;
        indices[2] = 1;
        indices[3] = 1;
        indices[4] = 4;
        indices[5] = 2;
        indices[6] = 2;
        indices[7] = 4;
        indices[8] = 3;
        indices[9] = 3;
        indices[10] = 4;
        indices[11] = 0;
        indices[12] = 2;
        indices[13] = 0;
        indices[14] = 1;
        indices[15] = 0;
        indices[16] = 3;
        indices[17] = 2;
        break;
    default:
        break;
    }
}

Mesh::Mesh(){}

Mesh::~Mesh(){}
