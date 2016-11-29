#include "subpartcontroller.h"
#include <iostream>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>

SubpartController::SubpartController(QString subpartName)
{
    this->subpartName=subpartName;
    std::cout << "SubpartController";
}

SubpartController::~SubpartController()
{
    std::cout << "SubpartController";
}

QWidget *SubpartController::getWidgetForSubpart()
{
   if (widgetForSubpart==nullptr)
   {
       widgetForSubpart = new QWidget();
       QVBoxLayout * layout = new QVBoxLayout();
       widgetForSubpart->setLayout(layout);
       layout->addWidget(new QLabel(subpartName));
   }
   return widgetForSubpart;
}

