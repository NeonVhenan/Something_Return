#include <QDir>
#include <QFile>
#include <QString>
#include <QList>
#include <QIODevice>

#include "scene.h"

    Scene::Scene() { }

    Scene::~Scene() { }

    Scene::Scene(QString *name) {

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

 void Scene::generateListObject(QList<GameObject*> *sceneObjects, QString filename) {

     /*Structure du fichier :
      * chargement de ce dont a besoin un GameObject :
      * parent = monde our le GameObject précédent
      * mesh = mesh à appliquer (float à implémenter)
      * tranform = float
      * collider = float
      *
      * charger le gameobject en dernier
      *
      * inclure la ligne séparatrice
      *
      * Passer à l'objet suivant
      * */

      filename = "scene/scene.txt";
      QFile file(filename);

      QString separator = "--------------------"

      if(!file.open(QIODevice::ReadOnly)) {
            return;
      }

      QTextSream in(&file);
      QString line = in.readLine();

      while(!line.isNull() && line != separator) {

          return;
      }

      //Files list

  }

