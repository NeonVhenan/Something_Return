#ifndef COLLIDERMESH_H
#define COLLIDERMESH_H

#include "mesh.h"
#include "colliderbox.h"

class ColliderMesh
{
public:
    ColliderMesh();
    ColliderMesh(Mesh mesh);
    void transform(Transform t, int i);
    bool collision(ColliderBox * c);
    Mesh mesh;
    bool defini;

    float xmin();
    float xmax();
    float ymin();
    float ymax();
    float zmin();
    float zmax();
};

#endif // COLLIDERMESH_H
