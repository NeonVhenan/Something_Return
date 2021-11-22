#ifndef SCENE_H
#define SCENE_H

#include "gameobject.h"

class Scene
{
private:
    QString *name;
    QList *objectList;

public:
    Scene();
    virtual ~Scene();
   // Scene(GameObject *object);

  //  void generateListObject(QList *sceneObjects);



};

#endif // SCENE_H
