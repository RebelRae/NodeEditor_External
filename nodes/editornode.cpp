#include "editornode.h"

#include <QDebug>

#include "../nodestyles.h"

EditorNode::EditorNode(QGraphicsScene *scene, qreal x, qreal y, QObject *parent) : QObject(parent) {
    // Init
    nodeItem = new NodeItem(this, x, y);
    scene->addItem(nodeItem);
    nodeItem->SetupFromType(static_cast<int>(EditorNodes::Type::Empty));
}
EditorNode::~EditorNode() {}
void EditorNode::OnClick(QGraphicsSceneMouseEvent *event) {}

void EditorNode::AddInput() {
    IOElement *inputNode = new IOElement(nodeItem, this);
    nodeItem->AddInput(inputNode);
    inputs.push_back(inputNode);
}
void EditorNode::AddOutput() {
    IOElement *outputNode = new IOElement(nodeItem, this);
    outputNode->SetOutput(true);
    nodeItem->AddOutput(outputNode);
    inputs.push_back(outputNode);
}

void EditorNode::ConnectInput(EditorNode *node) { inputNodes.push_back(node); }
void EditorNode::ConnectOutput(EditorNode *node) { outputNodes.push_back(node); }
void EditorNode::Disconnect(EditorNode *node) {
    for(int i = 0; i < inputNodes.size(); i++) {
        if(inputNodes[i] == node)
            inputNodes.erase(inputNodes.begin() + i);
    }
    for(int i = 0; i < outputNodes.size(); i++) {
        if(outputNodes[i] == node)
            outputNodes.erase(outputNodes.begin() + i);
    }
}

void EditorNode::Update() {}
void EditorNode::DownstreamUpdate() {
    Update();
    for(int i = 0; i < outputNodes.size(); i++)
        outputNodes[i]->DownstreamUpdate();
}

void EditorNode::ApplyStyle(int style) {
    qDebug() << QString("From Node: %1").arg(style);
    nodeItem->ApplyStyle(style);
}
