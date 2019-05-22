#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  MainWindow mainWin;

  mainWin.show();
  mainWin.setFixedSize(mainWin.size());

  return app.exec();
}
