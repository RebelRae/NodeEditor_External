#include "nodescene.h"

#include "nodestyles.h"
#include "nodeitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

NodeScene::NodeScene(QObject *parent) : QGraphicsScene(parent) {
    // Style stuffs
    style = Normie;

    // Draw Background
    int width = 1000;
    int height = 600;
    QGraphicsRectItem *rect_item2 = this->addRect(-width/2, -height/2, width, height);
    rect_item2->setBrush(NodeStyles::Color::BackgroundFill);
    for(int y = -height/2; y < height/2; y+=20) {
        this->addLine(-width/2, y, width/2, y, NodeStyles::Color::GridLinesStroke);
    }
    this->addLine(-width/2, height/2, width/2, height/2, NodeStyles::Color::GridLinesStroke);
    for(int x = -width/2; x < width/2; x+=20) {
        this->addLine(x, -height/2, x, height/2, NodeStyles::Color::GridLinesStroke);
    }
    this->addLine(width/2, -height/2, width/2, height/2, NodeStyles::Color::GridLinesStroke);
    // Center
    this->addLine(0, -20, 0, 20, QPen(Qt::red));
    this->addLine(-20, 0, 20, 0, QPen(Qt::red));

    // Nodes
    nodes.push_back(new Node(this));
    nodes.push_back(new ValueNode(this));
    nodes.push_back(new ColorNode(this));
    nodes.push_back(new GeometryNode(this));
    nodes.push_back(new AttributeNode(this));
    for(int i = 0; i < nodes.size(); i++) {
    }

    // Connections
//    connections.push_back(new Connection(this));
//    for(int i = 0; i < connections.size(); i++) {
//    }

    // Events
    installEventFilter(this);
}

void NodeScene::setStyle(int index) {
    qDebug() << QString("Selected: %1").arg(index);
    style = static_cast<NodeStyle>(index);
    for(int i = 0; i < nodes.size(); i++) {
        nodes[i]->ApplyStyle(index);
    }
    // NOTE  : Possible bg style
}

IOElement * NodeScene::getChildHover() const { return hoverIO; }
void NodeScene::setChildHover(IOElement * hover) {
    hoverIO = hover;
}

bool NodeScene::eventFilter(QObject *watched, QEvent *event) {
    if(watched == this) {
        QGraphicsSceneMouseEvent *mouseSceneEvent;
        if(event->type() == QEvent::GraphicsSceneMousePress) { // Mouse Down
            if(hoverIO) {
                if(hoverIO->IsOutput()) {
                    activeConnection = new Connection(this, hoverIO->scenePos().x()+6, hoverIO->scenePos().y()+6);
                } else {
                    // Check if connected first
                    qDebug() << "Grabbing intput";
                }
            }
        }
        else if (event->type() == QEvent::GraphicsSceneMouseRelease) { // Mouse Up
            delete activeConnection;
            activeConnection = nullptr;
//            mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
//            qDebug() << mouseSceneEvent->scenePos()<<mouseSceneEvent->lastScenePos();
        }
        else if (event->type() == QEvent::GraphicsSceneMouseMove) { // Mouse Move
            mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
            int x = mouseSceneEvent->lastScenePos().rx();
            int y = mouseSceneEvent->lastScenePos().ry();
            if(activeConnection) {
//                qDebug() << mouseSceneEvent->scenePos()<<mouseSceneEvent->lastScenePos();
                activeConnection->DrawTo(x, y);
            }
//            for(int i = 0; i < connections.size(); i++) {
//                connections[i]->DrawTo(x, y);
//            }
//            QGraphicsScene::mouseMoveEvent(mouseSceneEvent);
        }
        QKeyEvent *keyEvent;
        if(event->type() == QEvent::KeyPress) { // Key Press
            keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << keyEvent->key();
        }
    }
    return QGraphicsScene::eventFilter(watched, event);
}
