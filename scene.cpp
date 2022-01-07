#include "scene.h"
#include "mainwidget.h"

Scene::~Scene() { }

Scene::Scene(QString name) {

    this->name = name;
}

Scene::Scene(QVector3D v1, Scene * s1, int type_scene, QVector3D translation, float angle) {

    passage1 = v1;

    previous = s1;
    int i;
    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    GeometryEngine::monde->transform.transform(&mat);

    switch(type_scene) {

    case 1:
        translation = translation * mat;
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/back.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,-20.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(8.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,6.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/back.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(8.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));

        i = rand()%3 + 1;
        next = new Scene(QVector3D(0.0,0.0,-1.0)*mat+translation, this, i, QVector3D(0.0f,0.0f,-20.0f)+translation, angle);
        passage2 = QVector3D(0.0,0.0,-19.0)*mat+translation;
        break;

    case 2:
        translation = translation * mat;
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/back.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90 + angle), (QVector3D(20.0f,0.0f,-18.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(8.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90 + angle), (QVector3D(10.0f,0.0f,-10.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90 + angle), (QVector3D(14.0f,0.0f,-6.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,6.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90 + angle), (QVector3D(10.0f,0.0f,-10.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), -90 + angle), (QVector3D(10.0f,6.0f,-10.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/back.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(8.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        i = rand()%3 + 1;
        next = new Scene(QVector3D(0.0,0.0,-1.0)*mat+translation, this, i, QVector3D(28.0f,0.0f,-28.0f)+translation, -90+angle);
        passage2 = QVector3D(15.0f,0.0f,-24.0f)*mat+translation;
        break;

    case 3:
        translation = translation * mat;
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/back.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90 + angle), (QVector3D(-20.0f,0.0f,-18.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(8.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90 + angle), (QVector3D(-2.0f,0.0f,-10.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/wall2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90 + angle), (QVector3D(-6.0f,0.0f,-6.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor1.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,6.0f,0.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90 + angle), (QVector3D(-10.0f,0.0f,-10.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/floor2.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90 + angle), (QVector3D(-10.0f,6.0f,-10.0f) + translation), 1.0f), true));
        addGameObject(new GameObject(GeometryEngine::monde, GeometryEngine::loadOff("../Something_Return/Qt/back.off"), Transform(QQuaternion::fromAxisAndAngle(QVector3D(8.0f, 1.0f, 0.0f), 00 + angle), (QVector3D(0.0f,0.0f,0.0f) + translation), 1.0f), true));
        i = rand()%3 + 1;
        next = new Scene(QVector3D(0.0,0.0,-1.0)*mat+translation, this, i, QVector3D(-12.0f,0.0f,-20.0f)+translation, 90+angle);
        passage2 = QVector3D(-11.0f,0.0f,-24.0f)*mat+translation;
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
    objectList.removeOne(object);
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

void Scene::updateScene() {

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    GeometryEngine::monde->transform.transform(&mat);

    if(step == 1) {

        if(previous == NULL)
            step = 2;
        else{
            QVector3D v = passage1 * mat;

            if((v.x() >= -0.5 && v.x() <= 0.5) && (v.z() >= -0.5 && v.z() <= 0.5)) { //si le point de passage1 est à notre niveau

                //animation des portes
                previous->unloadScene();
                step = 2;
            }
        }
    }

    else {

        if(step == 2) {

            QVector3D v = passage2 * mat;

            if((v.x() >= -0.5 && v.x() <= 0.5) && (v.z() >= -0.5 && v.z() <= 0.5)) { //si le point de passage2 est à notre niveau

                next->loadScene();
                //animation des portes
                step = 3;
            }
        }
    }
}

void Scene::loadScene() {

    for(int i = 0; i < objectList.size(); i++) {

        GeometryEngine::monde->addEnfant(objectList[i]);
    }

    QMatrix4x4 mat = QMatrix4x4(1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0);

    GeometryEngine::monde->transform.transform(&mat);

    MainWidget::scenes_en_cours->push_back(this);
}

void Scene::unloadScene() {

    for(int i = 0; i < objectList.size(); i++) {

        GeometryEngine::monde->child->removeOne(objectList[i]);
    }

    MainWidget::scenes_en_cours->push_back(this);
}


