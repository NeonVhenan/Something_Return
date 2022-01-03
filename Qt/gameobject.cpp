#include "gameobject.h"
#include "colliderbox.h"
#include "collidermesh.h"

GameObject::GameObject(GameObject *parent, Mesh mesh, Transform transform, Mesh collide): indexBuf(QOpenGLBuffer::IndexBuffer)
{
    this->parent = parent;
    this->mesh = mesh;
    this->transform = transform;
    this->type = 1;
    this->collideM = ColliderMesh(collide);
    this->child = new QList<GameObject*>();
}

GameObject::GameObject(GameObject *parent, Mesh mesh, Transform transform, bool aCollider): indexBuf(QOpenGLBuffer::IndexBuffer)
{
    this->parent = parent;
    this->mesh = mesh;
    this->transform = transform;
    this->type = 2;
    if(aCollider)
        this->collideB = ColliderBox(mesh);
    else {
        this->collideB = ColliderBox(QVector3D(0.0, -1.0, 0.0), QVector3D(0.0, -1.0, 0.0));
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
    if(obj->type == 2){
        ColliderBox c = obj->collideB;
        c.transform(obj->transform, 1);
        if(type == 2){
            if(!collideB.defini){
                collideB = c;
                this->collideB.defini = true;
            }
            else{
                if(this->collideB.xmin() > c.xmin()){
                    this->collideB.point1[0] = c.xmin();
                }
                if(this->collideB.xmax() < c.xmax()){
                    this->collideB.point2[0] = c.xmax();
                }
                if(this->collideB.ymin() > c.ymin()){
                    this->collideB.point1[1] = c.ymin();
                }
                if(this->collideB.ymax() < c.ymax()){
                    this->collideB.point2[1] = c.ymax();
                }
                if(this->collideB.zmin() > c.zmin()){
                    this->collideB.point1[2] = c.zmin();
                }
                if(this->collideB.zmax() < c.zmax()){
                    this->collideB.point2[2] = c.zmax();
                }
            }
        }
        else{
            if(!collideM.defini){
                type = 2;
                collideB = c;
                collideM.defini = false;
                collideB.defini = true;
            }
            else{
                type = 2;
                collideM.defini = false;
                collideB.defini = true;
                if(this->collideB.xmin() > c.xmin()){
                    this->collideB.point1[0] = c.xmin();
                }
                if(this->collideB.xmax() < c.xmax()){
                    this->collideB.point2[0] = c.xmax();
                }
                if(this->collideB.ymin() > c.ymin()){
                    this->collideB.point1[1] = c.ymin();
                }
                if(this->collideB.ymax() < c.ymax()){
                    this->collideB.point2[1] = c.ymax();
                }
                if(this->collideB.zmin() > c.zmin()){
                    this->collideB.point1[2] = c.zmin();
                }
                if(this->collideB.zmax() < c.zmax()){
                    this->collideB.point2[2] = c.zmax();
                }
            }
        }
    }
    else {
        ColliderMesh c = obj->collideM;
        c.transform(obj->transform, 1);
        if(type == 2){
            if(!collideB.defini){
                collideB = ColliderBox(c.mesh);
                this->collideB.defini = true;
            }
            else{
                if(this->collideB.xmin() > c.xmin()){
                    this->collideB.point1[0] = c.xmin();
                }
                if(this->collideB.xmax() < c.xmax()){
                    this->collideB.point2[0] = c.xmax();
                }
                if(this->collideB.ymin() > c.ymin()){
                    this->collideB.point1[1] = c.ymin();
                }
                if(this->collideB.ymax() < c.ymax()){
                    this->collideB.point2[1] = c.ymax();
                }
                if(this->collideB.zmin() > c.zmin()){
                    this->collideB.point1[2] = c.zmin();
                }
                if(this->collideB.zmax() < c.zmax()){
                    this->collideB.point2[2] = c.zmax();
                }
            }
        }
        else{
            if(!collideM.defini){
                collideM.defini = false;
                collideB = ColliderBox(c.mesh);
                collideB.defini = true;
            }
            else{
                type = 2;
                collideM.defini = false;
                collideB.defini = true;
                if(this->collideB.xmin() > c.xmin()){
                    this->collideB.point1[0] = c.xmin();
                }
                if(this->collideB.xmax() < c.xmax()){
                    this->collideB.point2[0] = c.xmax();
                }
                if(this->collideB.ymin() > c.ymin()){
                    this->collideB.point1[1] = c.ymin();
                }
                if(this->collideB.ymax() < c.ymax()){
                    this->collideB.point2[1] = c.ymax();
                }
                if(this->collideB.zmin() > c.zmin()){
                    this->collideB.point1[2] = c.zmin();
                }
                if(this->collideB.zmax() < c.zmax()){
                    this->collideB.point2[2] = c.zmax();
                }
            }
        }
    }
    this->child->append(obj);
}
