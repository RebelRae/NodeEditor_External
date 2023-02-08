#include "previewnode.h"

//#include "layernode.h"
//#include "kis_shape_layer.h"

#include "../nodestyles.h"

PreviewNode::PreviewNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    type = EditorNodes::Type::Preview;
    nodeItem->SetupFromType(static_cast<int>(type));
    nodeItem->SetTitle("Preview");
    // Init
    times = 0;
    // Inputs
    inputIO = AddInput();// new IOElement(nodeItem, this);
//    inputIO->index = 0;
//    inputIO->SetOutput(false);
    inputIO->SetVSpacing(26);
//    nodeItem->AddInput(inputIO);
//    inputs.push_back(inputIO);
    // Display
    AddInput();
    AddInput();
    imageItem = new QGraphicsPixmapItem();
    imageItem->setPos(nodeItem->scenePos().x() + 15, nodeItem->scenePos().y() + 15);
    nodeItem->addToGroup(imageItem);

    textItem = new QGraphicsTextItem();
    textItem->setPos(nodeItem->scenePos().x(), nodeItem->scenePos().y() + NodeStyles::Style::NodeHeaderHeight);
    textItem->setAcceptHoverEvents(false);
    nodeItem->addToGroup(textItem);
}
PreviewNode::~PreviewNode() {}

void PreviewNode::Update() {
    imageItem->hide();
//    nodeItem->removeFromGroup(imageItem);
    inputIO->SetVSpacing(26);
    nodeItem->resizeBody();
    times++;
    textItem->setPlainText(QString("updated %1").arg(times));

//    if(!inputNodes[0]) {
//        textItem->setPlainText(QString("No input"));
//        return;
//    } else {
//        textItem->setPlainText(QString("Input"));
//    }
//    QSharedPointer<LayerNode> layerNode = qobject_cast<QSharedPointer<LayerNode>>(inputNodes[0]); // TODO : Deref
//    if(!layerNode) {
//        textItem->setPlainText(QString("Only Layer Node"));
//        return;
//    }
//    KisNodeSP node = layerNode->value;
//    if(!node) {
//        textItem->setPlainText(QString("Only Layer Node"));
//        return;
//    }
//    KisShapeLayer *shapeLayer = qobject_cast<KisShapeLayer*>(node.data());
//    if(!shapeLayer) {
//        textItem->setPlainText(QString("Invalid Layer"));
//        return;
//    }

//    nodeItem->addToGroup(imageItem);
//    textItem->setPlainText(QString(""));
//    inputIO->SetVSpacing(130);
//    nodeItem->resizeBody();
//    QImage thumbnail = shapeLayer->createThumbnail(130, 130, Qt::KeepAspectRatio); // TODO : Deref, probably move to header and update
//    imageItem->show();
//    imageItem->setPixmap(QPixmap::fromImage(thumbnail));
}
