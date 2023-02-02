#include "geometrynode.h"

#include <QDebug>

GeometryNode::GeometryNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Geometry));
    AddOutput();
}
GeometryNode::~GeometryNode() {}

void GeometryNode::Update() {
    qDebug() << "From geo node";
}
