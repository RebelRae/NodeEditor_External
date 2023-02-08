#ifndef VALUENODE_H
#define VALUENODE_H

#include  "editornode.h"

class ValueNode : public EditorNode {
    Q_OBJECT
public:
    ValueNode(QGraphicsScene *scene, qreal x = 0, qreal y = 0);
    virtual ~ValueNode();
    void Update() override;

private:
};

#endif // VALUENODE_H
