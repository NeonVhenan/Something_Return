#include "colliderbox.h"


ColliderBox::ColliderBox()
{

}


ColliderBox::ColliderBox(QVector3D point1, QVector3D point2, QVector3D point3, QVector3D point4, QVector3D point5, QVector3D point6, QVector3D point7, QVector3D point8){
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    this->point4 = point4;
    this->point5 = point5;
    this->point6 = point6;
    this->point7 = point7;
    this->point8 = point8;
}
