#include "transform.h"


Transform::Transform(QQuaternion rotation, QVector3D translation, float scale)
{
    this->rotation = rotation;
    this->translation = translation;
    this->scale = scale;
    this->angle = 0;
}

Transform::Transform(){}

Transform::~Transform(){}

void Transform::transform(QMatrix4x4 *mat){

    mat->scale(this->scale);
    mat->rotate(this->rotation);
    mat->translate(this->translation);
}


void Transform::addTranslation(QVector3D translation)
{
    this->translation += translation;
}

void Transform::addRotation(float angle)
{
    this->angle += angle;
    this->rotation = QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f),angle);
}
