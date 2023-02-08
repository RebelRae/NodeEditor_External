#include "valuenode.h"

ValueNode::ValueNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    type = EditorNodes::Type::Value;
    nodeItem->SetupFromType(static_cast<int>(type));
    nodeItem->SetTitle("Value");
    AddOutput();
}
ValueNode::~ValueNode() {}

void ValueNode::Update() {}
