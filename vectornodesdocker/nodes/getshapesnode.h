#ifndef GETSHAPESNODE_H
#define GETSHAPESNODE_H

#include  "editornode.h"

#include <kis_node.h>

class GetShapesNode : public EditorNode {
    Q_OBJECT
public:
    GetShapesNode(QGraphicsScene *scene, qreal x = 0, qreal y = 0);
    virtual ~GetShapesNode();
    void Update() override;
    KisShapeLayer *value;

private:
    IOElement *geometryInput;
    IOElement *selectionInput;
    IOElement *outputIO;
    QGraphicsPixmapItem *imageItem;
    QGraphicsTextItem *textItem;
};

#endif // GETSHAPESNODE_H
