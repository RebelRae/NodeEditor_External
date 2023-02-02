#include "shapenode.h"

ShapeNode::ShapeNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Geometry));
    nodeItem->SetTitle("Shape");
/*
 * description :
 * TODO : combo box w primitive or library(future task)
*/
}
ShapeNode::~ShapeNode() {}

void ShapeNode::Update() {
}
