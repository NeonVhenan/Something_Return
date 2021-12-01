#ifndef SCENE_H
#define SCENE_H

#include <QDir>
#include <QFile>
#include <QString>

#include "gameobject.h"

class Scene
{
private:
    QString *name;
    QList<GameObject*> *objectList;

public:
    Scene();
    virtual ~Scene();
   // Scene(GameObject *object);

    void generateListObject(QList<GameObject*> *sceneObjects);



};

#endif // SCENE_H
