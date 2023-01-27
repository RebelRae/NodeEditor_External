#include "connection.h"

#include "../nodestyles.h"

Connection::Connection(QGraphicsScene *parent, qreal x, qreal y) : QGraphicsPathItem() {
    path = new QPainterPath();
    path->moveTo(x, y);
    path->cubicTo(x+60, y, 40, 100, 100, 100);
    setPath(*path);
    selected = true;
    pen = new QPen();
    pen->setColor(NodeStyles::Color::Connection_Normie);
    pen->setWidth(3);
    setPen(*pen);
    parent->addItem(this);
//    setFlags(QGraphicsItem::GraphicsItemFlag::Item);
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
