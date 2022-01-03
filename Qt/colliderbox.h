#ifndef COLLIDERBOX_H
#define COLLIDERBOX_H

#include "transform.h"
#include "mesh.h"

class ColliderBox
{
public:
    ColliderBox();
    ColliderBox(Mesh mesh);
    ColliderBox(QVector3D p1, QVector3D p2);
    void transform(Transform t, int i) ;
    bool collision(ColliderBox * c);

    float xmin() ;
    float xmax() ;
    float ymin() ;
    float ymax() ;
    float zmin() ;
    float zmax() ;

    bool defini = false;

    QVector3D point1;
    QVector3D point2;
};

#endif // COLLIDERBOX_H
