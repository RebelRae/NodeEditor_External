#include "mathnode.h"

MathNode::MathNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Value));
    nodeItem->SetTitle("Math");
/*
 * description :
 * TODO : combo box to select operation
 * types
*/
}
MathNode::~MathNode() {}

void MathNode::Update() {
}
