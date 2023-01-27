#ifndef NODESCENE_H
#define NODESCENE_H

#include <vector>

#include <QGraphicsScene>

#include "elements/connection.h"
#include "nodes/node.h"
#include "nodes/valuenode.h"
#include "nodes/colornode.h"
#include "nodes/geometrynode.h"
#include "nodes/attributenode.h"

class NodeScene : public QGraphicsScene {
    Q_OBJECT
public:
    using QGraphicsScene::QGraphicsScene;
    explicit NodeScene(QObject *parent = nullptr);
    void setStyle(int index);
    IOElement * getChildHover() const;
    void setChildHover(IOElement * hover=nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    enum NodeStyle {
        Normie,
        Brightly,
        ChocolateThunder
    };
    NodeStyle style;
    QColor BackgroundFill;
    QColor GridLinesStroke;
    QColor NodeBodyFill;
    QColor NodeBodyStroke;
    std::vector<Node *> nodes;
    std::vector<Connection *> connections;
    IOElement *hoverIO;
    IOElement *selectedIO;
    Connection *activeConnection;
};

#endif // NODESCENE_H
