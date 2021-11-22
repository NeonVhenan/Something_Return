#include <QDir>
#include <QFile>
#include <QString>
#include <QList>

#include "scene.h"

scene::scene()
{

    Scene::Scene() { }

     Scene::~Scene() { }

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


}

/*

 void Scene::generateListObject(QList *sceneObjects) {

      QString path;

      path = "/scene";

      QDir(path);
      QDir myPath(path);

      sceneObjects = myPath.entryList();
      sceneObjects.append();
  }

 Scene::Scene(QString *name) {

     this->name = name;
     this->objectList = new QList<GameObject*>();

     QList

     generateListObject(name)
 }*/
