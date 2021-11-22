#include "collidercapsule.h"


ColliderCapsule::ColliderCapsule()
{

}

ColliderCapsule::ColliderCapsule(QVector3D point1, QVector3D point2, float rayon){
    this-> point1 = point1;
    this-> point2 = point2;
    this->rayon = rayon;
}


bool ColliderCapsule::collision(ColliderBox c){

}
