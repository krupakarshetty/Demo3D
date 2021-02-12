#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"view.h"
#include<QFrame>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<Qt3DExtras/Qt3DWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     wid1=new Openwidget();
     wid2=new Openwidget();
     wid3=new Openwidget();
     wid4=new Openwidget();


     wid2->setVisible(false);
     wid3->setVisible(false);
     wid4->setVisible(false);


     setUpLayout();
     createMenus();
}

void MainWindow::setUpLayout()
{
    //Main Widget
    QWidget *widget=new QWidget();

    //Verticle Layout
    QVBoxLayout *box=new QVBoxLayout;
    grid=new QGridLayout;


    //Horizontal Layout
    hLayout=new QHBoxLayout();
    hLayout->setSpacing(5);

    //Header ToolBar
    tool=new QToolBar;

    //LeftSide Verticle Toolbar
    tool1=new QToolBar;



    //Right Side ToolBar
    rightTool=new QToolBar;



    //adding widget to gridview
    grid->addWidget(wid1,0,0);
    grid->addWidget(wid2,0,1);
    grid->addWidget(wid3,1,0);
    grid->addWidget(wid4,1,1);
    widget->setStyleSheet("border: 1px solid black");



    //adding Left ToolBar to horizontal Layout
    hLayout->addWidget(tool1,10);


    //Adding Grid Layout
    hLayout->addLayout(grid);

    //placing rightTool bar to right side
    addToolBar(Qt::RightToolBarArea ,rightTool);

    //adding right toolbar
    hLayout->addWidget(rightTool);

    //adding main Tool bar to main Layout
    box->addWidget(tool);

    //adding Horizontal Layout to MainLayout
    box->addLayout(hLayout);

     //Setting Layout
     widget->setLayout(box);

    setCentralWidget(widget);

    setWindowTitle("Demo3D");

}


void MainWindow::createMenus()
{
    //File Menu
    fileMenu=fileMenu=menuBar()->addMenu(tr("&File"));
    auto New=new QAction("New");
    New->setShortcuts(QKeySequence::New);
    New->setStatusTip(tr("Create New File"));
    fileMenu->addAction(New);
    connect(New,&QAction::triggered,this,&MainWindow::messageBox);

    //Open
    auto openAct=new QAction(tr("&Open"),this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(tr("Open File"));
    fileMenu->addAction(openAct);
    connect(openAct,&QAction::triggered,this,&MainWindow::messageBox);


    //save
    auto saveAct=new QAction(tr("&Save"),this);
    saveAct->setShortcut(QKeySequence::Save);
    saveAct->setStatusTip("Save your File");
    fileMenu->addAction(saveAct);
    connect(saveAct,&QAction::triggered,this,&MainWindow::messageBox);

    //exit
    auto exitAct=new QAction(tr("&Exit"));
    exitAct->setShortcut(QKeySequence::Quit);
    exitAct->setStatusTip("Exit");
    fileMenu->addAction(exitAct);
    connect(exitAct,&QAction::triggered,this,&MainWindow::messageBox);


    //Edit Menu
    editMenue=menuBar()->addMenu(tr("&Edit"));
    auto undoAct=new QAction(tr("&Undo"));
    undoAct->setShortcut(QKeySequence::Undo);
    undoAct->setStatusTip("Undo Your Work");
    editMenue->addAction(undoAct);

    //redo
    auto redoAct=new QAction(tr("&Undo"));
    redoAct->setShortcut(QKeySequence::Redo);
    redoAct->setStatusTip("Redo Your Work");
    editMenue->addAction(redoAct);

    viewMenu=menuBar()->addMenu(tr("&View"));
    curve=menuBar()->addMenu(tr("&Curve"));
    copy=menuBar()->addMenu(tr("&Copy"));
    deform=menuBar()->addMenu(tr("&Deform"));
    misc=menuBar()->addMenu(tr("&Misc"));
    help=menuBar()->addMenu(tr("&Help"));

    //adding toolbars
    verticleToolBar();
    horizontalToolBar();

}

void MainWindow::horizontalToolBar()
{
    //header Tool Bar
    tool->setStyle(QApplication::style());

    //new file
    QAction *newAction=new QAction("New",this);
    newAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/add-file.png"));
    tool->addAction(newAction);
    connect(newAction,&QAction::triggered,this,&MainWindow::messageBox);


    //open File
    QAction *openAction=new QAction("Open",this);
    openAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/open.png"));
    tool->addAction(openAction);
    connect(openAction,&QAction::triggered,this,&MainWindow::messageBox);


    //Save
    QAction *saveAction=new QAction("Save",this);
    saveAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/floppy-disk.png"));
    tool->addAction(saveAction);
    connect(saveAction,&QAction::triggered,this,&MainWindow::messageBox);

    //Mesh
    meshAction=new QAction("Mesh",this);
    meshAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/mesh.png"));
    tool->addAction(meshAction);
    connect(meshAction,&QAction::triggered,this,&MainWindow::twoGrid);

    //viewPort
    QAction *viewAction=new QAction("viewPort",this);
    viewAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/viewport.png"));
    tool->addAction(viewAction);
    connect(viewAction,&QAction::triggered,this,&MainWindow::fourGrid);

    //rectangle
    QAction *rectangleAction=new QAction("Rectangle",this);
    rectangleAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/rounded-rectangle.png"));
    tool->addAction(rectangleAction);
    connect(rectangleAction,&QAction::triggered,this,&MainWindow::oneGrid);


}

void MainWindow::verticleToolBar()
{

    /* Verticle tool bar  Right side*/

    //Bend Action
    QAction *bendAction=new QAction("Bend",this);
    tool1->addAction(bendAction);
    bendAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/Bend.png"));
    connect(bendAction,&QAction::triggered,this,&MainWindow::messageBox);

    //BendTwo
    QAction *bendTwoAction=new QAction("Bend Two side",this);
    tool1->addAction(bendTwoAction);
    bendTwoAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/bendTwo.png"));
    connect(bendTwoAction,&QAction::triggered,this,&MainWindow::messageBox);


    //taperAction
    QAction *taperAction=new QAction("Taper",this);
    tool1->addAction(taperAction);
    taperAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/tampertwo.png"));
    connect(taperAction,&QAction::triggered,this,&MainWindow::messageBox);

    //two side taper
    QAction *taperTwoAction=new QAction("Taper Two sides",this);
    tool1->addAction(taperTwoAction);
    taperTwoAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/tampertwo.png"));
    connect(taperTwoAction,&QAction::triggered,this,&MainWindow::messageBox);

    //scaled  Taper
    QAction *scaledTaperAction=new QAction("Scaled Taper",this);
    tool1->addAction(scaledTaperAction);
    scaledTaperAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/scaledtamper.png"));

    //scaled  Taper Two
    QAction *scaledTaperTwoAction=new QAction("Scaled Taper",this);
    tool1->addAction(scaledTaperTwoAction);
    scaledTaperTwoAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/scaledtampertwo.png"));

    //SKew
    QAction *skewAction=new QAction("Skew",this);
    tool1->addAction(skewAction);
    skewAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/skewTwo.png"));

    //Skew Two
    QAction *skewTwoAction=new QAction("Skew Two side",this);
    tool1->addAction(skewTwoAction);
    skewTwoAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/skew.png"));


    tool1->setOrientation(Qt::Vertical);


    rightTool->setOrientation(Qt::Vertical);
    //rightVLayout->addWidget(rightTool);
    //rightVLayout->setAlignment(Qt::AlignRight|Qt::AlignTop);

    rightTool->addAction(skewTwoAction);
    skewTwoAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/skew.png"));

    rightTool->addAction(scaledTaperTwoAction);
    scaledTaperTwoAction->setIcon(QIcon::fromTheme(":/new/prefix1/C:/Users/USER/Desktop/Icons/scaledtampertwo.png"));

}




void MainWindow::messageBox()
{
    auto message=new QMessageBox();
    message->setText("Work in Progress :)");
    message->exec();
}



//view port

void MainWindow::oneGrid()
{

    wid1->setVisible(true);
    wid2->setVisible(false);
    wid3->setVisible(false);
    wid4->setVisible(false);

}

void MainWindow::twoGrid()
{
    wid1->setVisible(true);
    wid2->setVisible(true);
    wid3->setVisible(false);
    wid4->setVisible(false);
}

void MainWindow::fourGrid()
{
    wid1->setVisible(true);
    wid2->setVisible(true);
    wid3->setVisible(true);
    wid4->setVisible(true);

}
MainWindow::~MainWindow()
{
    delete ui;
}

