#ifndef COLLIDERCAPSULE_H
#define COLLIDERCAPSULE_H

#include "collider.h"
#include "colliderbox.h"

class ColliderCapsule : public Collider
{
public:
    ColliderCapsule();
    ColliderCapsule(QVector3D point1, QVector3D point2, float rayon);

    bool collision(ColliderBox c);

    QVector3D point1;
    QVector3D point2;
    float rayon;
};

#endif // COLLIDERCAPSULE_H
