#ifndef VIEWER3D_H
#define VIEWER3D_H

#include <QtWidgets/QWidget>
#include <Qt3DCore/QEntity>

/**
 * @brief The Viewer3d class The 3D viewer of the application
 */
class Viewer3d
{
private:
    // The component that contains the viewer
    QWidget *container;
    // The root of the framegraph
    Qt3DCore::QEntity *rootEntity;

public:
    Viewer3d();
    ~Viewer3d();

    // Widget of the viewer
    QWidget *getWidget();


};

#endif // VIEWER3D_H
