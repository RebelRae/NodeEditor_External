#include "attributenode.h"

#include <QDebug>

#include "../nodestyles.h"

AttributeNode::AttributeNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Attribute));
    times = 0;
    textItem = new QGraphicsTextItem();
    AddInput();
    AddOutput();
    AddOutput();
    AddOutput();
    textItem->setAcceptHoverEvents(false);
    nodeItem->addToGroup(textItem);
}
AttributeNode::~AttributeNode() {}

void AttributeNode::Update() {
    times++;
    textItem->setPos(10, nodeItem->boundingRect().height()/2);
    textItem->setPlainText(QString("Node Updated %1 times").arg(times));
}
