#include "gameobject.h"


GameObject::GameObject(GameObject *parent, Mesh mesh, Transform transform, Collider c): indexBuf(QOpenGLBuffer::IndexBuffer)
{
    this->parent = parent;
    this->mesh = mesh;
    this->transform = transform;
    this->collide = c;
    this->child = QList<GameObject*>();
}

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::transformObj(QMatrix4x4 *mat, int type, int indice){


    if(parent != NULL){
        this->parent->transformObj(mat, 1, indice-1);
    }

    this->transform.transform(mat);
}
