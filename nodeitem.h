#ifndef NODEITEM_H
#define NODEITEM_H

#include <vector>

#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>

#include "elements/nodeoutlinerectitem.h"
#include "elements/ioelement.h"

class NodeItem : public QGraphicsItemGroup {
public:
    explicit NodeItem(int w = 160, int h = 50);
    void SetupFromType(int type);
    void ApplyStyle(int style);
    void SetTitle(QString &text);
    void AddInput(IOElement *input);
    void AddOutput(IOElement *output);
//    IOElement * getChildHover() const;
//    void setChildHover(IOElement * hover=nullptr);

private:
    void resizeBody();
    QGraphicsRectItem *bodyRect;
    QGraphicsRectItem *headerRect;
    NodeOutlineRectItem *outlineRect;
    QGraphicsTextItem *textItem;
    std::vector<IOElement *> inputs;
    std::vector<IOElement *> outputs;
//    IOElement * childHover;
};

#endif // NODEITEM_H
