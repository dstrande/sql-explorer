#include "sqlsearch.h"
#include "./ui_sqlsearch.h"

sqlSearch::sqlSearch(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sqlSearch)
{
    ui->setupUi(this);
}

sqlSearch::~sqlSearch()
{
    delete ui;
}
