#ifndef ATTRIBUTENODE_H
#define ATTRIBUTENODE_H

#include  "editornode.h"

class AttributeNode : public EditorNode {
    Q_OBJECT
public:
    AttributeNode(QGraphicsScene *scene, qreal x = 0, qreal y = 0);
    virtual ~AttributeNode();
    void Update() override;

private:
    QGraphicsTextItem *textItem;
    int times;
};

#endif // ATTRIBUTENODE_H
