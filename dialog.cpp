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
#include <subpartmaterialset.h>
#include <stdio.h>

Dialog::Dialog() : QWidget()
{
    controlPanel = new ControlPanel();
    viewer3d = new Viewer3d();

    QWidget *dialogWindow = new QWidget();
    // layout horizontal
    QHBoxLayout *hLayout = new QHBoxLayout(dialogWindow);



    // a droite les cases à cocher
    hLayout->addWidget(controlPanel->getWidget());

    // a gauche le viewer3d
    hLayout->addWidget(viewer3d->getWidget(), 1);

    dialogWindow->setWindowTitle(QStringLiteral("My shape"));

    // Show window
    dialogWindow->show();
    dialogWindow->resize(1200, 800);

    // Definition of the barel
    Object3d *barel = new Object3d();
    barel->setMesh(QStringLiteral("qrc:/metal_barrel.obj"));
    float s= 0.1f;
    barel->getTransform()->setScale3D(QVector3D(s,s,s));
    Qt3DExtras::QPhongMaterial *barelMaterial = new Qt3DExtras::QPhongMaterial();
    barelMaterial->setDiffuse(QColor(QRgb(0xfef32b)));
    barel->setMaterial(barelMaterial);

    SubpartMaterialSet * sms = new SubpartMaterialSet("Barel");

    std::vector<Qt3DRender::QMaterial*> * materials = new std::vector<Qt3DRender::QMaterial*>();
    materials->push_back(barelMaterial);
    materials->push_back(barelMaterial);

    std::vector<QString*> * names = new std::vector<QString*>();
    names->push_back(new QString("Material A"));
    names->push_back(new QString("Material B"));

    sms->init(barel, materials, names);
    sms->install(viewer3d, controlPanel);


}


Dialog::~Dialog()
{

}
