#include "valuenode.h"

ValueNode::ValueNode(QGraphicsScene *parent) : Node(parent) {
    nodeItem->SetupFromType(static_cast<int>(Nodes::Type::Value));
    AddOutput();
}

void ValueNode::Update() {}
