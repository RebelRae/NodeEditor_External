#ifndef CONNECTION_H
#define CONNECTION_H

#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QPainterPath>

class Connection : public QGraphicsPathItem {
public:
    Connection(QGraphicsScene *parent=nullptr, qreal x=0, qreal y=0);
    void DrawTo(int xPos, int yPos, bool left = false);

protected:
    QPainterPath *path;
    QPen *pen;
    bool selected;
};

#endif // CONNECTION_H
