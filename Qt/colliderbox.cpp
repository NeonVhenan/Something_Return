#include "colliderbox.h"
#include "geometryengine.h"

ColliderBox::ColliderBox()
{
    this->defini = false;
    this->point1 = QVector3D(0.0, 0.0, 0.0);
    this->point2 = QVector3D(0.0, 0.0, 0.0);
}


ColliderBox::ColliderBox(Mesh mesh)
{
    float xmin = mesh.vertices[0].position[0];
    float xmax = mesh.vertices[0].position[0];
    float ymin = mesh.vertices[0].position[1];
    float ymax = mesh.vertices[0].position[1];
    float zmin = mesh.vertices[0].position[2];
    float zmax = mesh.vertices[0].position[2];
    for(unsigned int i = 1; i  < mesh.vertexNumber; i++){
        if(xmin > mesh.vertices[i].position[0])
            xmin = mesh.vertices[i].position[0];
        else{
            if(xmax < mesh.vertices[i].position[0])
                xmax = mesh.vertices[i].position[0];
        }
        if(ymin > mesh.vertices[i].position[1])
            ymin = mesh.vertices[i].position[1];
        else{
            if(ymax < mesh.vertices[i].position[1])
                ymax = mesh.vertices[i].position[1];
        }
        if(zmin > mesh.vertices[i].position[2])
            zmin = mesh.vertices[i].position[2];
        else{
            if(zmax < mesh.vertices[i].position[2])
                zmax = mesh.vertices[i].position[2];
        }
    }

    this->point1 = QVector3D(xmin-0.15, ymin-0.15, zmin-0.15);
    this->point2 = QVector3D(xmax+0.15, ymax+0.15, zmax+0.15);
    this->defini = true;
}

ColliderBox::ColliderBox(QVector3D p1, QVector3D p2){
    this->point1 = p1;
    this->point2 = p2;
    this->defini = true;
}

void ColliderBox::transform(Transform t, int i)
{
    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);
    if(i != 0)
        GeometryEngine::monde->transform.transform(&mat);
    t.transform(&mat);
    QVector4D p1 = QVector4D(point1.x(), point1.y(), point1.z(), 1.0);
    p1 = mat * p1;
    QVector4D p2 = QVector4D(point2.x(), point2.y(), point2.z(), 1.0);
    p2 = mat * p2;
    float tmp;
    if(p2.x() < p1.x()){
        tmp = p2.x();
        p2[0] = p1.x();
        p1[0] = tmp;
    }
    if(p2.y() < p1.y()){
        tmp = p2.y();
        p2[1] = p1.y();
        p1[1] = tmp;
    }
    if(p2.z() < p1.z()){
        tmp = p2.z();
        p2[2] = p1.z();
        p1[2] = tmp;
    }
    this->point1 = QVector3D(p1.x(), p1.y(), p1.z());
    this->point2 = QVector3D(p2.x(), p2.y(), p2.z());
}

bool ColliderBox::collision(ColliderBox * c)
{
    if(c->xmin() >= xmin() && c->xmin() <= xmax()){
        if(c->ymin() >= ymin() && c->ymin() <= ymax()){
            if(c->zmin() >= zmin() && c->zmin() <= zmax())
                return true;
            if(c->zmin() < zmin() && c->zmax() > zmin())
                return true;
        }
        else{
            if(c->ymin() < ymin() && c->ymax() > ymin()){
                if(c->zmin() >= zmin() && c->zmin() <= zmax())
                    return true;
                if(c->zmin() < zmin() && c->zmax() > zmin())
                    return true;
            }
        }
    }
    else{
       if(c->xmin() < xmin() && c->xmax() > xmax()){
           if(c->ymin() >= ymin() && c->ymin() <= ymax()){
               if(c->zmin() >= zmin() && c->zmin() <= zmax())
                   return true;
               if(c->zmin() < zmin() && c->zmax() > zmin())
                   return true;
           }
           else{
               if(c->ymin() < ymin() && c->ymax() > ymin()){
                   if(c->zmin() >= zmin() && c->zmin() <= zmax())
                       return true;
                   if(c->zmin() < zmin() && c->zmax() > zmin())
                       return true;
               }
           }
       }
    }
    return false;
}

float ColliderBox::xmin(){
    return this->point1.x();
}

float ColliderBox::xmax(){
    return this->point2.x();
}

float ColliderBox::ymin(){
    return this->point1.y();
}

float ColliderBox::ymax(){
    return this->point2.y();
}

float ColliderBox::zmin(){
    return this->point1.z();
}

float ColliderBox::zmax(){
    return this->point2.z();
}
