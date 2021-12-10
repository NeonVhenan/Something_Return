#include <QDir>
#include <QFile>
#include <QString>
#include <QList>
#include <QIODevice>
#include <stdio.h>

#include "scene.h"

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

 void Scene::generateListObject() {

     /*Structure du fichier :
      * chargement de ce dont a besoin un GameObject :
      * parent = monde ou le GameObject précédent
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

     printf("hello\n");

      QFile file(name);

      QString separator = "--------------------";

      //Files list
      if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
          printf("non\n");
          return;
      }

      printf("blbl \n");

      while(!file.atEnd()) {

          printf("work \n");

          QByteArray line = file.readLine();
          printf("% \n", line);
      }

      file.close();

  }
