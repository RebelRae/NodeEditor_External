#include "nodescene.h"

#include "nodestyles.h"
#include "nodeitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

NodeScene::NodeScene(QObject *parent) : QGraphicsScene(parent) {
    //  Init
    hoverIO = nullptr;
    selectedIO = nullptr;
    activeConnection = nullptr;
    // Style stuffs
    style = Normie;

    // Draw Background
//    int width = 1000;
//    int height = 600;
//    QGraphicsRectItem *rect_item2 = this->addRect(-width/2, -height/2, width, height);
//    rect_item2->setBrush(NodeStyles::Color::BackgroundFill);
//    for(int y = -height/2; y < height/2; y+=20) {
//        this->addLine(-width/2, y, width/2, y, NodeStyles::Color::GridLinesStroke);
//    }
//    this->addLine(-width/2, height/2, width/2, height/2, NodeStyles::Color::GridLinesStroke);
//    for(int x = -width/2; x < width/2; x+=20) {
//        this->addLine(x, -height/2, x, height/2, NodeStyles::Color::GridLinesStroke);
//    }
//    this->addLine(width/2, -height/2, width/2, height/2, NodeStyles::Color::GridLinesStroke);
    // Center
    this->addLine(0, -20, 0, 20, QPen(Qt::red));
    this->addLine(-20, 0, 20, 0, QPen(Qt::red));

    // Nodes
    nodes.push_back(new Node(this));
    nodes.push_back(new ValueNode(this));
    nodes.push_back(new ColorNode(this));
    nodes.push_back(new GeometryNode(this));
    nodes.push_back(new AttributeNode(this));
    nodes.push_back(new AttributeNode(this));

    // Events
    installEventFilter(this);
}

void NodeScene::setStyle(int index) {
    qDebug() << QString("Selected: %1").arg(index);
    style = static_cast<NodeStyle>(index);
    for(int i = 0; i < nodes.size(); i++) {
        nodes[i]->ApplyStyle(index);
    }
    // TODO  : Add bg styles
}

IOElement * NodeScene::getChildHover() const { return hoverIO; }
void NodeScene::setChildHover(IOElement * hover) { hoverIO = hover; }

void NodeScene::DeleteConnection(Connection *conn) {
    if(conn->Input()) // TODO : Make delete connection funcion
        conn->Input()->Disconnect();
    if(conn->Output())
        conn->Output()->Disconnect(conn);
    removeItem(conn);
    delete conn;
}

bool NodeScene::eventFilter(QObject *watched, QEvent *event) {
    if(watched == this) {
        QGraphicsSceneMouseEvent *mouseSceneEvent;
        if(event->type() == QEvent::GraphicsSceneMousePress) { // Mouse Down
            if(hoverIO) {
                if(hoverIO->IsOutput()) {
                    activeConnection = new Connection(this, hoverIO->scenePos().x()+6, hoverIO->scenePos().y()+6, false);
                    activeConnection->setOutput(hoverIO);
                } else {
                    if(hoverIO->Connection()) {
                        IOElement *outOld = hoverIO->Connection()->Output();
                        DeleteConnection(hoverIO->Connection());
                        // Disconnect
                        hoverIO->Node()->Disconnect(outOld->Node());
                        outOld->Node()->Disconnect(hoverIO->Node());
                        activeConnection = new Connection(this, outOld->scenePos().x()+6, outOld->scenePos().y()+6, false);
                        activeConnection->setOutput(outOld);
                    } else {
                        activeConnection = new Connection(this, hoverIO->scenePos().x()+6, hoverIO->scenePos().y()+6, true);
                        activeConnection->setInput(hoverIO);
                    }
                }
                activeConnection->ColorActive(true);
            }
        }
        else if (event->type() == QEvent::GraphicsSceneMouseRelease) { // Mouse Up
            if(activeConnection) {
                if(hoverIO) {
                    if(hoverIO->IsOutput()) {
                        activeConnection->setOutput(hoverIO);
                        // Connect
                        hoverIO->Node()->ConnectOutput(activeConnection->Input()->Node());
                        activeConnection->Input()->Node()->ConnectInput(hoverIO->Node());
                        activeConnection->Input()->Node()->DownstreamUpdate();
                    } else {
                        if(hoverIO->Connection())
                            DeleteConnection(hoverIO->Connection());
                        activeConnection->setInput(hoverIO);
                        // Connect
                        hoverIO->Node()->ConnectInput(activeConnection->Output()->Node());
                        activeConnection->Output()->Node()->ConnectOutput(hoverIO->Node());
                        hoverIO->Node()->DownstreamUpdate();
                    }
                    activeConnection->ColorActive(false);
                } else {
                    DeleteConnection(activeConnection);
                }
                activeConnection = nullptr;
            }
        }
        else if (event->type() == QEvent::GraphicsSceneMouseMove) { // Mouse Move
            // If dragging activeConnection
            if(activeConnection) {
                mouseSceneEvent = static_cast<QGraphicsSceneMouseEvent *>(event);
                int x = mouseSceneEvent->scenePos().rx();
                int y = mouseSceneEvent->scenePos().ry();
                bool snap = false;
                // Set tempHover objptr
                IOElement *tempHover = nullptr;
                // For each graphics item
                foreach (QGraphicsItem *item, this->items()) {
                    IOElement *ioElement = qgraphicsitem_cast<IOElement *>(item);
                    IOElement *selectedElement = activeConnection->CurrentIO();
                    // process only if item is an IOElement
                    if (!ioElement) continue;
                    // if under the mouse
                    if(ioElement->isUnderMouse()) {
                        if(ioElement->IsOutput() == selectedElement->IsOutput()) continue;
                        if(ioElement->Node() == selectedElement->Node()) continue;
                        // Draw to snapping position and set snap to prevent drawing to mouse pos
                       activeConnection->DrawTo(ioElement->scenePos().x()+6, ioElement->scenePos().y()+6);
                       snap = true;
                        // Draw hover - NOTE : Also sets hoverIO
                        ioElement->SetHovering(true);
                        // Set tempHover
                        tempHover = ioElement;
                    // if not under mouse
                    } else {
                        // Draw non hovering - NOTE : Also sets hoverIO to nullptr
                        ioElement->SetHovering(false);
                    }
                }
                // Sets hoverIO to nullptr OR to tempHover if it was set
                hoverIO = tempHover;
                if(!snap)
                    activeConnection->DrawTo(x, y);
            }
        }
        QKeyEvent *keyEvent;
        if(event->type() == QEvent::KeyPress) { // Key Press
            keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << keyEvent->key();
        }
    }
    return QGraphicsScene::eventFilter(watched, event);
}
