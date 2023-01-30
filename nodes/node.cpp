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
    IOElement *inputNode = new IOElement(nodeItem, this);
    nodeItem->AddInput(inputNode);
    inputs.push_back(inputNode);
}
void Node::AddOutput() {
    IOElement *outputNode = new IOElement(nodeItem, this);
    outputNode->SetOutput(true);
    nodeItem->AddOutput(outputNode);
    inputs.push_back(outputNode);
}

void Node::ConnectInput(Node *node) { inputNodes.push_back(node); }
void Node::ConnectOutput(Node *node) { outputNodes.push_back(node); }
void Node::Disconnect(Node *node) {
    for(int i = 0; i < inputNodes.size(); i++) {
        if(inputNodes[i] == node)
            inputNodes.erase(inputNodes.begin() + i);
    }
    for(int i = 0; i < outputNodes.size(); i++) {
        if(outputNodes[i] == node)
            outputNodes.erase(outputNodes.begin() + i);
    }
}

void Node::Update() {}
void Node::DownstreamUpdate() {
    Update();
    for(int i = 0; i < outputNodes.size(); i++)
        outputNodes[i]->DownstreamUpdate();
}

void Node::ApplyStyle(int style) {
    qDebug() << QString("From Node: %1").arg(style);
    nodeItem->ApplyStyle(style);
}
