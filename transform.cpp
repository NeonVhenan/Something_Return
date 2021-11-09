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
    mat->scale(this->scale);
    mat->translate(this->translation);
    mat->rotate(this->rotation);
}
