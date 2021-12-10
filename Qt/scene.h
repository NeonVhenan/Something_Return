#ifndef SCENE_H
#define SCENE_H

#include <QDir>
#include <QFile>
#include <QString>

#include "gameobject.h"

class Scene
{
private:
    QString filename;
    QString name;
    QList<GameObject*> *objectList;

public:
    Scene();
    virtual ~Scene();
   Scene(GameObject *object);

    void generateListObject();
    Scene(QString name);
};

#endif // SCENE_H
