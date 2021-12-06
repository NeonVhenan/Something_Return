#ifndef COLLIDERBOX_H
#define COLLIDERBOX_H

#include "transform.h"

class ColliderBox
{
public:
    ColliderBox();
    ColliderBox(QVector3D point1, QVector3D point2);
    void transform(Transform t, int i);
    bool collision(ColliderBox * c);

    float xmin();
    float xmax();
    float ymin();
    float ymax();
    float zmin();
    float zmax();


    QVector3D point1;
    QVector3D point2;

    bool defini = false;
};

#endif // COLLIDERBOX_H
