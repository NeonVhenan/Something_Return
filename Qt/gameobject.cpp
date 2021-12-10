#include "gameobject.h"
#include "colliderbox.h"
#include "collidermesh.h"

/*GameObject::GameObject(GameObject *parent, Mesh mesh, Transform transform, Mesh collide): indexBuf(QOpenGLBuffer::IndexBuffer)
{
    this->parent = parent;
    this->mesh = mesh;
    this->transform = transform;
    this->collide = ColliderMesh(collide);
    this->child = new QList<GameObject*>();
}*/

GameObject::GameObject(GameObject *parent, Mesh mesh, Transform transform, bool aCollider): indexBuf(QOpenGLBuffer::IndexBuffer)
{
    this->parent = parent;
    this->mesh = mesh;
    this->transform = transform;
    if(aCollider)
        this->collide = ColliderBox(mesh);
    else {
        this->collide = ColliderBox(QVector3D(0.0, -1.0, 0.0), QVector3D(0.0, -1.0, 0.0));
    }
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
    ColliderBox c = obj->collide;
    c.transform(obj->transform, 1);
    if(!collide.defini){
        collide = obj->collide;
        this->collide.defini = true;
    }
    else{
        if(this->collide.xmin() > c.xmin()){
            this->collide.point1[0] = c.xmin();
        }
        if(this->collide.xmax() < c.xmax()){
            this->collide.point2[0] = c.xmax();
        }
        if(this->collide.ymin() > c.ymin()){
            this->collide.point1[1] = c.ymin();
        }
        if(this->collide.ymax() < c.ymax()){
            this->collide.point2[1] = c.ymax();
        }
        if(this->collide.zmin() > c.zmin()){
            this->collide.point1[2] = c.zmin();
        }
        if(this->collide.zmax() < c.zmax()){
            this->collide.point2[2] = c.zmax();
        }
    }
    this->child->append(obj);
}
