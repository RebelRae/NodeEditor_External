#include "colornode.h"

ColorNode::ColorNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Color));
    AddOutput();
}
ColorNode::~ColorNode() {}

void ColorNode::Update() {}
