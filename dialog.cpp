#include "dialog.h"
#include "object3d.h"

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QForwardRenderer>
#include <QtGui/QScreen>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QCamera>
#include <Qt3DExtras/QFirstPersonCameraController>

Dialog::Dialog() : QWidget()
{
    // vue / canvas ?
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();

    // couleur de fond
    Qt3DExtras::QForwardRenderer * fr =  view->defaultFramegraph();
    fr->setClearColor(QColor(QRgb(0x884d4f)));

    QWidget *container = QWidget::createWindowContainer(view);
    QScreen * screen = view->screen();

    QSize screenSize = screen->size();

    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);

    QWidget *widget = new QWidget();
    // layout horizontal
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);

    // a droite les cases à cocher
    hLayout->addLayout(vLayout);

    // a gauche le viewer3d
    hLayout->addWidget(container, 1);

    widget->setWindowTitle(QStringLiteral("My shape"));

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    view->registerAspect(input);

    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

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


    // Show window
    widget->show();
    widget->resize(1200, 800);
}


Dialog::~Dialog()
{

}
