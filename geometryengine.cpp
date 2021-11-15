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

GameObject * GeometryEngine::monde = new GameObject(NULL, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), Collider());

//! [0]
GeometryEngine::GeometryEngine()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();
    arrayBuf.create();
    indexBuf.create();


    monde->arrayBuf.create();
    monde->indexBuf.create();

    mur1 = new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), Collider());
    mur1->arrayBuf.create();
    mur1->indexBuf.create();

    mur2 = new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), Collider());
    mur2->arrayBuf.create();
    mur2->indexBuf.create();

    mur3 = new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), Collider());
    mur3->arrayBuf.create();
    mur3->indexBuf.create();

    mur4 = new GameObject(monde, Mesh(4), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), Collider());
    mur4->arrayBuf.create();
    mur4->indexBuf.create();

    mur5 = new GameObject(monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(0.0f,0.0f,-20.0f), 1.0f), Collider());
    mur5->arrayBuf.create();
    mur5->indexBuf.create();

    mur6 = new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(0.0f,0.0f,-20.0f), 1.0f), Collider());
    mur6->arrayBuf.create();
    mur6->indexBuf.create();

    mur7 = new GameObject(monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(0.0f,0.0f,-20.0f), 1.0f), Collider());
    mur7->arrayBuf.create();
    mur7->indexBuf.create();

    mur8 = new GameObject(monde, Mesh(4), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(0.0f,0.0f,-20.0f), 1.0f), Collider());
    mur8->arrayBuf.create();
    mur8->indexBuf.create();


    // Initializes cube geometry and transfers it to VBOs
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
    mur1->arrayBuf.bind();
    mur1->arrayBuf.allocate(mur1->mesh.vertices, mur1->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur1->indexBuf.bind();
    mur1->indexBuf.allocate(mur1->mesh.indices,  mur1->mesh.indexCount* sizeof(GLushort));

    mur2->arrayBuf.bind();
    mur2->arrayBuf.allocate(mur2->mesh.vertices, mur2->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur2->indexBuf.bind();
    mur2->indexBuf.allocate(mur2->mesh.indices,  mur2->mesh.indexCount* sizeof(GLushort));

    mur3->arrayBuf.bind();
    mur3->arrayBuf.allocate(mur3->mesh.vertices, mur3->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur3->indexBuf.bind();
    mur3->indexBuf.allocate(mur3->mesh.indices,  mur3->mesh.indexCount* sizeof(GLushort));

    mur4->arrayBuf.bind();
    mur4->arrayBuf.allocate(mur4->mesh.vertices, mur4->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur4->indexBuf.bind();
    mur4->indexBuf.allocate(mur4->mesh.indices,  mur4->mesh.indexCount* sizeof(GLushort));



    mur5->arrayBuf.bind();
    mur5->arrayBuf.allocate(mur5->mesh.vertices, mur5->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur5->indexBuf.bind();
    mur5->indexBuf.allocate(mur5->mesh.indices,  mur5->mesh.indexCount* sizeof(GLushort));

    mur6->arrayBuf.bind();
    mur6->arrayBuf.allocate(mur6->mesh.vertices, mur6->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur6->indexBuf.bind();
    mur6->indexBuf.allocate(mur6->mesh.indices,  mur6->mesh.indexCount* sizeof(GLushort));

    mur7->arrayBuf.bind();
    mur7->arrayBuf.allocate(mur7->mesh.vertices, mur7->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur7->indexBuf.bind();
    mur7->indexBuf.allocate(mur7->mesh.indices,  mur7->mesh.indexCount* sizeof(GLushort));

    mur8->arrayBuf.bind();
    mur8->arrayBuf.allocate(mur8->mesh.vertices, mur8->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    mur8->indexBuf.bind();
    mur8->indexBuf.allocate(mur8->mesh.indices,  mur8->mesh.indexCount* sizeof(GLushort));
//! [1]
}

//! [2]v_position
void GeometryEngine::drawCubeGeometry(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
   // arrayBuf = objet.arrayBuf;
    mur1->arrayBuf.bind();
   // indexBuf = objet.indexBuf;
    mur1->indexBuf.bind();

    // Offset for position
    quintptr offset = 0;

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    mur1->transformObj(&mat, 0, 0);

    program->setUniformValue("transformation", mat);

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLES, mur1->indexBuf.size(), GL_UNSIGNED_SHORT, 0); //Careful update indicesNumber when creating new geometry

    mur2->arrayBuf.bind();
    mur2->indexBuf.bind();

    offset = 0;

    mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    mur2->transformObj(&mat, 0, 1);

    program->setUniformValue("transformation", mat);

    vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    glDrawElements(GL_TRIANGLES, mur2->indexBuf.size(), GL_UNSIGNED_SHORT, 0);


    mur3->arrayBuf.bind();
    mur3->indexBuf.bind();

    offset = 0;

    mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    mur3->transformObj(&mat, 0, 1);

    program->setUniformValue("transformation", mat);

    vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    glDrawElements(GL_TRIANGLES, mur3->indexBuf.size(), GL_UNSIGNED_SHORT, 0);


    mur4->arrayBuf.bind();
    mur4->indexBuf.bind();

    offset = 0;

    mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);


    mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    mur4->transformObj(&mat, 0, 2);

    program->setUniformValue("transformation", mat);

    vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    glDrawElements(GL_TRIANGLES, mur4->indexBuf.size(), GL_UNSIGNED_SHORT, 0);




     mur5->arrayBuf.bind();
     mur5->indexBuf.bind();

     offset = 0;

     mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

     mur5->transformObj(&mat, 0, 0);

     program->setUniformValue("transformation", mat);

     vertexLocation = program->attributeLocation("a_position");
     program->enableAttributeArray(vertexLocation);
     program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

     offset += sizeof(QVector3D);

     texcoordLocation = program->attributeLocation("a_texcoord");
     program->enableAttributeArray(texcoordLocation);
     program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

     glDrawElements(GL_TRIANGLES, mur5->indexBuf.size(), GL_UNSIGNED_SHORT, 0); //Careful update indicesNumber when creating new geometry

     mur6->arrayBuf.bind();
     mur6->indexBuf.bind();

     offset = 0;

     mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

     mur6->transformObj(&mat, 0, 1);

     program->setUniformValue("transformation", mat);

     vertexLocation = program->attributeLocation("a_position");
     program->enableAttributeArray(vertexLocation);
     program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

     offset += sizeof(QVector3D);

     texcoordLocation = program->attributeLocation("a_texcoord");
     program->enableAttributeArray(texcoordLocation);
     program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

     glDrawElements(GL_TRIANGLES, mur6->indexBuf.size(), GL_UNSIGNED_SHORT, 0);


     mur7->arrayBuf.bind();
     mur7->indexBuf.bind();

     offset = 0;

     mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

     mur7->transformObj(&mat, 0, 1);

     program->setUniformValue("transformation", mat);

     vertexLocation = program->attributeLocation("a_position");
     program->enableAttributeArray(vertexLocation);
     program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

     offset += sizeof(QVector3D);

     texcoordLocation = program->attributeLocation("a_texcoord");
     program->enableAttributeArray(texcoordLocation);
     program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

     glDrawElements(GL_TRIANGLES, mur7->indexBuf.size(), GL_UNSIGNED_SHORT, 0);


     mur8->arrayBuf.bind();
     mur8->indexBuf.bind();

     offset = 0;

     mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);


     mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

     mur8->transformObj(&mat, 0, 2);

     program->setUniformValue("transformation", mat);

     vertexLocation = program->attributeLocation("a_position");
     program->enableAttributeArray(vertexLocation);
     program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

     offset += sizeof(QVector3D);

     texcoordLocation = program->attributeLocation("a_texcoord");
     program->enableAttributeArray(texcoordLocation);
     program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

     glDrawElements(GL_TRIANGLES, mur8->indexBuf.size(), GL_UNSIGNED_SHORT, 0);

}
