#include <QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"

int main(int argc, char *argv[]){

  
  //parameters for main window of Qt
  int screenWidth;
  int screenHeight;
  
  Q_INIT_RESOURCE(squadplanner);

  QApplication app(argc,argv); //whole app holder
  MainWindow *mainwindow = new MainWindow();

  //Get monitor size and resolutions
  QDesktopWidget *desktop = QApplication::desktop();   
  screenWidth = desktop->width();
  screenHeight= desktop->height();

  //assign position to window
  mainwindow->showMaximized();
  mainwindow->setWindowTitle("SquadPlanner");
  mainwindow->setWindowIcon(QIcon(":/images/planner.png")); //TODO: set SQUAD icon here, in current working directory

  mainwindow->show();


  return app.exec();



  }
