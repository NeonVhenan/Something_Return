#include "collidermesh.h"
#include "geometryengine.h"

ColliderMesh::ColliderMesh()
{
    this->defini = false;
}


ColliderMesh::ColliderMesh(Mesh mesh)
{
    this->defini = true;
    this->mesh = mesh;
}


void ColliderMesh::transform(Transform t, int i)
{
    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);
    if(i != 0)
        GeometryEngine::monde->transform.transform(&mat);
    t.transform(&mat);
    mesh.transform(mat);
}

bool ColliderMesh::collision(ColliderBox * c)
{
    if(!ColliderBox(this->mesh).collision(c))
        return false;
    QVector3D p;
    for(unsigned int i = 0; i < mesh.vertexNumber; i++){
        p = mesh.vertices[i].position;
        if((p.x() >= c->xmin() && p.x() <= c->xmax()) &&
           (p.y() >= c->ymin() && p.y() <= c->ymax()) &&
           (p.z() >= c->zmin() && p.z() <= c->zmax()))
            return true;
    }
    return false;
}

float ColliderMesh::xmin(){
    float xmin = mesh.vertices[0].position[0];
    for(unsigned int i = 1; i  < mesh.vertexNumber; i++){
        if(xmin < mesh.vertices[i].position[0])
            xmin = mesh.vertices[i].position[0];
    }
    return xmin;
}

float ColliderMesh::xmax(){
    float xmax = mesh.vertices[0].position[0];
    for(unsigned int i = 1; i  < mesh.vertexNumber; i++){
        if(xmax > mesh.vertices[i].position[0])
            xmax = mesh.vertices[i].position[0];

    }
    return xmax;
}

float ColliderMesh::ymin(){
    float ymin = mesh.vertices[0].position[1];
    for(unsigned int i = 1; i  < mesh.vertexNumber; i++){
        if(ymin < mesh.vertices[i].position[1])
            ymin = mesh.vertices[i].position[1];
    }
    return ymin;
}

float ColliderMesh::ymax(){
    float ymax = mesh.vertices[0].position[1];
    for(unsigned int i = 1; i  < mesh.vertexNumber; i++){
        if(ymax > mesh.vertices[i].position[1])
            ymax = mesh.vertices[i].position[1];
    }
    return ymax;
}

float ColliderMesh::zmin(){
    float zmin = mesh.vertices[0].position[2];
    for(unsigned int i = 1; i  < mesh.vertexNumber; i++){
        if(zmin < mesh.vertices[i].position[2])
            zmin = mesh.vertices[i].position[2];
    }
    return zmin;
}

float ColliderMesh::zmax(){
    float zmax = mesh.vertices[0].position[2];
    for(unsigned int i = 1; i  < mesh.vertexNumber; i++){
        if(zmax > mesh.vertices[i].position[2])
            zmax = mesh.vertices[i].position[2];
    }
    return zmax;
}
