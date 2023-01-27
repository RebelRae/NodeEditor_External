#ifndef IOELEMENT_H
#define IOELEMENT_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItemGroup>
#include <QPen>
#include <QGraphicsSceneDragDropEvent>

class IOElement : public QGraphicsEllipseItem {
public:
    IOElement(QGraphicsItemGroup *parent=nullptr);
    int getVSpacing() const;
    void setVSpacing(int v);
    bool IsOutput() const;
    void SetOutput(bool output);

protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event) override;

private:
    int vSpacing;
    bool isOutput;
};

#endif // IOELEMENT_H
