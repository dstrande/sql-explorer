#include "sqlexplorer.h"
#include "./ui_sqlexplorer.h"

sqlExplorer::sqlExplorer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sqlExplorer)
{
    ui->setupUi(this);
}

sqlExplorer::~sqlExplorer()
{
    delete ui;
}
