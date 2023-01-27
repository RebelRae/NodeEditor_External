#include "attributenode.h"

AttributeNode::AttributeNode(QGraphicsScene *parent) : Node(parent) {
    nodeItem->SetupFromType(static_cast<int>(Nodes::Type::Attribute));
    AddInput();
    AddOutput();
    AddOutput();
    AddOutput();
}
