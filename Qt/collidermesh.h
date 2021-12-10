#ifndef COLLIDERMESH_H
#define COLLIDERMESH_H

#include "collider.h"
#include "mesh.h"
#include "colliderbox.h"

class ColliderMesh : public Collider
{
public:
    ColliderMesh(Mesh mesh);
    void transform(Transform t, int i) override;
    bool collision(ColliderBox * c);
    Mesh mesh;

    float xmin() override;
    float xmax() override;
    float ymin() override;
    float ymax() override;
    float zmin() override;
    float zmax() override;
};

#endif // COLLIDERMESH_H
