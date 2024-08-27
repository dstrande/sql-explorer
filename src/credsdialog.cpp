#include "./ui_credsDialog.h"
#include "credsdialog.h"


credsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::credsDialog)
{
    ui->setupUi(this);

    addressText = ui->addressTextEdit->toPlainText();
    dbNameText = ui->dbNameTextEdit->toPlainText();
    passwordText = ui->passwordTextEdit->toPlainText();
    portText = ui->portTextEdit->toPlainText();
    usernameText = ui->usernameTextEdit->toPlainText();

    QString combine = "dbname=";
    combine.append(dbNameText);
    combine.append(" user=");
    combine.append(usernameText);
    combine.append(" password=");
    combine.append(passwordText);
    combine.append(" hostaddr=");
    combine.append(addressText);
    combine.append(" port=");
    combine.append(portText);
}


// credsDialog::~credsDialog()
// {
//     delete ui;
// }
