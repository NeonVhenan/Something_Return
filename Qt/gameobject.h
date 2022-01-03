#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "mesh.h"
#include "transform.h"
#include "collidermesh.h"
#include "colliderbox.h"

#include <QList>


class GameObject
{
public:
    GameObject(GameObject *parent, Mesh mesh, Transform transform, Mesh collide);
    GameObject(GameObject *parent, Mesh mesh, Transform transform, bool aCollider);
    GameObject();
    ~GameObject();
    void transformObj(QMatrix4x4 *mat);
    void anime(QMatrix4x4 *mat);

    GameObject *parent;
    Mesh mesh;
    Transform transform;
    ColliderBox collideB;
    ColliderMesh collideM;
    int type; //type = 1 -> colliderMesh, type = 2 -> colliderBox


    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;

    QList<GameObject*> * child;

    void addEnfant(GameObject * obj);
};

#endif // GAMEOBJECT_H
