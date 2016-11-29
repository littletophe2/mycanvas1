#ifndef SUBPARTCONTROLLER_H
#define SUBPARTCONTROLLER_H

#include "viewer3d.h"
#include "controlpanel.h"

/**
 * @brief The SubpartController class
 * A controller
 */
class SubpartController
{
private:
    QString subpartName;
    QWidget * widgetForSubpart;
public:
    SubpartController(QString subpartName);
    virtual ~SubpartController();
    virtual void install(Viewer3d * viewer, ControlPanel * controlPanel)=0;

    /**
     * @brief getWidgetForSubpart
     * @return
     */
    QWidget * getWidgetForSubpart();


};


#endif // SUBPARTCONTROLLER_H
