#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "mesh.h"
#include "transform.h"
#include "collider.h"
#include "colliderbox.h"
#include "collidercapsule.h"

#include <QList>


class GameObject
{
public:
    GameObject(GameObject *parent, Mesh mesh, Transform transform, Collider c);
    GameObject();
    ~GameObject();
    void transformObj(QMatrix4x4 *mat);
    void anime(QMatrix4x4 *mat);

    GameObject *parent;
    Mesh mesh;
    Transform transform;
    Collider collide;


    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;

    QList<GameObject*> * child;
};

#endif // GAMEOBJECT_H
