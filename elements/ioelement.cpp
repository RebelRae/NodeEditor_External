#include "ioelement.h"

#include <QBrush>
#include <QDebug>

#include "../nodescene.h"
#include "../nodestyles.h"

IOElement::IOElement(QGraphicsItemGroup *parent) : QGraphicsEllipseItem(parent) {
    vSpacing = 26;
    isOutput = false;
    QBrush brush = QBrush(Qt::SolidPattern);
    brush.setColor(NodeStyles::Color::IO_Normie);
    setBrush(brush);
    setPen(QPen(NodeStyles::Color::IO_Pen_Normie));
    setAcceptHoverEvents(true);
    setFlags(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable |
             QGraphicsItem::GraphicsItemFlag::ItemSendsScenePositionChanges |
             QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptDrops(true);
}

void IOElement::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    NodeScene *nodeScene = dynamic_cast<NodeScene *>(scene());
    nodeScene->setChildHover(this);
    QPen pen;
    pen.setColor(NodeStyles::Color::Pen_Hover_Normie);
    pen.setWidth(2);
    setPen(pen);
    update();
    QGraphicsEllipseItem::hoverEnterEvent(event);
}
void IOElement::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    NodeScene *nodeScene = dynamic_cast<NodeScene *>(scene());
    nodeScene->setChildHover(nullptr);
    QPen pen;
    pen.setColor(NodeStyles::Color::IO_Pen_Normie);
    pen.setWidth(1);
    setPen(pen);
    update();
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}

void IOElement::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
    NodeScene *nodeScene = dynamic_cast<NodeScene *>(scene());
    nodeScene->setChildHover(this);
    QPen pen;
    pen.setColor(NodeStyles::Color::Pen_Hover_Normie);
    pen.setWidth(2);
    setPen(pen);
    update();
    qDebug() << "dragEnterEvent started";
    event->setAccepted(true);
//    event->setAccepted(true);
//    QGraphicsEllipseItem::dragEnterEvent(event);
}
void IOElement::dragLeaveEvent(QGraphicsSceneDragDropEvent *event) {
    qDebug() << "dragMoveEvent started";
    event->setAccepted(true);
}
void IOElement::dropEvent(QGraphicsSceneDragDropEvent *event) {
    qDebug() << "dropEvent started";
    event->setAccepted(true);
    IOElement::dropEvent(event);
}

bool IOElement::IsOutput() const { return isOutput; }
void IOElement::SetOutput(bool output) { isOutput = output; }

int IOElement::getVSpacing() const { return vSpacing; }

void IOElement::setVSpacing(int v) { vSpacing = v; }
