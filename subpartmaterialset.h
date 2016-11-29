#ifndef SUBPARTMATERIALSET_H
#define SUBPARTMATERIALSET_H
#include "subpartcontroller.h"

#include <stdio.h>

/**
 * @brief The SubpartMaterialSet class Dedicated to a single mesh with multiple materials
 */
class SubpartMaterialSet : public SubpartController
{
private:
   Object3d * obj3d;
   std::vector<Qt3DRender::QMaterial*> * materials;
   std::vector<QString*> * names;

public:
    SubpartMaterialSet(QString subpartName);
    virtual ~SubpartMaterialSet();

    /**
     * @brief init Init the subpart
     * @param obj3d The object
     * @param materials The material set to pick in
     */
    void init(Object3d * obj3d, std::vector<Qt3DRender::QMaterial*> * materials, std::vector<QString*> * names);

    /**
     * @brief install Installation of the subpart
     * @param viewer
     * @param controlPanel
     */
    virtual void install(Viewer3d * viewer, ControlPanel * controlPanel);
};


#endif // SUBPARTMATERIALSET_H
