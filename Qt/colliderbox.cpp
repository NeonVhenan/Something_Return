#include "colliderbox.h"
#include "geometryengine.h"


ColliderBox::ColliderBox()
{

}

ColliderBox::ColliderBox(QVector3D point1, QVector3D point2)
{
    this->point1 = point1;
    this->point2 = point2;
    this->defini = true;
}

void ColliderBox::transform(Transform t)
{
    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);
    GeometryEngine::monde->transform.transform(&mat);
    t.transform(&mat);
    QVector4D p1 = QVector4D(point1.x(), point1.y(), point1.z(), 1.0);
    p1 = mat * p1;
    point1 = QVector3D(p1.x(), p1.y(), p1.z());
    QVector4D p2 = QVector4D(point2.x(), point2.y(), point2.z(), 1.0);
    p2 = mat * p2;
    point2 = QVector3D(p2.x(), p2.y(), p2.z());
}

bool ColliderBox::collision(ColliderBox * c)
{
    printf("%f %f  %f %f  %f %f            %f %f  %f %f  %f %f\n", c->xmin(), c->xmax(), c->ymin(), c->ymax(), c->zmin(), c->zmax(), xmin(), xmax(), ymin(), ymax(), zmin(), zmax());
    if(c->xmin() >= xmin() && c->xmin() <= xmax()){
        if(c->ymin() >= ymin() && c->ymin() <= ymax()){
            if(c->zmin() >= zmin() && c->zmin() <= zmax())
                return true;
            if(c->zmin() < zmin() && c->zmax() > zmin())
                return true;
        }
        else{
            if(c->ymin() < ymin() && ymax() > ymin()){
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
               if(c->ymin() < ymin() && ymax() > ymin()){
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
