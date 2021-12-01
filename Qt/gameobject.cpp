#include "gameobject.h"

GameObject::GameObject(GameObject *parent, Mesh mesh, Transform transform, Collider c): indexBuf(QOpenGLBuffer::IndexBuffer)
{
    this->parent = parent;
    this->mesh = mesh;
    this->transform = transform;
    this->collide = c;
    this->child = new QList<GameObject*>();
}

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::transformObj(QMatrix4x4 *mat){
    if(parent != NULL){
        this->parent->transformObj(mat);
    }
    this->transform.transform(mat);
}


void GameObject::addEnfant(GameObject * obj){
    if(!collide.defini){
        collide = obj->collide;
        this->collide.defini = true;
    }
    else{

    }
    this->child->append(obj);
}
