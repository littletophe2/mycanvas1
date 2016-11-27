#include "viewer3d.h"
#include "object3d.h"

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QFirstPersonCameraController>
#include <Qt3DInput/QInputAspect>

#include <QScreen>
#include <QSize>

Viewer3d::Viewer3d()
{
    // vue / canvas ?
    Qt3DExtras::Qt3DWindow *viewer3d = new Qt3DExtras::Qt3DWindow();

    // couleur de fond
    Qt3DExtras::QForwardRenderer * fr =  viewer3d->defaultFramegraph();
    fr->setClearColor(QColor(QRgb(0x884d4f)));

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
    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    Object3d *barel = new Object3d(rootEntity);
    barel->setMesh(QStringLiteral("qrc:/metal_barrel.obj"));
    float s= 0.1f;
    barel->getTransform()->setScale3D(QVector3D(s,s,s));
    Qt3DExtras::QPhongMaterial *barelMaterial = new Qt3DExtras::QPhongMaterial();
    barelMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));
    barel->setMaterial(barelMaterial);

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
