QT       += core gui widgets

TARGET = gameengine
TEMPLATE = app

SOURCES += main.cpp \
    collider.cpp \
    colliderbox.cpp \
    collidercapsule.cpp \
    gameobject.cpp \
    mesh.cpp \
    scene.cpp \
    transform.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    collider.h \
    colliderbox.h \
    collidercapsule.h \
    gameobject.h \
    mainwidget.h \
    geometryengine.h \
    mesh.h \
    scene.h \
    transform.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
target.path = $$[YOUR_PATH]
INSTALLS += target
