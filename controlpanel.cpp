#include "controlpanel.h"
#include <QLabel>
#include <QString>
ControlPanel::ControlPanel()
{
    layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignTop);

    panel = new QWidget();
    panel->setLayout(layout);

    QLabel * label = new QLabel(QString("TOTO"));
    layout->addWidget(label);

}

ControlPanel::~ControlPanel()
{

}

QWidget *ControlPanel::getWidget()
{
    return panel;
}

void ControlPanel::addComponent(QWidget *widget)
{
    layout->addWidget(widget);
}
