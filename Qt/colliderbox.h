#ifndef COLLIDERBOX_H
#define COLLIDERBOX_H

#include "collider.h"

class ColliderBox : public Collider
{
public:
    ColliderBox();
    ColliderBox(QVector3D point1, QVector3D point2);

    QVector3D point1;
    QVector3D point2;
};

#endif // COLLIDERBOX_H
