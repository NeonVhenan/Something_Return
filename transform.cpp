#include "transform.h"

Transform::Transform(QQuaternion rotation, QVector3D translation, float scale)
{
    this->rotation = rotation;
    this->translation = translation;
    this->scale = scale;
    this->rotationSpe = QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f),0);
}

Transform::Transform(){}

Transform::~Transform(){}

void Transform::transform(QMatrix4x4 *mat){

    mat->rotate(this->rotationSpe);
    mat->translate(this->translation);
    mat->scale(this->scale);
    mat->rotate(this->rotation);
}


void Transform::addTranslation(QVector3D translation)
{
    this->translation += translation;
}

void Transform::addRotation(QQuaternion rotation)
{
    this->rotationSpe += rotation;
}
