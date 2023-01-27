#include "nodeitem.h"

#include <QBrush>
#include <QPen>
#include <QDebug>

#include "nodestyles.h"
//#include "nodescene.h"

NodeItem::NodeItem(int w, int h) :
    bodyRect(new QGraphicsRectItem(0, 0, w, h)),
    headerRect(new QGraphicsRectItem(0, -NodeStyles::Style::NodeHeaderHeight, w, NodeStyles::Style::NodeHeaderHeight)),
    outlineRect(new NodeOutlineRectItem(0, -NodeStyles::Style::NodeHeaderHeight, w, h + NodeStyles::Style::NodeHeaderHeight, this))
{
    QBrush brush = QBrush(Qt::SolidPattern);
    // Body
    brush.setColor(NodeStyles::Color::NodeFill_Normie);
    bodyRect->setBrush(brush);
    bodyRect->setPen(Qt::NoPen);
    addToGroup(bodyRect);
    // Header
    addToGroup(headerRect);
    textItem = new QGraphicsTextItem();
    textItem->setPos(0, -NodeStyles::Style::NodeHeaderHeight-4);
    textItem->setAcceptHoverEvents(false);
    addToGroup(textItem);
    // This
    setFlags(QGraphicsItem::GraphicsItemFlag::ItemIsMovable);
    setAcceptHoverEvents(true);
    setHandlesChildEvents(false);
}

//IOElement * NodeItem::getChildHover() const { return childHover; }
//void NodeItem::setChildHover(IOElement * hover) {
//    childHover = hover;
//    NodeScene *nodeScene = dynamic_cast<NodeScene *>(scene());
//    nodeScene->setChildHover(hover);
//}

void NodeItem::SetTitle(QString &text) { textItem->setPlainText(text); }

void NodeItem::AddInput(IOElement *input) {
    addToGroup(input);
    inputs.push_back(input);
    resizeBody();
}
void NodeItem::AddOutput(IOElement *output) {
    addToGroup(output);
    outputs.push_back(output);
    resizeBody();
}

void NodeItem::SetupFromType(int type) {
    QBrush brush = QBrush(Qt::SolidPattern);
    switch (type) {
    case 0:
        brush.setColor(NodeStyles::Color::HeaderIO_Normie);
        headerRect->setBrush(brush);
        headerRect->setPen(Qt::NoPen);
        textItem->setPlainText("Empty Node");
        break;
    case 1:
        brush.setColor(NodeStyles::Color::HeaderValue_Normie);
        headerRect->setBrush(brush);
        headerRect->setPen(Qt::NoPen);
        textItem->setPlainText("Value");
        break;
    case 2:
        brush.setColor(NodeStyles::Color::HeaderColor_Normie);
        headerRect->setBrush(brush);
        headerRect->setPen(Qt::NoPen);
        textItem->setPlainText("Color");
        break;
    case 3:
        brush.setColor(NodeStyles::Color::HeaderGeometry_Normie);
        headerRect->setBrush(brush);
        headerRect->setPen(Qt::NoPen);
        textItem->setPlainText("Geometry");
        break;
    case 4:
        brush.setColor(NodeStyles::Color::HeaderAdjust_Normie);
        headerRect->setBrush(brush);
        headerRect->setPen(Qt::NoPen);
        textItem->setPlainText("Get Attributes");
        break;
    default:
        break;
    }
}

void NodeItem::resizeBody() {
    int w = outlineRect->rect().width();
    int inputsHeight = NodeStyles::Style::NodeMarginV;
    for(int i = 0; i < inputs.size(); i++) {
        int space = inputs[i]->getVSpacing();
        inputs[i]->setRect(0, 0, 12, 12);
        inputs[i]->setPos(-6, inputsHeight + space/2 - 6);
        inputsHeight += space;
    }
    int outputsHeight = NodeStyles::Style::NodeMarginV;
    for(int i = 0; i < outputs.size(); i++) {
        int space = outputs[i]->getVSpacing();
        outputs[i]->setRect(0, 0, 12, 12);
        outputs[i]->setPos(w - 6, outputsHeight + space/2 - 6);
        outputsHeight += space;
    }

    int h = (outputsHeight > inputsHeight)? outputsHeight : inputsHeight;
    h += NodeStyles::Style::NodeMarginV;
    bodyRect->setRect(0, 0, w, h);
    headerRect->setRect(0, -NodeStyles::Style::NodeHeaderHeight, w, NodeStyles::Style::NodeHeaderHeight);
    outlineRect->setRect(0, -NodeStyles::Style::NodeHeaderHeight, w, h + NodeStyles::Style::NodeHeaderHeight);
    // Note : Necessary for resizing
    QGraphicsRectItem *rect = new QGraphicsRectItem(0, -NodeStyles::Style::NodeHeaderHeight, w, h + NodeStyles::Style::NodeHeaderHeight);
    addToGroup(rect);
    removeFromGroup(rect);
    delete rect;
}

void NodeItem::ApplyStyle(int style) {
    qDebug() << QString("From Node Item: %1").arg(style);
    switch (style) {
    case 0:

        break;
    default:
        break;
    }
}