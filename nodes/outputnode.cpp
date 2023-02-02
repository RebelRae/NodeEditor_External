#include "outputnode.h"

OutputNode::OutputNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Layer));
    nodeItem->SetTitle("Output");
/*
 * description :
 * TODO : combo box with create or select layer output
 * clear and rebuild layer on update
*/
}
OutputNode::~OutputNode() {}

void OutputNode::Update() {
}
