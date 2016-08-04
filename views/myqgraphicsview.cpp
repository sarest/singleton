#include "myqgraphicsview.h"

MyQGraphicsView::MyQGraphicsView()
{
    scene = new QGraphicsScene();

    this->setScene(scene);
}
