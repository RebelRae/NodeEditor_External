#include "noisenode.h"

NoiseNode::NoiseNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Value));
    nodeItem->SetTitle("Noise");
/*
 * description :
 * TODO : Import noise algorithms
 * apply to handles first, raster later
*/
}
NoiseNode::~NoiseNode() {}

void NoiseNode::Update() {
}
