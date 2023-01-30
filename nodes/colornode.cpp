#include "colornode.h"

ColorNode::ColorNode(QGraphicsScene *parent) : Node(parent) {
    nodeItem->SetupFromType(static_cast<int>(Nodes::Type::Color));
    AddOutput();
}

void ColorNode::Update() {}
