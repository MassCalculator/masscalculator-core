#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::on_shape_currentIndexChanged(int index)
{
  switch (index)
  {
    case 1 :
    {
        std::unique_ptr<MassCalculator::Shape<MassCalculator::Cylinder>> shape(new MassCalculator::Cylinder(10.0, 10.0));
        std::stringstream from_ostream; from_ostream << *shape;
        ui->shape_res->setText(QString::fromStdString(from_ostream.str()));
        break;
    }

    default:
        break;
  }
}

void MainWindow::on_material_currentIndexChanged(int index)
{
       qDebug() << "Shape: ";// << *shape << std::endl;
}


void MainWindow::on_material_type_currentIndexChanged(int index)
{
        std::unique_ptr<MassCalculator::Shape<MassCalculator::Cylinder>> shape(new MassCalculator::Cylinder(10.0, 10.0));
       //qDebug() << "Shape: " << *shape << std::endl;
}

void MainWindow::on_calculate_btn_clicked()
{
  qDebug() << "Calculate";
}


MainWindow::~MainWindow()
{
    delete ui;
}
