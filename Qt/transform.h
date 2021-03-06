#ifndef TRANSFORM_H
#define TRANSFORM_H


#include <QOpenGLFunctions_3_1>
#include <QVector3D>
#include <QQuaternion>
#include <QMatrix4x4>

class Transform
{
public:
    Transform();
    Transform(QQuaternion rotation, QVector3D translation, float scale);
    ~Transform();
    void addTranslation(QVector3D translation);
    void addRotation(float angle);

    QQuaternion rotation;
    QVector3D translation;
    float scale;
    float angle;

    void transform(QMatrix4x4 *mat);

};

#endif // TRANSFORM_H
