#ifndef ATTRIBUTENODE_H
#define ATTRIBUTENODE_H

#include  "node.h"

class AttributeNode : public Node {
public:
    AttributeNode(QGraphicsScene *parent);
    void Update() override;

private:
    QGraphicsTextItem *textItem;
    int times;
};

#endif // ATTRIBUTENODE_H
