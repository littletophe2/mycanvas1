#include "object3d.h"
#include <Qt3DRender/QGeometry>
#include <Qt3DRender/QAttribute>
#include <iostream>

Object3d::Object3d(Qt3DCore::QNode *parent):
    Qt3DCore::QEntity(parent),
    mesh(new Qt3DRender::QMesh()),
    transform(new Qt3DCore::QTransform()),
    material(new Qt3DExtras::QPhongMaterial())
{
    addComponent(mesh);
    addComponent(transform);
    addComponent(material);
}

Object3d::~Object3d()
{
    delete mesh;
    delete transform;
    delete material;
}

/**
 * @brief setMaterial
 * @param material
 */
void Object3d::setMaterial(Qt3DRender::QMaterial * material)
{
    removeComponent(this->material);
    delete this->material;
    addComponent(material);
    this->material = material;
}


/**
 * @brief setMaterial
 * @param material
 */
void Object3d::setTransform(Qt3DCore::QTransform * transform)
{
    removeComponent(this->transform);
    delete this->transform;
    addComponent(transform);
    this->transform=transform;
}

/**
 * @brief getTransform Get the transform
 * @return
 */
Qt3DCore::QTransform * Object3d::getTransform()
{
    return transform;
}



/**
 * @brief setMesh
 * @param resourceNameForMesh
 */
void Object3d::setMesh(QString resourceNameForMesh)
{
   mesh->setSource(QUrl(resourceNameForMesh));

  /* Qt3DRender::QGeometry * geometry = mesh->geometry();
   Qt3DRender::QAttribute * bbox = geometry->boundingVolumePositionAttribute();
   std::cout << bbox;*/
}
