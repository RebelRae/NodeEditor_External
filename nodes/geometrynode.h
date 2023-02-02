#ifndef GEOMETRYNODE_H
#define GEOMETRYNODE_H

#include  "editornode.h"

class GeometryNode : public EditorNode {
    Q_OBJECT
public:
    GeometryNode(QGraphicsScene *scene, qreal x = 0, qreal y = 0);
    virtual ~GeometryNode();
    void Update() override;

private:
};

#endif // GEOMETRYNODE_H
