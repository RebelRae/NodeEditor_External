#ifndef LAYERNODE_H
#define LAYERNODE_H

#include <QComboBox>
#include <QPushButton>

#include <kis_node.h>

#include  "editornode.h"

class LayerNode : public EditorNode {
    Q_OBJECT
public:
    LayerNode(QGraphicsScene *scene, qreal x = 0, qreal y = 0);
    virtual ~LayerNode();
    void Update() override;
    void updateLayers();
    void OnClick(QGraphicsSceneMouseEvent *event) override;
    KisNodeSP value; // TODO : Remove referencial

protected:
    QList<KisNodeSP> getLayers(KisNodeSP layer);
    KisNodeSP findLayer(KisNodeSP layer, QString name);

private:
    QComboBox *spinner;
    Q_SLOT void selectLayer(int index);
    QPushButton *refreshButton;
    Q_SLOT void refreshButtonClicked(bool clicked);
};

#endif // LAYERNODE_H
