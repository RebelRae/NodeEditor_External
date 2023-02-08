#ifndef GETSHAPESNODE_H
#define GETSHAPESNODE_H

#include  "editornode.h"

class GetShapesNode : public EditorNode {
    Q_OBJECT
public:
    GetShapesNode(QGraphicsScene *scene, qreal x = 0, qreal y = 0);
    virtual ~GetShapesNode();
    void Update() override;

private:
    IOElement *geometryInput;
    IOElement *selectionInput;
    IOElement *outputIO;
    QGraphicsPixmapItem *imageItem;
};

#endif // GETSHAPESNODE_H
