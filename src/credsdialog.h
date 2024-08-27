#ifndef CREDSDIALOG_H
#define CREDSDIALOG_H

#include <QDialog>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui {
class credsDialog;
}
QT_END_NAMESPACE

class credsDialog : public QDialog
{
    Q_OBJECT

public:
    credsDialog(QWidget *parent = nullptr);

private:
    Ui::credsDialog *ui;
    QString addressText;
    QString dbNameText;
    QString passwordText;
    QString portText;
    QString usernameText;
    QString combine;
};

#endif // CREDSDIALOG_H
