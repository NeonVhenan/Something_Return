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

Scene::~Scene() { }

Scene::Scene(QString name) {

    this->name = name;
}

Scene::Scene(QVector3D v1, Scene s1, QVector3D v2, Scene s2, int type_scene QVector3D translation, float angle) {

    passage1 = v1;
    passage2 = v2;

    previous = s1;
    next = s2;

    switch(type_scene) {

    case 1:

        addGameObject(listeObjets.push_back(new GameObject(monde, loadOff("../Something_Return/Qt/corridor_back.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,20.0f) + translation), 1.0f), true)));
        break;

    case 2:

        break;

    default:

        break;
    }
}

void Scene::addGameObject(GameObject* object) {

    if(qFind(objectList.begin(), objectList.end(), object) != objectList.end()) {

        objectList.append(object);
        return;
    }

    objectList.push_back(object);
}

void Scene::deleteGameObject(GameObject* object) {

    int size = objectList.size();

    for(unsigned int i = 0; i < size; i++) {

        objectList.removeOne(object);
        //objectList.erase(remove(objectList.begin(), objectList.end(), object), objectList.end());

    }
}

/*QList<GameObject*> Scene::findChildren(const GameObject* object) {

    QList<GameObject*> result;
    int size = objectList.size();

    for(int i = 0; i < size; i++) {

        if(objectList[i] == 0 || objectList[i] == object) {

            continue;
        }

        GameObject* iterator = objectList[i]->parent;

        if(iterator != 0) {

            result.push_back(objectList[i]);
            continue;
        }

        iterator = iterator->parent;
    }

    return result;
}*/

void Scene::updateScene(GameObject* object) {

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    GeometryEngine::monde.transform.transform(&mat);

    if(step == 1) {

        QVector3D v = passage1 * mat;

        if((v.x >= -0.5 && v.x <= 0.5) && (v.z >= -0.5 && v.z <= 0.5)) { //si le point de passage1 est à notre niveau

            //animation des portes
            previous.unloadScene();
            step = 2;
        }
    }

    else {

        if(step == 2) {

            QVector3D v = passage2 * mat;

            if((v.x >= -0.5 && v.x <= 0.5) && (v.z >= -0.5 && v.z <= 0.5)) { //si le point de passage2 est à notre niveau

                next.loadScene();
                //animation des portes
                step = 3;
            }
        }
    }
}

void Scene::loadScene() {

    for(unsigned int = 0; i < objectList.size(); i++) {

        GeometryEngine::monde.addEnfant(objectList[i]);
    }

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    GeometryEngine::monde.transform.transform(&mat);

    MainWidget::scenes_en_cours.push_back(this);
}

void Scene::unloadScene() {

    for(unsigned int = 0; i < objectList.size(); i++) {

        GeometryEngine::monde.child.remove(objectList[i]);
    }

    MainWidget::scenes_en_cours.push_back(this);
}


