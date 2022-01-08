/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "geometryengine.h"
#include "scene.h"
#include <iostream>
#include <QVector2D>
#include <QVector3D>

#define PI 3.1415926535897932384626433832795


GameObject * GeometryEngine::monde = new GameObject(NULL, Mesh(0), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), false);

//! [0]
GeometryEngine::GeometryEngine()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    srand(time(NULL));
    initializeOpenGLFunctions();
    arrayBuf.create();
    indexBuf.create();

    monde->arrayBuf.create();
    monde->indexBuf.create();

    /*unsigned int i = 0;

    listeObjets.push_back(new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), true));
    listeObjets[i]->arrayBuf.create();
    listeObjets[i]->indexBuf.create();

    monde->addEnfant(listeObjets[i++]);
    //mise à jour collider monde

    listeObjets.push_back(new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), true));
    listeObjets[i]->arrayBuf.create();
    listeObjets[i]->indexBuf.create();

    monde->addEnfant(listeObjets[i++]);
    //mise à jour collider monde*/

//    listeObjets.push_back(new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,0.0f), 1.0f), true));
//    listeObjets[i]->arrayBuf.create();
//    listeObjets[i]->indexBuf.create();

//    monde->addEnfant(listeObjets[i++]);
//    //mise à jour collider monde

//    listeObjets.push_back(new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,-4.0f), 1.0f), true));
//    listeObjets[i]->arrayBuf.create();
//    listeObjets[i]->indexBuf.create();

//    monde->addEnfant(listeObjets[i++]);
//    //mise à jour collider monde

//    listeObjets.push_back(new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,20.0f), 1.0f), true));
//    listeObjets[i]->arrayBuf.create();
//    listeObjets[i]->indexBuf.create();

//    monde->addEnfant(listeObjets[i++]);
//    //mise à jour collider monde

//    listeObjets.push_back(new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,24.0f), 1.0f), true));
//    listeObjets[i]->arrayBuf.create();
//    listeObjets[i]->indexBuf.create();

//    monde->addEnfant(listeObjets[i++]);
    //mise à jour collider monde


    /*listeObjets.push_back(new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00), QVector3D(0.0f,0.0f,0.0f), 1.0f), false));
    listeObjets[i]->arrayBuf.create();
    listeObjets[i]->indexBuf.create();

    monde->addEnfant(listeObjets[i++]);*/


//    listeObjets.push_back(new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,0.0f), 1.0f), true));
//    listeObjets[i]->arrayBuf.create();
//    listeObjets[i]->indexBuf.create();

//    monde->addEnfant(listeObjets[i++]);



//    listeObjets.push_back(new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,20.0f), 1.0f), true));
//    listeObjets[i]->arrayBuf.create();
//    listeObjets[i]->indexBuf.create();

//    monde->addEnfant(listeObjets[i++]);


    //Scene *scene = new Scene(QString("../Something_Return/Qt/scene/scene.txt"));
    //scene->generateListObject();


// sphere.off
    /*listeObjets.push_back(new GameObject(monde, loadOff("../Something_Return/Qt/sphere.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00),
                                                                                   QVector3D(0.0f,1.0f,5.0f), 1.0f), false));
    listeObjets[i]->arrayBuf.create();
   listeObjets[i]->indexBuf.create();

   monde->addEnfant(listeObjets[i++]);*/

    Scene * s = new Scene(QVector3D(0.0,0.0,-1.0), NULL, 1, QVector3D(0.0f,0.0f,0.0f), 0.0);
    s->loadScene();

    printf("%d\n", monde->child->size());

    initCubeGeometry();

}

GeometryEngine::~GeometryEngine()
{
    arrayBuf.destroy();
    indexBuf.destroy();
}
//! [0]

void GeometryEngine::initCubeGeometry()
{
    monde->arrayBuf.bind();
    monde->arrayBuf.allocate(monde->mesh.vertices, monde->mesh.vertexNumber * sizeof(VertexData));

    monde->indexBuf.bind();
    monde->indexBuf.allocate(monde->mesh.indices,  monde->mesh.indexCount* sizeof(GLushort));

    for(int i = 0; i < listeObjets.size(); i++){
        listeObjets[i]->arrayBuf.bind();
        listeObjets[i]->arrayBuf.allocate(listeObjets[i]->mesh.vertices, listeObjets[i]->mesh.vertexNumber * sizeof(VertexData));

        listeObjets[i]->indexBuf.bind();
        listeObjets[i]->indexBuf.allocate(listeObjets[i]->mesh.indices,  listeObjets[i]->mesh.indexCount* sizeof(GLushort));
    }

//! [1]
}

Mesh  GeometryEngine::loadOff(std::string filename){
    Mesh mesh=Mesh();
    std::vector< std::vector<unsigned int> >  faces;
    std::vector<QVector3D>  vertex;
    OFFIO::open(filename, vertex, faces, true);

    mesh.vertexNumber = vertex.size();
//    mesh.vertices[mesh.vertexNumber];
    mesh.indexCount = faces.size()*3;
     mesh.vertices = new VertexData[mesh.vertexNumber];
     mesh.indices = new GLushort[mesh.indexCount];

 //   mesh.indices[mesh.indexCount];

    for(unsigned int i=0; i<mesh.indexCount;i+=3) {
        mesh.indices[i]= faces[i/3][0];
        mesh.indices[i+1]= faces[i/3][1];
        mesh.indices[i+2]= faces[i/3][2];
    }

    for(unsigned int i=0; i<mesh.vertexNumber;i++) {
        mesh.vertices[i]= {vertex[i], QVector2D(vertex[i][0]+vertex[i][1], vertex[i][0]+vertex[i][2])};
    }
    mesh.TextN=1;
    return mesh;
}


Mesh  GeometryEngine::loadOffSimple(char * filename){
    FILE * f;
    char type[50];
    if((f = fopen(filename, "r")) != NULL){
        fscanf(f,"%s", type);
        if(strcmp(type, "OFFS") != 0) {
            printf("TYPE DE FICHIER %s ET NON OFFS\n", type);
            return Mesh();
        }
        int nbTri;
        Mesh mesh = Mesh();
        fscanf(f,"%d %d", &mesh.vertexNumber, &nbTri);
        mesh.indexCount = nbTri * 3;
        mesh.vertices = new VertexData[mesh.vertexNumber];
        mesh.indices = new GLushort[mesh.indexCount];
        float x, y, z, xt, yt;
        for(unsigned int i = 0; i < mesh.vertexNumber; i++){
            fscanf(f,"%f %f %f %f %f", &x, &y, &z, &xt, &yt);
            mesh.vertices[i] = {QVector3D(x, y, z), QVector2D(xt, yt)};
        }
        int p1, p2, p3;
        for(unsigned int i = 0; i < mesh.indexCount; i+=3){
            fscanf(f,"%d %d %d", &p1, &p2, &p3);
            mesh.indices[i] = p1;
            mesh.indices[i+1] = p2;
            mesh.indices[i+2] = p3;
        }
        fscanf(f,"%d", &mesh.TextN);
        return mesh;
    }
    else{
        printf("Impossible d'ouvrir le fichier\n");
        return Mesh();
    }
}


void GeometryEngine::draw(QOpenGLShaderProgram *program)
{
    quintptr offset = 0;

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    int vertexLocation = program->attributeLocation("a_position");

    int texcoordLocation = program->attributeLocation("a_texcoord");

    drawGameObject(program, offset, mat, vertexLocation, texcoordLocation, monde); //objectList[0]
}


void GeometryEngine::drawGameObject(QOpenGLShaderProgram *program, quintptr offset, QMatrix4x4 mat, int vertexLocation, int texcoordLocation, GameObject* obj){
    if(obj->mesh.vertexNumber != 0){
        obj->arrayBuf.bind();
        obj->indexBuf.bind();

        offset = 0;

        mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

        obj->transformObj(&mat);

        program->setUniformValue("transformation", mat);

        vertexLocation = program->attributeLocation("a_position");
        program->enableAttributeArray(vertexLocation);
        program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

        offset += sizeof(QVector3D);

        texcoordLocation = program->attributeLocation("a_texcoord");
        program->enableAttributeArray(texcoordLocation);
        program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

        glDrawElements(GL_TRIANGLES, obj->indexBuf.size(), GL_UNSIGNED_SHORT, 0);
    }
    if(!obj->child->isEmpty()){
        for(int i = 0; i < obj->child->size(); i++){

            program->setUniformValue("TextN",obj->child->value(i)->mesh.TextN  );


            drawGameObject(program, offset, mat, vertexLocation, texcoordLocation, obj->child->value(i));
        }
    }
}

bool GeometryEngine::testCollision(GameObject * obj){
    if(obj->type == 2){
        ColliderBox *c = new ColliderBox(obj->collideB.point1, obj->collideB.point2);
        if(obj->parent == NULL)
            c->transform(obj->transform, 0);
        else {
            c->transform(obj->transform, 1);
        }
        if(c->collision(new ColliderBox(QVector3D(-1.5,0.0,-1.5), QVector3D(1.5, 3.5, 1.5)))){//test collision sans oublié le transform bloc/bloc
            if(!obj->child->isEmpty()){
                for(int i = 0 ; i < obj->child->size(); i++){
                    if(testCollision(obj->child->at(i))){
                        return true;
                    }
                }
                return false;
            }
            else
                return true;
        }
        else {
            return false;
        }
    }
    else{
        ColliderMesh *c = new ColliderMesh(obj->collideM.mesh);
        if(obj->parent == NULL)
            c->transform(obj->transform, 0);
        else {
            c->transform(obj->transform, 1);
        }
        if(c->collision(new ColliderBox(QVector3D(-1.5,0.0,-1.5), QVector3D(1.5, 3.5, 1.5)))){//test collision sans oublié le transform bloc/bloc
            if(!obj->child->isEmpty()){
                for(int i = 0 ; i < obj->child->size(); i++){
                    if(testCollision(obj->child->at(i))){
                        return true;
                    }
                }
                return false;
            }
            else
                return true;
        }
        else {
            return false;
        }
    }
}
