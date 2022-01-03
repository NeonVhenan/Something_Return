#ifndef SCENE_H
#define SCENE_H

#include <QDir>
#include <QFile>
#include <QString>
#include <QList>

#include "gameobject.h"

class Scene
{
protected:
    QString name;
    QList<GameObject*> objectList;

public:
    Scene();
    virtual ~Scene();
    Scene(QString name);
    Scene(GameObject *object);
    QList<GameObject*> findChildren(const GameObject* object);

    //void generateListObject();
    void addGameObject(GameObject* object);
    void updateGameObject(GameObject* object);
    void deleteGameObject(GameObject* object);
};

#endif // SCENE_H
