#ifndef SCENE_H
#define SCENE_H

#include <QDir>
#include <QFile>
#include <QString>
#include <QVector>

#include "gameobject.h"

class Scene
{
protected:
    QString name;
    QVector<GameObject*> objectList;

public:
    Scene();
    virtual ~Scene();
    Scene(QString name);
    Scene(GameObject *object);
    QVector<GameObject*> findChildren(const GameObject* object);

    //void generateListObject();
    void addGameObject(GameObject* object);
    void updateGameObject(GameObject* object);
    void deleteGameObject(GameObject* object);
};

#endif // SCENE_H
