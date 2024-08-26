#include "./ui_credsDialog.h"
#include "credsdialog.h"


credsDialog::credsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::credsDialog)
{
    ui->setupUi(this);
}


// credsDialog::~credsDialog()
// {
//     delete ui;
// }
