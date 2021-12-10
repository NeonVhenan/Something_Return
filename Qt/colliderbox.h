#ifndef COLLIDERBOX_H
#define COLLIDERBOX_H

#include "collider.h"
#include "transform.h"
#include "mesh.h"

class ColliderBox //: public Collider
{
public:
    ColliderBox();
    ColliderBox(Mesh mesh);
    ColliderBox(QVector3D p1, QVector3D p2);
    void transform(Transform t, int i) ;//override;
    bool collision(ColliderBox * c);

    float xmin() ;//override;
    float xmax() ;//override;
    float ymin() ;//override;
    float ymax() ;//override;
    float zmin() ;//override;
    float zmax() ;//override;

    bool defini = false;

    QVector3D point1;
    QVector3D point2;
};

#endif // COLLIDERBOX_H
