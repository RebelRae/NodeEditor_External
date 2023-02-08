#include "getshapesnode.h"

#include "layernode.h"
#include "kis_shape_layer.h"

GetShapesNode::GetShapesNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    type = EditorNodes::Type::GetShapes;
    nodeItem->SetupFromType(static_cast<int>(type));
    nodeItem->SetTitle("Get Shapes");
    // Inputs
    geometryInput = new IOElement(nodeItem, this);
    geometryInput->index = 0;
    geometryInput->SetOutput(false);
    nodeItem->AddInput(geometryInput);
    inputs.push_back(geometryInput);

    selectionInput = new IOElement(nodeItem, this);
    selectionInput->index = 1;
    selectionInput->SetOutput(false);
    nodeItem->AddInput(selectionInput);
    inputs.push_back(selectionInput);
    // Outputs
    outputIO = new IOElement(nodeItem, this);
    outputIO->index = 0;
    outputIO->SetOutput(true);
//    outputIO->SetVSpacing(100);
    nodeItem->AddOutput(outputIO);
    outputs.push_back(outputIO);
    // Display
    imageItem = new QGraphicsPixmapItem();
    imageItem->setPos(nodeItem->scenePos().x() + 15, nodeItem->scenePos().y() + 15);
    nodeItem->addToGroup(imageItem);
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
