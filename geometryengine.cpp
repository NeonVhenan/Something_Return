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

//! [0]
GeometryEngine::GeometryEngine()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();
    arrayBuf.create();
    indexBuf.create();

    monde = new GameObject(NULL, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), 0.0);
    monde->arrayBuf.create();
    monde->indexBuf.create();

    soleil = new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 5.0f), 0.000000347 * M_PI / 180 * 10);
    soleil->arrayBuf.create();
    soleil->indexBuf.create();

    objet1 = new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0), QVector3D(1.0f,0.0f,0.0f), 1.0f), 1.0 * M_PI / 180 * 10);
    objet1->arrayBuf.create();
    objet1->indexBuf.create();

    terre = new GameObject(monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 1.0f), 23.44 * M_PI / 180), QVector3D(1.0f,0.0f,0.0f), 3.0f/*0.009142857f*/), 1.0 * M_PI / 180 * 10);
    terre->arrayBuf.create();
    terre->indexBuf.create();

    lune = new GameObject(objet1, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 1.0f), 6.68 * M_PI / 180), QVector3D(0.5f,0.0,0.0f), 1.0f/*0.002485714f*/), 13.2 * M_PI / 180 * 10);
    lune->arrayBuf.create();
    lune->indexBuf.create();

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

    terre->arrayBuf.bind();
    terre->arrayBuf.allocate(terre->mesh.vertices, terre->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    terre->indexBuf.bind();
    terre->indexBuf.allocate(terre->mesh.indices,  terre->mesh.indexCount* sizeof(GLushort));

    soleil->arrayBuf.bind();
    soleil->arrayBuf.allocate(soleil->mesh.vertices, soleil->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    soleil->indexBuf.bind();
    soleil->indexBuf.allocate(soleil->mesh.indices,  soleil->mesh.indexCount* sizeof(GLushort));

    lune->arrayBuf.bind();
    lune->arrayBuf.allocate(lune->mesh.vertices, lune->mesh.vertexNumber * sizeof(VertexData));

    // Transfer index data to VBO 1
    lune->indexBuf.bind();
    lune->indexBuf.allocate(lune->mesh.indices,  lune->mesh.indexCount* sizeof(GLushort));
//! [1]
}

//! [2]v_position
void GeometryEngine::drawCubeGeometry(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
   // arrayBuf = objet.arrayBuf;
    soleil->arrayBuf.bind();
   // indexBuf = objet.indexBuf;
    soleil->indexBuf.bind();

    // Offset for position
    quintptr offset = 0;

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    soleil->transformObj(&mat, 0, 0);

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
    glDrawElements(GL_TRIANGLES, soleil->indexBuf.size(), GL_UNSIGNED_SHORT, 0); //Careful update indicesNumber when creating new geometry

    terre->arrayBuf.bind();
   // indexBuf = objet.indexBuf;
    terre->indexBuf.bind();

    // Offset for position
    offset = 0;

    mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    terre->transformObj(&mat, 0, 1);

    program->setUniformValue("transformation", mat);

    // Tell OpenGL programmable pipeline how to locate vertex position data
    vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLES, terre->indexBuf.size(), GL_UNSIGNED_SHORT, 0);


    lune->arrayBuf.bind();
   // indexBuf = objet.indexBuf;
    lune->indexBuf.bind();

    // Offset for position
    offset = 0;

    mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    //objet1->transformObj(&mat, 0, 1);


    mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    lune->transformObj(&mat, 0, 2);

    program->setUniformValue("transformation", mat);

    // Tell OpenGL programmable pipeline how to locate vertex position data
    vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    // Offset for texture coordinate
    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLES, lune->indexBuf.size(), GL_UNSIGNED_SHORT, 0);
}
