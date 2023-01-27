#ifndef NODE_H
#define NODE_H

#include <vector>

#include <QGraphicsScene>

#include "../nodeitem.h"

class Node {
public:
    Node(QGraphicsScene *parent);
    void ApplyStyle(int style);
    void AddInput();
    void AddOutput();
    void ConnectInput();
    void ConnectOutput();

protected:
    NodeItem *nodeItem;

private:
    std::vector<Node *> inputNodes;
    std::vector<Node *> outputNodes;
    std::vector<IOElement *> inputs;
    std::vector<IOElement *> outputs;
};

namespace Nodes {
enum Type {
    Empty,
    Value,
    Color,
    Geometry,
    Attribute,
};
}

#endif // NODE_H
