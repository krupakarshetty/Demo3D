#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QWidget>
#include<QGraphicsView>

class view:public QGraphicsView
{
public:
    view();
protected:
    void wheelEvent(QWheelEvent *) override;
};

#endif // VIEW_H
