#ifndef NODESCENE_H
#define NODESCENE_H

#include <vector>

#include <QGraphicsScene>
#include <KoCanvasObserverBase.h>

#include "elements/connection.h"
#include "elements/editormenu.h"
#include "nodes/editornode.h"
#include "nodes/valuenode.h"
#include "nodes/colornode.h"
#include "nodes/geometrynode.h"
#include "nodes/attributenode.h"
#include "nodes/layernode.h"
#include "nodes/previewnode.h"
#include "nodes/getshapesnode.h"
#include "nodes/mathnode.h"
#include "nodes/noisenode.h"
#include "nodes/outputnode.h"
#include "nodes/shapenode.h"

class NodeScene : public QGraphicsScene {
    Q_OBJECT
public:
    using QGraphicsScene::QGraphicsScene;
    explicit NodeScene(QObject *parent = nullptr);
    void setCanvas(KoCanvasBase *canvas);
    void setStyle(int index);
    IOElement * getChildHover() const;
    void setChildHover(IOElement * hover = nullptr);
    KoCanvasBase *Canvas() const;
    void AddNode(QString nodeName);
    void Debug(QString text);

protected:
    bool eventFilter(QObject *watched, QEvent *event);
    void DeleteConnection(Connection *conn);

private:
    EditorMenu *addNodeMenu;
    KoCanvasBase *mainCanvas;
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
    std::vector<EditorNode *> nodes;
    IOElement *hoverIO;
    IOElement *selectedIO;
    Connection *activeConnection;
    bool shiftKey;
    bool ctrlKey;
    bool altKey;
    QGraphicsTextItem *debugTextItem;
    QPointF previousPos;
};

#endif // NODESCENE_H
