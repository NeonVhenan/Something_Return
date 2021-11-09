#include "transform.h"

Transform::Transform(QQuaternion rotation, QVector3D translation, float scale)
{
    this->rotation = rotation;
    this->translation = translation;
    this->scale = scale;
}

Transform::Transform(){}

Transform::~Transform(){}

void Transform::transform(QMatrix4x4 *mat){

    mat->translate(this->translation);
    mat->scale(this->scale);
    mat->rotate(this->rotation);
}


void Transform::addTranslation(QVector3D translation)
{
    this->translation += translation;
}
