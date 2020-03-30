#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

// #define stringify( name ) # name

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  //TODO: Initialize the Combo boxes here, create seperated functions 

  ui->material->setDisabled(true);
  ui->material_type->setDisabled(true);

  // ui->material_type->setDisabled(false);
  for(auto type = static_cast<int>(MassCalculator::Shape<decltype(42)>::Type::BEGIN); type < static_cast<int>(MassCalculator::Shape<decltype(42)>::Type::END); type++)
  {
    std::stringstream ss; ss << static_cast<MassCalculator::Shape<decltype(42)>::Type>(type);
    ui->shape->addItem(ss.str().c_str());
    // ui->material_type->insertItem(type, ss.str().c_str());
  }

}

void MainWindow::on_shape_currentIndexChanged(int index)
{
  switch (index)
  {
    case 0 :
    {

      break;
    }
    case 1 :
    {
      ui->material->setDisabled(true);
      ui->material_type->setDisabled(true);
      break;
    }
    case static_cast<int>(MassCalculator::Shape<decltype(42)>::Type::Cylinder) + 2 :
    {
      ui->material->setDisabled(false);
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
  switch (index)
  {
    case 0 :
      {
        ui->material_type->setDisabled(false);

      }
      break;

    case 1 :
      {
        ui->material_type->setDisabled(false);
        for(auto type = static_cast<int>(MassCalculator::Materials::Aluminium::Type::BEGIN); type < static_cast<int>(MassCalculator::Materials::Aluminium::Type::END); type++)
        {
          std::stringstream ss; ss << static_cast<MassCalculator::Materials::Aluminium::Type>(type);
          ui->material_type->addItem(ss.str().c_str());
          // ui->material_type->insertItem(type, ss.str().c_str());
        }
      }
      break;
    
    default:
    {
      ui->material_type->clear();
      ui->material_type->setDisabled(true);
    }
      break;
  }


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
