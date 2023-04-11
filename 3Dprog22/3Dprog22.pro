QT          += core gui widgets opengl

TEMPLATE    = app
CONFIG      += c++17

TARGET      = 3D-programmering

SOURCES += main.cpp \
    camera.cpp \
    cube.cpp \
    curve.cpp \
    door.cpp \
    hightmap.cpp \
    hus.cpp \
    interactiveobject.cpp \
    items.cpp \
    lamp.cpp \
    logger.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    phong.cpp \
    point.cpp \
    renderwindow.cpp \
    shader.cpp \
    texture.cpp \
    trianglesurface.cpp \
    trophy.cpp \
    vertex.cpp \
    visualobject.cpp \
    xyz.cpp

HEADERS += \
    ../../../../Documents/libraries/stb_image.h \
    camera.h \
    cube.h \
    curve.h \
    door.h \
    geometryengine.h \
    hightmap.h \
    hus.h \
    interactiveobject.h \
    items.h \
    lamp.h \
    logger.h \
    mainwidget.h \
    mainwindow.h \
    phong.h \
    point.h \
    renderwindow.h \
    shader.h \
    texture.h \
    trianglesurface.h \
    trophy.h \
    vertex.h \
    visualobject.h \
    xyz.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    Phong.frag \
    Phong.vert \
    plainshader.frag \
    plainshader.vert \
    texturefragment.frag \
    texturevertex.vert
