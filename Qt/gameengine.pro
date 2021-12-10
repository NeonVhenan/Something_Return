QT       += core gui widgets

TARGET = gameengine
TEMPLATE = app

SOURCES += main.cpp \
    collider.cpp \
    colliderbox.cpp \
    collidermesh.cpp \
    gameobject.cpp \
    mesh.cpp \
    transform.cpp \
    scene.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    collider.h \
    colliderbox.h \
    collidermesh.h \
    gameobject.h \
    mainwidget.h \
    geometryengine.h \
    mesh.h \
    transform.h \
    scene.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
target.path = $$[YOUR_PATH]
INSTALLS += target

DISTFILES += \
    scene/scene.txt
