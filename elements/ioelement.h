#ifndef IOELEMENT_H
#define IOELEMENT_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItemGroup>
#include <QPen>
#include <QGraphicsSceneDragDropEvent>

class IOElement : public QGraphicsEllipseItem {
public:
    IOElement(QGraphicsItemGroup *parent = nullptr);
    int  VSpacing() const;
    void SetVSpacing(int v);

    bool IsOutput() const;
    void SetOutput(bool output);

    bool IsHovering() const;
    void SetHovering(bool newIsHovering);

    void HoverDraw(bool hovering);

protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    int vSpacing;
    bool isOutput;
    bool isHovering;
};

#endif // IOELEMENT_H
