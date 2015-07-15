#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

class QWidget;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QToolButton;
class QToolBar;
class QAction;
class QLabel;

const int ICONSIZE = 32  ;
const int PADDING  = 10  ;
const int WIDTH    = 1366;
const int HEIGHT   = 768 ;

class MainWindow : public QMainWindow 
{
  Q_OBJECT
 
public:
  MainWindow();


private slots:

  //slots for click events
  void manualClicked();
  void cameraClicked();
  void diveClicked();
  void waypointClicked();
  

private:
  //helper methods
  void setFlightIcon(std::string newFlightMode);
  void setFlightMode(std::string newFlightMode);

  //initialize window elements
  void createLayout();
  void createActions();
  void createToolbar();
  void createToolButtons();
  void createStatusbar();


  //class fields
  //previously, we use VBox and HBox, using Grid instead
  /*
  QVBoxLayout *mainWindowLayout;
  QHBoxLayout *flightModeLayout;
  */

  QWidget *centralWidget;
  QWidget *flightDataWidget;

  QGridLayout *mainWindowLayout;
  QHBoxLayout *flightDataLayout;

  QToolBar *flightModeToolbar;

  /*DEPRECATED as of now
  QToolButton *manualButton;
  QToolButton *cameraButton;
  QToolButton *diveButton;
  QToolButton *waypointButton;
  */

  //mode actions are normal unselected icons
  QAction *manualModeAction;
  QAction *cameraModeAction;
  QAction *diveModeAction;
  QAction *waypointModeAction;

  QLabel *flightModeLabel;
  std::string currentFlightMode;

};

#endif
