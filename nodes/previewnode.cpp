#include "previewnode.h"

#include "layernode.h"
#include "kis_shape_layer.h"

PreviewNode::PreviewNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Value));

    inputIO = new IOElement(nodeItem, this);
    inputIO->SetOutput(false);
    inputIO->SetVSpacing(130);
    nodeItem->AddInput(inputIO);
    outputs.push_back(inputIO);
    nodeItem->SetTitle("Preview");

    imageItem = new QGraphicsPixmapItem();
    imageItem->setPos(nodeItem->scenePos().x() + 15, nodeItem->scenePos().y() + 15);
    nodeItem->addToGroup(imageItem);

//    textItem = new QGraphicsTextItem();
//    textItem->setAcceptHoverEvents(false);
//    nodeItem->addToGroup(textItem);
}
PreviewNode::~PreviewNode() {}

void PreviewNode::Update() {
    EditorNode *inputNode = inputNodes[0]; // TODO : Deref
    if(!inputNode) return;
    LayerNode *layerNode = qobject_cast<LayerNode*>(inputNode); // TODO : Deref
    if(!layerNode) return;
    KisNodeSP node = layerNode->value;
    if(!node) return;
//    textItem->setPos(0, 0);
//    textItem->setPlainText(QString("From LayerNode: %1").arg(node.data()->name()));
    KisShapeLayer *shapeLayer = qobject_cast<KisShapeLayer*>(node.data());
    if(!shapeLayer) return;
    QImage thumbnail = shapeLayer->createThumbnail(130, 130, Qt::KeepAspectRatio); // TODO : Deref, probably move to header and update
    imageItem->setPixmap(QPixmap::fromImage(thumbnail));
}
