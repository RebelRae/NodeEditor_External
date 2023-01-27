#include "geometrynode.h"

GeometryNode::GeometryNode(QGraphicsScene *parent) : Node(parent) {
    nodeItem->SetupFromType(static_cast<int>(Nodes::Type::Geometry));
    AddOutput();
}
