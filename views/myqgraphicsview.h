#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class MyQGraphicsView : public QGraphicsView
{
public:
    MyQGraphicsView();
    QGraphicsScene *scene;
};

#endif // MYQGRAPHICSVIEW_H
