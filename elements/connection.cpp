#include "connection.h"

#include "../nodestyles.h"

Connection::Connection(QGraphicsScene *parent, qreal x, qreal y) : QGraphicsPathItem() {
    // Init
    input = nullptr;
    output = nullptr;
    path = new QPainterPath();
    pen = new QPen();
    // Configure
    path->moveTo(x, y);
    path->cubicTo(x+60, y, 40, 100, 100, 100);
    setPath(*path);
    pen->setColor(NodeStyles::Color::Connection_Normie);
    pen->setWidth(3);
    setPen(*pen);
    parent->addItem(this);
}

void Connection::DrawTo(int xPos, int yPos, bool left) {
    if(left) {
        path->setElementPositionAt(2, xPos+60, yPos);
        path->setElementPositionAt(3, xPos, yPos);
    } else {
        path->setElementPositionAt(2, xPos-60, yPos);
        path->setElementPositionAt(3, xPos, yPos);
    }
    setPath(*path);
}

void Connection::ColorActive(bool active) {
    if(active)
        pen->setColor(NodeStyles::Color::Connection_Selected_Normie);
    else
        pen->setColor(NodeStyles::Color::Connection_Normie);
    update();
    setPen(*pen);
}

IOElement *Connection::Input() const { return input; }
void Connection::setInput(IOElement *newInput) { input = newInput; }

IOElement *Connection::Output() const { return output; }
void Connection::setOutput(IOElement *newOutput) { output = newOutput; }

IOElement *Connection::CurrentIO() const { return input? input : output; }
