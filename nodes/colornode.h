#ifndef COLORNODE_H
#define COLORNODE_H

#include  "node.h"

class ColorNode : public Node {
public:
    ColorNode(QGraphicsScene *parent);
    void Update() override;

private:
};

#endif // COLORNODE_H
