#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "mesh.h"
#include "transform.h"

class GameObject
{
public:
    GameObject(GameObject *parent, Mesh mesh, Transform transform, float vit);
    GameObject();
    ~GameObject();
    void transformObj(QMatrix4x4 *mat, int type, int indice);
    void anime(QMatrix4x4 *mat);

    GameObject *parent;
    Mesh mesh;
    Transform transform;
    float angle;
    float vit;


    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif // GAMEOBJECT_H
