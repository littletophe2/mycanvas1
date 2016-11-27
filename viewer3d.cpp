#include "viewer3d.h"
#include "object3d.h"

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QFirstPersonCameraController>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DInput/QInputAspect>

#include <QScreen>
#include <QSize>

Viewer3d::Viewer3d()
{
    // vue / canvas ?
    Qt3DExtras::Qt3DWindow *viewer3d = new Qt3DExtras::Qt3DWindow();

    // couleur de fond
    Qt3DExtras::QForwardRenderer * fr =  viewer3d->defaultFramegraph();
    fr->setClearColor(QColor(QRgb(0xfffdfb)));

    QScreen * screen = viewer3d->screen();

    QSize screenSize = screen->size();

    container = QWidget::createWindowContainer(viewer3d);
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    viewer3d->registerAspect(input);

    // Root entity
    rootEntity = new Qt3DCore::QEntity();

    // Camera
    Qt3DRender::QCamera *cameraEntity = viewer3d->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // For camera controls
   /* Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);*/


    Qt3DExtras::QOrbitCameraController *camController2= new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController2->setCamera(cameraEntity);







    // Set root object of the scene
    viewer3d->setRootEntity(rootEntity);


}

Viewer3d::~Viewer3d()
{

}

// Widget of the viewer
QWidget *Viewer3d::getWidget()
{
    return container;
}

void Viewer3d::addObject(Object3d * obj3d)
{
    obj3d->setParent(rootEntity);
}
