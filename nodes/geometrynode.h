#ifndef GEOMETRYNODE_H
#define GEOMETRYNODE_H

#include  "node.h"

class GeometryNode : public Node {
public:
    GeometryNode(QGraphicsScene *parent);
    void Update() override;

private:
};

#endif // GEOMETRYNODE_H
