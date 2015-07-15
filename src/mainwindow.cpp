#include <QtGui> //TODO: replace later for efficiency
#include "mainwindow.h"

MainWindow::MainWindow(){
  //TODO: set video frame to be the central frame, be careful of waypoint and video switching

  //initial states
  currentFlightMode = "MANUAL";

  flightModeLabel = new QLabel(QString::fromStdString("MANUAL"));
  flightModeLabel->setMinimumHeight(24);
  flightModeLabel->setStyleSheet("QLabel {color:#00ff00; font-size: 20px }");

  createActions();
  createToolbar();
  //createToolButtons();
  createLayout();
  createStatusbar();
  
  //window parameters
  setWindowFlags(Qt::FramelessWindowHint); //fullscreeen without headers

  //has to be here since action have not been initialized
  setFlightIcon("MANUAL");

  }


//setting up the slots here
void MainWindow::manualClicked(){
  if (currentFlightMode.compare("MANUAL") == 0) { //if the string are exactly the same
    //don't update, since user pressed the same button twice
    statusBar()->showMessage("Manual mode is already selected.",2000);
    } 
  else {
    setFlightMode("MANUAL"); //changing flight mode
    statusBar()->showMessage("Manual mode activated.",2000); //send to status bar for debug purposes
    }  

 }

void MainWindow::cameraClicked(){
  if  (currentFlightMode.compare("CAMERA") == 0) { //if the string are exactly the same
    //don't update, since user pressed the same button twice
    statusBar()->showMessage("Camera mode is already selected.",2000);
    } 
  else {
    setFlightMode("CAMERA"); //changing flight mode
    statusBar()->showMessage("Camera mode activated.",2000); //send to status bar for debug purposes
    }  


  }

void MainWindow::diveClicked(){
  if (currentFlightMode.compare("DIVE") == 0) { //if the string are exactly the same
    //don't update, since user pressed the same button twice
    statusBar()->showMessage("Dive mode is already selected.",2000);
    } 
  else {
    setFlightMode("DIVE"); //changing flight mode
    statusBar()->showMessage("Dive mode activated.",2000); //send to status bar for debug purposes
    }  


  }

void MainWindow::waypointClicked(){
  if (currentFlightMode.compare("WAYPOINT") == 0) { //if the string are exactly the same
    //don't update, since user pressed the same button twice
    statusBar()->showMessage("Waypoint mode is already selected.",2000);
    } 
  else {
    setFlightMode("WAYPOINT"); //changing flight mode
    statusBar()->showMessage("Waypoint mode activated.",2000); //send to status bar for debug purposes
    }  


  }

void MainWindow::createLayout(){

  /* this is for VBox layouts
  mainWindowLayout = new QVBoxLayout;
  
  QWidget *hohoWidget = new QWidget();
  hohoWidget->resize()

  flightDataWidget = new QWidget();
  flightDataWidget->setStyleSheet("{ background-color: #101010; }");
  flightDataLayout = new QHBoxLayout;

  flightDataLayout->addWidget(new QPushButton ("hello1"));
  flightDataLayout->addWidget(new QPushButton ("hello2"));
  flightDataLayout->addWidget(new QPushButton ("hello3"));
  flightDataLayout->addWidget(new QPushButton ("hello4"));

  flightDataWidget->setLayout(flightDataLayout);

  mainWindowLayout->addWidget(hohoWidget,0,Qt::AlignCenter);
  mainWindowLayout->addWidget(flightModeToolbar,0,Qt::AlignCenter);  
  mainWindowLayout->addWidget(flightDataWidget,0,Qt::AlignCenter);
  mainWindowLayout->addWidget(new QTextEdit(),200,Qt::AlignCenter);


  
  */
  mainWindowLayout = new QGridLayout();

  
  flightDataWidget = new QWidget();
  flightDataLayout = new QHBoxLayout();
  /*
  QFrame *filler1 = new QFrame();
  filler1->setFrameShape(QFrame::Panel);
  filler1->setFrameRect(QRect(0,0,WIDTH,HEIGHT-200));
  filler1->setStyleSheet("QFrame {background-color:white;}");
  */


  //placeholder for future video buffers
  QLabel *filler1 = new QLabel();
  filler1->setMinimumSize(QSize(WIDTH-20, HEIGHT-170) );
  filler1->setStyleSheet("QLabel {background-color:#ffffff;}");
  
  //flightDataWidget->setLayout(flightDataLayout);
  //flightDataWidget->setMinimumHeight(24);

  //this is the first row, data display
  //mainWindowLayout->addWidget(flightDataWidget,0,0,1,7,Qt::AlignCenter);
  mainWindowLayout->addWidget(flightModeLabel,0,8,1,4,Qt::AlignCenter);

  //second row, i.e. toolbar
  mainWindowLayout->addWidget(flightModeToolbar,1,8,1,4,Qt::AlignCenter);

  //third row, i.e. content
  mainWindowLayout->addWidget(filler1,2,0,32,20,Qt::AlignCenter);

  //where everything comes together, the central widget, i.e. the whole space
  centralWidget = new QWidget();
  centralWidget->setLayout(mainWindowLayout);
  centralWidget->setStyleSheet("QWidget { background-color: #101010;}");
  setCentralWidget(centralWidget);

  }


//initialize necessary actions,toolbars,and statusbars
void MainWindow::createActions(){
  manualModeAction = new QAction(QIcon(":/images/manual-grey.png"),"Manual control for drone",this);
  connect(manualModeAction,SIGNAL(triggered()),this,SLOT(manualClicked()));

  cameraModeAction = new QAction(QIcon(":/images/camera-grey.png"),"Control camera movement while drone is stationary",this);
  connect(cameraModeAction,SIGNAL(triggered()),this,SLOT(cameraClicked()));

  diveModeAction = new QAction(QIcon(":/images/dive-grey.png"),"Dive to target in the center of drone",this);
  connect(diveModeAction,SIGNAL(triggered()),this,SLOT(diveClicked()));

  waypointModeAction = new QAction(QIcon(":/images/waypoint-grey.png"),"Waypoint plotting and execution",this);
  connect(waypointModeAction,SIGNAL(triggered()),this,SLOT(waypointClicked()));
  

  /*
  manualSelected = new QAction(QIcon(":/images/manual.png"),"MANUAL",this);
  connect(manualSelected,SIGNAL(triggered()),this,SLOT(manualClicked()));

  cameraSelected = new QAction(QIcon(":/images/camera.png"),"CAMERA",this);
  connect(cameraSelected,SIGNAL(triggered()),this,SLOT(cameraClicked()));

  diveSelected = new QAction(QIcon(":/images/dive.png"),"DIVE",this);
  connect(diveSelected,SIGNAL(triggered()),this,SLOT(diveClicked()));

  waypointSelected = new QAction(QIcon(":/images/waypoint.png"),"WAYPOINT",this);
  connect(waypointSelected,SIGNAL(triggered()),this,SLOT(waypointClicked()));
  */
  

  }

void MainWindow::createToolbar(){
  flightModeToolbar = addToolBar("Flight Modes");
  
  flightModeToolbar->addSeparator();
  flightModeToolbar->addAction(manualModeAction);  
  flightModeToolbar->addSeparator();
  flightModeToolbar->addAction(cameraModeAction);
  flightModeToolbar->addSeparator();
  flightModeToolbar->addAction(diveModeAction);
  flightModeToolbar->addSeparator();
  flightModeToolbar->addAction(waypointModeAction);
  flightModeToolbar->addSeparator();

  flightModeToolbar->setIconSize(QSize(ICONSIZE,ICONSIZE));
  flightModeToolbar->setMovable(true);
  flightModeToolbar->setAllowedAreas(Qt::NoToolBarArea);
  //flightModeToolbar->setWindowFlags(Qt::QtTool
  flightModeToolbar->setStyleSheet("QToolBar {background-color:#101010; padding: 2px; spacing: 4px;}");

  }
/*
void MainWindow::createToolButtons(){
  manualButton = new QToolButton(this);
  manualButton->setDefaultAction(manualModeAction);
  manualButton->setAutoRaise(true);
  manualButton->setIconSize(QSize(64,64));

  cameraButton = new QToolButton(this);
  cameraButton->setDefaultAction(cameraModeAction);
  cameraButton->setAutoRaise(true);

  diveButton = new QToolButton(this);
  diveButton->setDefaultAction(diveModeAction);
  diveButton->setAutoRaise(true);
  
  waypointButton = new QToolButton(this);
  waypointButton->setDefaultAction(waypointModeAction);
  waypointButton->setAutoRaise(true);

  }
*/

void MainWindow::createStatusbar(){
  
  if (currentFlightMode.compare("MANUAL")== 0){
    statusBar()->showMessage("MANUAL",2000);
    }
  else if (currentFlightMode.compare("CAMERA") == 0){
    statusBar()->showMessage("CAMERA",2000);
    }
  else if (currentFlightMode.compare("DIVE") == 0){
    statusBar()->showMessage("DIVE",2000);    
    }
  else if (currentFlightMode.compare("WAYPOINT") == 0) {
    statusBar()->showMessage("WAYPOINT",2000);
    }
  else {
    statusBar()->showMessage("Ready");
    }

  }


void MainWindow::setFlightIcon(std::string newFlightMode){

  if (currentFlightMode.compare("MANUAL")== 0){
    manualModeAction->setIcon(QIcon(":/images/manual-grey.png"));
    }
  else if (currentFlightMode.compare("CAMERA") == 0){
    cameraModeAction->setIcon(QIcon(":/images/camera-grey.png"));
    }
  else if (currentFlightMode.compare("DIVE") == 0){
    diveModeAction->setIcon(QIcon(":/images/dive-grey.png"));
    }
  else {
    waypointModeAction->setIcon(QIcon(":/images/waypoint-grey.png"));
    }


  if (newFlightMode.compare("MANUAL")== 0){
    manualModeAction->setIcon(QIcon(":/images/manual-green.png"));
    }
  else if (newFlightMode.compare("CAMERA") == 0){
    cameraModeAction->setIcon(QIcon(":/images/camera-green.png"));
    }
  else if (newFlightMode.compare("DIVE") == 0){
    diveModeAction->setIcon(QIcon(":/images/dive-green.png"));
    }
  else {
    waypointModeAction->setIcon(QIcon(":/images/waypoint-green.png"));
    }

  }


void MainWindow::setFlightMode(std::string newFlightMode){
  setFlightIcon(newFlightMode);
  currentFlightMode = newFlightMode;
  flightModeLabel->setText(QString::fromStdString(newFlightMode));
  }


