#include "gameobject.h"

GameObject::GameObject(GameObject *parent, Mesh mesh, Transform transform, float vit): indexBuf(QOpenGLBuffer::IndexBuffer)
{
    this->parent = parent;
    this->mesh = mesh;
    this->transform = transform;
    this->angle = 0.0f;
    this->vit = vit;

//    arrayBuf.create();
//    indexBuf.create();
}

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::transformObj(QMatrix4x4 *mat, int type, int indice){
    if(type == 0){
        mat->rotate(QQuaternion::fromAxisAndAngle(QVector3D(0.0, 1.0, 0.0), this->angle));
        this->angle += this->vit;
        printf("%d : %f \n",indice,angle);
    }

    this->transform.transform(mat);

    if(parent != NULL){
        parent->transformObj(mat, 1, indice - 1);
    }
}
