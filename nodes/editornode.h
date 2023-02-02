#ifndef EDITORNODE_H
#define EDITORNODE_H

#include <vector>

#include <QObject>
#include <QGraphicsScene>

#include "../nodeitem.h"

class EditorNode : public QObject {
    Q_OBJECT
public:
    explicit EditorNode(QGraphicsScene *scene, qreal x = 0, qreal y = 0, QObject *parent = nullptr);
    virtual ~EditorNode();
    void ApplyStyle(int style);
    void AddInput();
    void AddOutput();
    void ConnectInput(EditorNode *node);
    void ConnectOutput(EditorNode *node);
    void Disconnect(EditorNode *node);
    virtual void Update();
    void DownstreamUpdate();
    virtual void OnClick(QGraphicsSceneMouseEvent *event);

protected:
    NodeItem *nodeItem;
    std::vector<EditorNode *> inputNodes;
    std::vector<EditorNode *> outputNodes;
    std::vector<IOElement *> inputs;
    std::vector<IOElement *> outputs;
};

namespace EditorNodes {
enum Type { // TODO : Decide on better classification, remove setTitle from setupFromStyle
    Empty,
    Value,
    Color,
    Geometry,
    Attribute,
    Layer,
};
}

#endif // EDITORNODE_H
