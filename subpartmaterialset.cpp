#include <iostream>
#include "subpartmaterialset.h"
#include <QtWidgets/QLabel>
SubpartMaterialSet::SubpartMaterialSet(QString subpartName) : SubpartController(subpartName)
{
    std::cout << "SubpartMaterialSet";
}

SubpartMaterialSet::~SubpartMaterialSet()
{
    std::cout << "~SubpartMaterialSet";
}



void SubpartMaterialSet::install(Viewer3d *viewer, ControlPanel *controlPanel)
{
    viewer->addObject(obj3d);

    QWidget * subpartWidget = getWidgetForSubpart();

    std::vector<QString*>::iterator it;
    for(it=names->begin() ; it < names->end(); it++)
    {
        QString str = **it;
        QLabel * label = new QLabel(str);
        QLayout * layout = subpartWidget->layout();
        layout->addWidget(label);
    }

    controlPanel->addComponent(subpartWidget);
}

void SubpartMaterialSet::init(Object3d *obj3d, std::vector<Qt3DRender::QMaterial*> *materials, std::vector<QString*> *names)
{
    this->obj3d=obj3d;
    this->materials=materials;
    this->names=names;
}
