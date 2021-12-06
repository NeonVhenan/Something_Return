#ifndef SCENE_H
#define SCENE_H

#include <QDir>
#include <QFile>
#include <QString>
#include <QIODevice>

#include "gameobject.h"

class Scene
{
private:
    QString filename;
    QString path;
    //QList<GameObject*> *objectList;

public:
    Scene();
    virtual ~Scene();
   Scene(GameObject *object);

    void generateListObject(QList<GameObject*> *sceneObjects, QString filename);
    Scene(QString *name);
};

#endif // SCENE_H
