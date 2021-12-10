#include <QDir>
#include <QFile>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QIODevice>

#include <stdio.h>

#include "scene.h"
#include "gameobject.h"
#include "geometryengine.h"

    Scene::Scene() { }

    Scene::~Scene() { }

    Scene::Scene(QString name) {

        this->name = name;
    }

    /*
     * Créer une arborescence suivant ce modèle :
     * lire dans un dossier le nom des GameObjects à charger
     * trouver dans leur(s) dossier(s) enfant(s) les fichiers contenant
     * le Mesh (texture/couleur ?), (la Transformation ?) et le Collider
     *  puis charger les objets dans l'odre de la liste
     *
     * Transform à l'identité si rien
     *
     * Mesh -> ID through ObjFile?
     */

 /*void Scene::generateListObject() {

     /*Structure du fichier :
      * chargement de ce dont a besoin un GameObject :
      * parent = monde ou le GameObject précédent
      * mesh = mesh à appliquer (int à implémenter)
      * tranform = float
      * collider = float
      *
      * charger le gameobject en dernier
      *
      * inclure la ligne séparatrice
      *
      * Passer à l'objet suivant
      *

      QFile file(name);

      QString separator = "--------------------";

      //Files list
      if(!file.open(QIODevice::ReadOnly)) {

          return;
      }

      printf("blbl \n");

      QTextStream in(&file);

      while(!in.atEnd()) {

          printf("work \n");

          QString line = in.readLine();
          in << "Line is: " << line << "\n";
      }

      file.close();
  }*/

    //VA PAS MARCHER

    void generateListObjects(QList<GameObject*> listeObjets) {

        int type = listeObjets.size();
        unsigned int i = 0;
        GeometryEngine::monde;

        switch (type) {

            case 1 :

                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(3.5, 0.0, -20.0), QVector3D(4.5, 6.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 00), QVector3D(0.0f,0.0f,0.0f), 1.0f),
                                                     ColliderBox(QVector3D(0, -1.0,0), QVector3D(0, -1.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0), QVector3D(0.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(-4.5, 0.0,-20.0), QVector3D(-3.5, 6.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                break;

            case 2 :

                //Left
                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(3.5, 0.0, -20.0), QVector3D(4.5, 6.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90),
                                                                QVector3D(24.0f,0.0f,0.0f), 1.0f), ColliderBox(QVector3D(0, -1.0,0), QVector3D(0, -1.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,-4.0f), 1.0f), ColliderBox(QVector3D(-4.5, 0.0,-20.0), QVector3D(-3.5, 6.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                //Right
                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(1), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,20.0f), 1.0f), ColliderBox(QVector3D(3.5, 0.0, -20.0), QVector3D(4.5, 6.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(2), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90),
                                                           QVector3D(24.0f,0.0f,20.0f), 1.0f), ColliderBox(QVector3D(0, -1.0,0), QVector3D(0, -1.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                listeObjets.push_back(new GameObject(GeometryEngine::monde, Mesh(3), Transform(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 90), QVector3D(24.0f,0.0f,24.0f), 1.0f), ColliderBox(QVector3D(-4.5, 0.0,-20.0), QVector3D(-3.5, 6.0, 0.0))));
                listeObjets[i]->arrayBuf.create();
                listeObjets[i]->indexBuf.create();

                GeometryEngine::monde->addEnfant(listeObjets[i++]);

                break;

        }
    }
