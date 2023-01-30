#ifndef IOELEMENT_H
#define IOELEMENT_H

#include <vector>

#include <QGraphicsEllipseItem>
#include <QGraphicsItemGroup>
#include <QPen>
#include <QGraphicsSceneDragDropEvent>

class IOElement : public QGraphicsEllipseItem {
public:
    IOElement(QGraphicsItemGroup *parent = nullptr, class Node *nodeParent = nullptr);
    class Node *Node();
    int  VSpacing() const;
    void SetVSpacing(int v);

    bool IsOutput() const;
    void SetOutput(bool output);

    bool IsHovering() const;
    void SetHovering(bool newIsHovering);

    class Connection *Connection() const;
    void Connect(class Connection *newConnection);
    void Disconnect(class Connection *conn = nullptr);

    void HoverDraw(bool hovering);

protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    class Node *node;
    int vSpacing;
    bool isOutput;
    bool isHovering;
    class Connection *connection;
    std::vector<class Connection *> connections;
};

#endif // IOELEMENT_H
