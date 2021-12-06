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

#include <iostream>
#include <QVector2D>
#include <QVector3D>

#define M_PI 3.1415926535897932384626433832795


GameObject * GeometryEngine::monde = new GameObject(NULL, Mesh(0), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), ColliderBox());

//! [0]
GeometryEngine::GeometryEngine()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();
    arrayBuf.create();
    indexBuf.create();

    monde->arrayBuf.create();
    monde->indexBuf.create();

    monde->arrayBuf.create();
    monde->indexBuf.create();

    listeObjets.push_back(new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(3.5, 0.0, -20.0), QVector3D(4.5, 6.0, 0.0))));
    listeObjets[0]->arrayBuf.create();
    listeObjets[0]->indexBuf.create();

    monde->addEnfant(listeObjets[0]);
    //mise à jour collider monde

    listeObjets.push_back(new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(-4.5, 0.0,-20.0), QVector3D(-3.5, 6.0, 0.0))));
    listeObjets[1]->arrayBuf.create();
    listeObjets[1]->indexBuf.create();

    monde->addEnfant(listeObjets[1]);
    //mise à jour collider monde

    listeObjets.push_back(new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(3.5, 0.0, -20.0), QVector3D(4.5, 6.0, 0.0))));
    listeObjets[2]->arrayBuf.create();
    listeObjets[2]->indexBuf.create();

    monde->addEnfant(listeObjets[2]);
    //mise à jour collider monde

    listeObjets.push_back(new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,-4.0f), 1.0f), ColliderBox(QVector3D(-4.5, 0.0,-20.0), QVector3D(-3.5, 6.0, 0.0))));
    listeObjets[3]->arrayBuf.create();
    listeObjets[3]->indexBuf.create();

    monde->addEnfant(listeObjets[3]);
    //mise à jour collider monde

    listeObjets.push_back(new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,20.0f), 1.0f), ColliderBox(QVector3D(3.5, 0.0, -20.0), QVector3D(4.5, 6.0, 0.0))));
    listeObjets[4]->arrayBuf.create();
    listeObjets[4]->indexBuf.create();

    monde->addEnfant(listeObjets[4]);
    //mise à jour collider monde

    listeObjets.push_back(new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,24.0f), 1.0f), ColliderBox(QVector3D(-4.5, 0.0,-20.0), QVector3D(-3.5, 6.0, 0.0))));
    listeObjets[5]->arrayBuf.create();
    listeObjets[5]->indexBuf.create();

    monde->addEnfant(listeObjets[5]);
    //mise à jour collider monde



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

void GeometryEngine::draw(QOpenGLShaderProgram *program)
{
    quintptr offset = 0;

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    int vertexLocation = program->attributeLocation("a_position");

    int texcoordLocation = program->attributeLocation("a_texcoord");

    drawGameObject(program, offset, mat, vertexLocation, texcoordLocation, monde);
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
            drawGameObject(program, offset, mat, vertexLocation, texcoordLocation, obj->child->value(i));
        }
    }
}

bool GeometryEngine::testCollision(GameObject * obj){
    ColliderBox *c = new ColliderBox(obj->collide.point1, obj->collide.point2);
    if(obj->parent == NULL)
        c->transform(obj->transform, 0);
    else {
        printf("hello\n");
        c->transform(obj->transform, 1);
    }
    if(c->collision(new ColliderBox(QVector3D(-1.5,0.0,-1.5), QVector3D(2.5, 3.5, 1.5))) || ColliderBox(QVector3D(-1.5,0.0,-1.5), QVector3D(2.5, 3.5, 1.5)).collision(c)){//test collision sans oublié le transform bloc/bloc
        if(!obj->child->isEmpty()){
            for(int i = 0 ; i < obj->child->size(); i++){
                if(obj->child->at(i)->parent == NULL)
                    printf("problème ?\n");
                if(testCollision(obj->child->at(i)))
                    return true;
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
