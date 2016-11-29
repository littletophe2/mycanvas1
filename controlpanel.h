#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QVBoxLayout>
#include <QWidget>

class ControlPanel
{
private:
    QVBoxLayout * layout;
    QWidget *panel;

public:
    ControlPanel();
    ~ControlPanel();
    QWidget *getWidget();

    void addComponent(QWidget * widget);

};

#endif // CONTROLPANEL_H
