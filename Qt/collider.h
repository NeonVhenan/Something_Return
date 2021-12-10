#ifndef COLLIDER_H
#define COLLIDER_H

#include "transform.h"

class Collider
{
public:
    Collider();
    virtual void transform(Transform t, int i);

    virtual float xmin();
    virtual float xmax();
    virtual float ymin();
    virtual float ymax();
    virtual float zmin();
    virtual float zmax();

    bool defini = false;
};

#endif // COLLIDER_H
