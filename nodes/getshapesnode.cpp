#include "getshapesnode.h"

GetShapesNode::GetShapesNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Geometry));
    nodeItem->SetTitle("Get Shapes");
/*
 * description :
 * TODO : separate all shapes in a layer,
 * range or index
 * non recursive (ie groups count w single index)
*/
}
GetShapesNode::~GetShapesNode() {}

void GetShapesNode::Update() {
}
