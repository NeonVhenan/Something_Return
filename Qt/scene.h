#ifndef SCENE_H
#define SCENE_H

#include <QDir>
#include <QFile>
#include <QString>
#include <QList>

#include "gameobject.h"

class Scene {

protected:
    QString name;
    QList<GameObject*> objectList;
    QVector3D passage1;
    QVector3D passage2;
    int step = 1;
    Scene previous;
    Scene next;

public:
    Scene();
    virtual ~Scene();
    Scene(QString name);

    Scene(GameObject *object);
    //QList<GameObject*> findChildren(const GameObject* object);

    //void generateListObject();
    void loadScene();
    void unloadScene();

    void addGameObject(GameObject* object);
    void deleteGameObject(GameObject* object);

    void updateScene(GameObject* object);
};

#endif // SCENE_H
