#include "colliderbox.h"


ColliderBox::ColliderBox()
{

}

ColliderBox::ColliderBox(QVector3D point1, QVector3D point2){
    this->point1 = point1;
    this->point2 = point2;
    this->defini = true;
}
