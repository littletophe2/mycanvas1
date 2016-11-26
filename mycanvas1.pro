TEMPLATE = app

QT += 3dcore 3drender 3dinput 3dextras
QT += widgets

SOURCES += main.cpp \
    dialog.cpp \
    object3d.cpp

HEADERS += \
    dialog.h \
    object3d.h

RESOURCES += \
    asset.qrc
