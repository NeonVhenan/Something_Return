#ifndef COLLIDERBOX_H
#define COLLIDERBOX_H

#include "collider.h"

class ColliderBox : public Collider
{
public:
    ColliderBox();
    ColliderBox(QVector3D point1, QVector3D point2, QVector3D point3, QVector3D point4, QVector3D point5, QVector3D point6, QVector3D point7, QVector3D point8);

    QVector3D point1;
    QVector3D point2;
    QVector3D point3;
    QVector3D point4;
    QVector3D point5;
    QVector3D point6;
    QVector3D point7;
    QVector3D point8;
};

#endif // COLLIDERBOX_H
