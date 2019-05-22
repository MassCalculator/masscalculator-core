#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>

#include "interface/object_interface.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_material_currentIndexChanged(int index);
    void on_material_type_currentIndexChanged(int index);
    void on_shape_currentIndexChanged(int index);
    void on_calculate_btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
