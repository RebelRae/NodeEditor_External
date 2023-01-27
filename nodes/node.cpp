#include "node.h"

#include <QDebug>

#include "../nodestyles.h"

Node::Node(QGraphicsScene *parent) {
    // Init
    nodeItem = new NodeItem();
    parent->addItem(nodeItem);
    nodeItem->SetupFromType(static_cast<int>(Nodes::Type::Empty));
}

void Node::AddInput() {
    IOElement *inputNode = new IOElement(nodeItem);
    nodeItem->AddInput(inputNode);
    inputs.push_back(inputNode);
}

void Node::AddOutput() {
    IOElement *outputNode = new IOElement(nodeItem);
    outputNode->SetOutput(true);
    nodeItem->AddOutput(outputNode);
    inputs.push_back(outputNode);
}

void Node::ConnectInput() {
}

void Node::ConnectOutput() {
}

void Node::ApplyStyle(int style) {
    qDebug() << QString("From Node: %1").arg(style);
    nodeItem->ApplyStyle(style);
}
