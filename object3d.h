#ifndef OBJECT3D_H
#define OBJECT3D_H

#include <Qt3DCore/QNode>
#include <Qt3DRender/QMaterial>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DRender/QMesh>
#include <QUrl>
#include <QString>

/**
 * @brief The Object3d class
 * 3D object
 */
class Object3d : public Qt3DCore::QEntity
{
private:
    Qt3DRender::QMesh *mesh;
    Qt3DCore::QTransform *transform;
    Qt3DRender::QMaterial *material;

public:
    Object3d(Qt3DCore::QNode *parent=nullptr);
    ~Object3d();

    /**
     * @brief setMesh
     * @param resourceNameForMesh
     */
    void setMesh(QString resourceNameForMesh);

    /**
     * @brief setMaterial
     * @param material
     */
    void setMaterial(Qt3DRender::QMaterial * material);

    /**
     * @brief setMaterial
     * @param material
     */
    void setTransform(Qt3DCore::QTransform * transform);

    /**
     * @brief getTransform Get the transform
     * @return
     */
    Qt3DCore::QTransform * getTransform();


};


#endif // OBJECT3D_H
