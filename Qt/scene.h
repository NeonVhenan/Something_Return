#ifndef SCENE_H
#define SCENE_H

#include <QDir>
#include <QFile>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QIODevice>
#include <QtAlgorithms>
#include <QStack>

#include <stdio.h>

#include "scene.h"
#include "gameobject.h"
#include "geometryengine.h"

class Scene
{
protected:
    QString name;
    QList<GameObject*> *objectList;
    QVector3D passage1;
    QVector3D passage2;
    int step = 1;
    Scene * previous;
    Scene * next;
    float angle;
    QVector3D translation;
    int type_scene;

public:
    Scene();
    virtual ~Scene();
    Scene(QString name);
    Scene(QVector3D v1, Scene * s1, int type_scene, QVector3D translation, float angle);

    Scene(GameObject *object);
    //QList<GameObject*> findChildren(const GameObject* object);

    //void generateListObject();
    void loadScene();
    void unloadScene();

    void addGameObject(GameObject* object);
    void deleteGameObject(GameObject* object);

    void updateScene();
};

#endif // SCENE_H
