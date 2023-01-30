#include "attributenode.h"

#include <QDebug>

#include "../nodestyles.h"

AttributeNode::AttributeNode(QGraphicsScene *parent) : Node(parent) {
    nodeItem->SetupFromType(static_cast<int>(Nodes::Type::Attribute));
    times = 0;
    textItem = new QGraphicsTextItem();
    AddInput();
    AddOutput();
    AddOutput();
    AddOutput();
    textItem->setAcceptHoverEvents(false);
    nodeItem->addToGroup(textItem);
}

void AttributeNode::Update() {
    qDebug() << this;
    times++;
    textItem->setPos(10, nodeItem->boundingRect().height()/2);
    textItem->setPlainText(QString("Node Updated %1 times").arg(times));
}
