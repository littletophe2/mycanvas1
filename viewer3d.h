#ifndef VIEWER3D_H
#define VIEWER3D_H

#include "object3d.h"
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

    /**
     * @brief getWidget Widget of the viewer
     * @return
     */
    QWidget *getWidget();

    /**
     * @brief addObject Add an object to the viewer
     * @param obj3d
     */
    void addObject(Object3d * obj3d);


};

#endif // VIEWER3D_H
