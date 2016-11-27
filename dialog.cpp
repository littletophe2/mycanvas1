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
}


Dialog::~Dialog()
{

}
