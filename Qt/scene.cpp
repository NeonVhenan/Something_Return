#include <QDir>
#include <QFile>
#include <QString>
#include <QList>

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

 void Scene::generateListObject(QList<GameObject*> *sceneObjects, QString path) {

      path = "/scene";
      QDir mypath(path);

      /*if(!mypath(path).exists()) {

          return;
      }

      //Files list
      sceneObjects = myPath.entryList(QList() << "*.obj", QDir::Files);
      sceneObjects->append();*/
  }

