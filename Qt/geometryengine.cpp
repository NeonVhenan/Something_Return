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

    couloir = new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), Collider());
    couloir->arrayBuf.create();
    couloir->indexBuf.create();

    monde->child->append(couloir);

    couloir2 = new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,-20.0f), 1.0f), Collider());
    couloir2->arrayBuf.create();
    couloir2->indexBuf.create();

    monde->child->append(couloir2);


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


    couloir->arrayBuf.bind();
    couloir->arrayBuf.allocate(couloir->mesh.vertices, couloir->mesh.vertexNumber * sizeof(VertexData));

    couloir->indexBuf.bind();
    couloir->indexBuf.allocate(couloir->mesh.indices,  couloir->mesh.indexCount* sizeof(GLushort));


    couloir2->arrayBuf.bind();
    couloir2->arrayBuf.allocate(couloir2->mesh.vertices, couloir2->mesh.vertexNumber * sizeof(VertexData));

    couloir2->indexBuf.bind();
    couloir2->indexBuf.allocate(couloir2->mesh.indices,  couloir2->mesh.indexCount* sizeof(GLushort));

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
