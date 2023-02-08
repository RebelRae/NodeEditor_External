#include "getshapesnode.h"

#include <QList>

#include "layernode.h"
#include "valuenode.h"

#include "kis_shape_layer.h"
//#include "kis_node.h"
#include <KoProperties.h>
#include <KoShapeManager.h>
#include <KoShape.h>
#include <KoShapeGroup.h>
//#include <KoShapeControllerBase.h>

GetShapesNode::GetShapesNode(QGraphicsScene *scene, qreal x, qreal y) : EditorNode(scene, x, y) {
    type = EditorNodes::Type::GetShapes;
    nodeItem->SetupFromType(static_cast<int>(type));
    nodeItem->SetTitle("Get Shapes");
    value = nullptr;
    // Inputs
    geometryInput = AddInput();
    selectionInput = AddInput();
    // Outputs
    outputIO = AddOutput();
    // Display
    imageItem = new QGraphicsPixmapItem();
    imageItem->setPos(nodeItem->scenePos().x() + 15, nodeItem->scenePos().y() + 15);
    nodeItem->addToGroup(imageItem);
    imageItem->hide();// TODO

    textItem = new QGraphicsTextItem();
    textItem->setPos(nodeItem->scenePos().x() + 10, nodeItem->scenePos().y() + NodeStyles::Style::NodeHeaderHeight);
    textItem->setAcceptHoverEvents(false);
    nodeItem->addToGroup(textItem);
}
GetShapesNode::~GetShapesNode() {}

void GetShapesNode::Update() {

    if(inputNodes.size() < 2) {
        textItem->setPlainText(QString("No input."));
        return;
    }
    LayerNode *layerNode = nullptr;
    KisNodeSP node = nullptr;
    KisShapeLayer *shapeLayer = nullptr;
    bool canDisplay = true;
    if(inputNodes.first()->inherits("LayerNode")) {
        layerNode = qobject_cast<LayerNode *>(inputNodes.first());
        node = layerNode->value;
        if(!node)
            canDisplay = false;
        shapeLayer = qobject_cast<KisShapeLayer *>(node.data());
        if(!shapeLayer)
            canDisplay = false;
    }
    if(inputNodes.last()->inherits("ValueNode")) {
        ValueNode *valueNode = qobject_cast<ValueNode *>(inputNodes.last());
        if(valueNode->value[2] == 0) { // Single element
            int index = valueNode->value[0];
        } else if(valueNode->value[2] == 1) { // Range of elements
            int min = valueNode->value[0];
            int max = valueNode->value[1];
            if(canDisplay) {
                value = new KisShapeLayer(*shapeLayer);
                ///////////////////////////////////////////////
                value->shapeManager()->setUpdatesBlocked(true);
//                for(int i = 0; i < value->shapeCount(); i++) {
//                    KoShape *shape = value->shapes().at(i);
//                    KIS_SAFE_ASSERT_RECOVER(shape) { continue; }
//                    if(i < min || i > max)
//                        value->shapeManager()->remove(shape);
////                        value->removeShape(shape);
//                }
                int i = 0;
                Q_FOREACH (KoShape *shape, value->shapes()) {
                    if(i < min || i > max)
//                        textItem->setPlainText(QString("Num shapes %1").arg(i));
                        value->removeShape(shape);
                    i++;
//                    KoShape *clonedShape = shape->cloneShape();
//                    KIS_SAFE_ASSERT_RECOVER(clonedShape) { continue; }
//                    clonedShape->setTransformation(shape->absoluteTransformation() * thisInvertedTransform);
//                    addShape(clonedShape);
                }
                value->shapeManager()->setUpdatesBlocked(false);
                ///////////////////////////////////////////////
                textItem->setPlainText(QString("Num shapes %1").arg(value->shapeCount()));
//                value->removeShape(value->shapes().last());
//                value->shapeManager()->remove(value->shapeManager()->shapes().last());
//                value->update();
////                while(value->shapeCount() > 0)
////                    value->removeShape(value->shapes().last());

//////                for(int i = 0; i < shapeLayer->childCount(); i++) {
//////                    KisNodeSP child = shapeLayer->childNodes(QStringList(), KoProperties())[i];
//////                    if(i >= min && i <= max)
//////                        value.data()->childNodes(QStringList(), KoProperties()).append(child);
//////                }
//                textItem->setPlainText(QString(""));
//                imageItem->show();
//                outputIO->SetVSpacing(130);
//                nodeItem->resizeBody();
////                shapeLayer = qobject_cast<KisShapeLayer*>(value.data());
//                QImage thumbnail = value->createThumbnail(130, 130, Qt::KeepAspectRatio);
//                imageItem->setPixmap(QPixmap::fromImage(thumbnail));
            } else {
                QVector<int> range = valueNode->value;
                textItem->setPlainText(QString("min: %1 max: %2 sel: %3").arg(range.at(0)).arg(range.at(1)).arg(range.at(2)));
            }
        }
//        if(canDisplay) {
//            textItem->setPlainText(QString(""));
//            imageItem->show();
//            outputIO->SetVSpacing(130);
//            nodeItem->resizeBody();
//            QImage thumbnail = shapeLayer->createThumbnail(130, 130, Qt::KeepAspectRatio);
//            imageItem->setPixmap(QPixmap::fromImage(thumbnail));
//        }
    } else {
        textItem->setPlainText(QString("Incorrect input type."));
        return;
    }
}
