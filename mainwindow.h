#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"view.h"
#include"openwidget.h"

#include <QMainWindow>
#include<QtWidgets>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT




public:
    MainWindow(QWidget *parent = nullptr);
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QMenu *fileMenu;
    QMenu *editMenue;
    QMenu *viewMenu;
    QAction *meshAction;
    QMenu *curve;
    QMenu *surface,*deform,*copy,*misc,*help;
    QToolBar *tool;
    QToolBar *tool1;
    QToolBar *rightTool;
    QBoxLayout *rightVLayout;
    QGridLayout *grid;


   // QGraphicsView *view;
    QGraphicsView *view1;
    ~MainWindow();

private slots:
        void messageBox();

private:
    Ui::MainWindow *ui;
    void setUpLayout();
    void createAction();
    void createMenus();
    void setSizePolicy(QSizePolicy);
    void horizontalToolBar();
    void verticleToolBar();
    void oneGrid();
    void twoGrid();
    void fourGrid();




    Openwidget *wid1,*wid2,*wid3,*wid4;

};
#endif // MAINWINDOW_H
