#ifndef VALUENODE_H
#define VALUENODE_H

#include  "node.h"

class ValueNode : public Node {
public:
    ValueNode(QGraphicsScene *parent);
    void Update() override;

private:
};

#endif // VALUENODE_H
