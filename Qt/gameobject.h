#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "mesh.h"
#include "transform.h"
#include "colliderbox.h"

#include <QList>


class GameObject
{
public:
    GameObject(GameObject *parent, Mesh mesh, Transform transform, ColliderBox c);
    GameObject();
    ~GameObject();
    void transformObj(QMatrix4x4 *mat);
    void anime(QMatrix4x4 *mat);

    GameObject *parent;
    Mesh mesh;
    Transform transform;
    ColliderBox collide;


    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;

    QList<GameObject*> * child;

    void addEnfant(GameObject * obj);
};

#endif // GAMEOBJECT_H
