#include "valuenode.h"

ValueNode::ValueNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Value));
    AddOutput();
}
ValueNode::~ValueNode() {}

void ValueNode::Update() {}
