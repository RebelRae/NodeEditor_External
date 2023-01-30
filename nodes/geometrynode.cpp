#include "geometrynode.h"

#include <QDebug>

GeometryNode::GeometryNode(QGraphicsScene *parent) : Node(parent) {
    nodeItem->SetupFromType(static_cast<int>(Nodes::Type::Geometry));
    AddOutput();
}

void GeometryNode::Update() {
    qDebug() << "From geo node";
}
