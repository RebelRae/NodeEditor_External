#include "ioelement.h"

#include <QBrush>
#include <QDebug>

#include "../nodescene.h"
#include "../nodestyles.h"

IOElement::IOElement(QGraphicsItemGroup *parent) : QGraphicsEllipseItem(parent) {
    //  Init
    vSpacing = 26;
    isOutput = false;
    isHovering = false;

    QBrush brush = QBrush(Qt::SolidPattern);
    brush.setColor(NodeStyles::Color::IO_Normie);
    setBrush(brush);
    setPen(QPen(NodeStyles::Color::IO_Pen_Normie));
    setAcceptHoverEvents(true);
    setFlags(QGraphicsItem::GraphicsItemFlag::ItemIsSelectable |
             QGraphicsItem::GraphicsItemFlag::ItemSendsScenePositionChanges);
}

void IOElement::HoverDraw(bool hovering) {
    QPen pen;
    if(hovering) {
        pen.setColor(NodeStyles::Color::Pen_Hover_Normie);
        pen.setWidth(2);
    } else {
        pen.setColor(NodeStyles::Color::IO_Pen_Normie);
        pen.setWidth(1);
    }
    setPen(pen);
    update();
}

void IOElement::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    SetHovering(true);
    QGraphicsEllipseItem::hoverEnterEvent(event);
}
void IOElement::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    SetHovering(false);
    QGraphicsEllipseItem::hoverLeaveEvent(event);
}

bool IOElement::IsHovering() const { return isHovering; }
void IOElement::SetHovering(bool hovering) {
    isHovering = hovering;
    HoverDraw(isHovering);
    NodeScene *nodeScene = dynamic_cast<NodeScene *>(scene());
    if(hovering)
        nodeScene->setChildHover(this);
    else
        nodeScene->setChildHover(nullptr);
}

bool IOElement::IsOutput() const { return isOutput; }
void IOElement::SetOutput(bool output) { isOutput = output; }

int IOElement::VSpacing() const { return vSpacing; }
void IOElement::SetVSpacing(int v) { vSpacing = v; }
