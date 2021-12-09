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

void ColliderBox::transform(Transform t, int i)
{
    //printf("AVANT : %f %f %f         %f %f %f\n",point1.x(), point1.y(), point1.z(), point2.x(),point2.y(), point2.z());
    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);
    if(i != 0)
        GeometryEngine::monde->transform.transform(&mat);
    //printf("%f %f %f   %f %f %f   %f %f %f     %f\n",mat(0,0), mat(0,1), mat(0,2), mat(1,0), mat(1,1), mat(1,2),mat(2,0),mat(2,1),mat(2,2), mat(2,3));
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
    //printf("APRES : %f %f %f         %f %f %f\n",point1.x(), point1.y(), point1.z(), point2.x(),point2.y(), point2.z());
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
