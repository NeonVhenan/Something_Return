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

}

Scene::Scene() {

    /*
     * paramètres : coordonnées du plan de la première porte rencontrée
     * créer liste des enfants de monde correspondant à la scène actuelle
     * coordonnées de la porte forcant le chargement du dernier couloir de scène 1 + un autre couloir afin de créer la scène 2
     *
     */
}
