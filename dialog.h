#ifndef DIALOG_H
#define DIALOG_H

#include <QtWidgets/QWidget>
#include "controlpanel.h"
#include "viewer3d.h"

class Dialog : public QWidget
{
private:
    ControlPanel * controlPanel;
    Viewer3d * viewer3d;
public:
    Dialog();
    ~Dialog();

};

#endif // DIALOG_H
