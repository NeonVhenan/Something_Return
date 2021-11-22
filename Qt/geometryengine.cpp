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


GameObject * GeometryEngine::monde = new GameObject(NULL, Mesh(0), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), Collider());

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

    couloirDroit = new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(3.5, 0.0, 0.0), QVector3D(3.5, 6.0, 0.0), QVector3D(3.5, 6.0, -20.0), QVector3D(3.5, 0.0,-20.0), QVector3D(4.5, 0.0, 0.0), QVector3D(4.5, 6.0, 0.0), QVector3D(4.5, 6.0, -20.0), QVector3D(4.5, 0.0,-20.0)));
    couloirDroit->arrayBuf.create();
    couloirDroit->indexBuf.create();

    monde->child->append(couloirDroit);
    //mise à jour collider monde

    couloirGauche = new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(-3.5, 0.0, 0.0), QVector3D(-3.5, 4.0, 0.0), QVector3D(-3.5, 4.0, -20.0), QVector3D(-3.5, 0.0,-20.0), QVector3D(-4.5, 0.0, 0.0), QVector3D(-4.5, 6.0, 0.0), QVector3D(-4.5, 6.0, -20.0), QVector3D(-4.5, 0.0,-20.0)));
    couloirGauche->arrayBuf.create();
    couloirGauche->indexBuf.create();

    monde->child->append(couloirGauche);
    //mise à jour collider monde

    couloirDroit2 = new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(0.0, 0.0, -27.5), QVector3D(0.0, 4.0, -27.5), QVector3D(-20.0, 4.0, -27.5), QVector3D(-20.0, 0.0,-27.5), QVector3D(0.0, 0.0, -28.5), QVector3D(0.0, 4.0, -28.5), QVector3D(-20.0, 4.0, -28.5), QVector3D(-20.0, 0.0,-28.5)));
    couloirDroit2->arrayBuf.create();
    couloirDroit2->indexBuf.create();

    monde->child->append(couloirDroit2);
    //mise à jour collider monde

    couloirGauche2 = new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,-4.0f), 1.0f), ColliderBox(QVector3D(-4.0, 0.0, -20.5), QVector3D(-4.0, 4.0, -20.5), QVector3D(-20.0, 4.0, -20.5), QVector3D(-20.0, 0.0,-20.5), QVector3D(-4.0, 0.0, -19.5), QVector3D(-4.0, 4.0, -19.5), QVector3D(-20.0, 4.0, -19.5), QVector3D(-20.0, 0.0,-19.5)));
    couloirGauche2->arrayBuf.create();
    couloirGauche2->indexBuf.create();

    monde->child->append(couloirGauche2);
    //mise à jour collider monde

    couloirDroit3 = new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,20.0f), 1.0f), ColliderBox(QVector3D(0.0, 0.0, -27.5), QVector3D(0.0, 4.0, -27.5), QVector3D(-20.0, 4.0, -27.5), QVector3D(-20.0, 0.0,-27.5), QVector3D(0.0, 0.0, -28.5), QVector3D(0.0, 4.0, -28.5), QVector3D(-20.0, 4.0, -28.5), QVector3D(-20.0, 0.0,-28.5)));
    couloirDroit3->arrayBuf.create();
    couloirDroit3->indexBuf.create();

    monde->child->append(couloirDroit3);
    //mise à jour collider monde

    couloirGauche3 = new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,24.0f), 1.0f), ColliderBox(QVector3D(-4.0, 0.0, -20.5), QVector3D(-4.0, 4.0, -20.5), QVector3D(-20.0, 4.0, -20.5), QVector3D(-20.0, 0.0,-20.5), QVector3D(-4.0, 0.0, -19.5), QVector3D(-4.0, 4.0, -19.5), QVector3D(-20.0, 4.0, -19.5), QVector3D(-20.0, 0.0,-19.5)));
    couloirGauche3->arrayBuf.create();
    couloirGauche3->indexBuf.create();

    monde->child->append(couloirGauche3);
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


    couloirDroit->arrayBuf.bind();
    couloirDroit->arrayBuf.allocate(couloirDroit->mesh.vertices, couloirDroit->mesh.vertexNumber * sizeof(VertexData));

    couloirDroit->indexBuf.bind();
    couloirDroit->indexBuf.allocate(couloirDroit->mesh.indices,  couloirDroit->mesh.indexCount* sizeof(GLushort));

    couloirGauche->arrayBuf.bind();
    couloirGauche->arrayBuf.allocate(couloirGauche->mesh.vertices, couloirGauche->mesh.vertexNumber * sizeof(VertexData));

    couloirGauche->indexBuf.bind();
    couloirGauche->indexBuf.allocate(couloirGauche->mesh.indices,  couloirGauche->mesh.indexCount* sizeof(GLushort));


    couloirDroit2->arrayBuf.bind();
    couloirDroit2->arrayBuf.allocate(couloirDroit2->mesh.vertices, couloirDroit2->mesh.vertexNumber * sizeof(VertexData));

    couloirDroit2->indexBuf.bind();
    couloirDroit2->indexBuf.allocate(couloirDroit2->mesh.indices,  couloirDroit2->mesh.indexCount* sizeof(GLushort));


    couloirGauche2->arrayBuf.bind();
    couloirGauche2->arrayBuf.allocate(couloirGauche2->mesh.vertices, couloirGauche2->mesh.vertexNumber * sizeof(VertexData));

    couloirGauche2->indexBuf.bind();
    couloirGauche2->indexBuf.allocate(couloirGauche2->mesh.indices,  couloirGauche2->mesh.indexCount* sizeof(GLushort));

    couloirDroit3->arrayBuf.bind();
    couloirDroit3->arrayBuf.allocate(couloirDroit3->mesh.vertices, couloirDroit3->mesh.vertexNumber * sizeof(VertexData));

    couloirDroit3->indexBuf.bind();
    couloirDroit3->indexBuf.allocate(couloirDroit3->mesh.indices,  couloirDroit3->mesh.indexCount* sizeof(GLushort));


    couloirGauche3->arrayBuf.bind();
    couloirGauche3->arrayBuf.allocate(couloirGauche3->mesh.vertices, couloirGauche3->mesh.vertexNumber * sizeof(VertexData));

    couloirGauche3->indexBuf.bind();
    couloirGauche3->indexBuf.allocate(couloirGauche3->mesh.indices,  couloirGauche3->mesh.indexCount* sizeof(GLushort));

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
    if(/*colision*/){//test collision sans oublié le transform bloc/bloc

        if(!obj->child->isEmpty()){
            for(int i =0 ; i < obj->child->size(); i++){
                if(testCollision(obj->child[i]))
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
