#ifndef CREDSDIALOG_H
#define CREDSDIALOG_H

#include <QDialog>


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

signals:
   void signalCreds(QString combineSlot);

private slots:
    void triggerSignal();
};

#endif // CREDSDIALOG_H
