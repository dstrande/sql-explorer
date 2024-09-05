#ifndef SQLEXPLORER_H
#define SQLEXPLORER_H

#include <QMainWindow>
#include "query.h"


class QStandardItemModel;

QT_BEGIN_NAMESPACE
namespace Ui {
class sqlExplorer;
}
QT_END_NAMESPACE

class sqlExplorer : public QMainWindow
{
    Q_OBJECT

public:
    sqlExplorer(QWidget *parent = nullptr);
    ~sqlExplorer();
    void linkCreds();
    void setCreds();

private:
    Ui::sqlExplorer *ui;
    QStandardItemModel *model;
    QString queryText;
    std::string combineSlotStr;

private slots:
    void queryCommand();
    void setFontSize();
    void setCreds(QString combineSlot);
    // void newQuery(std::string queryText);
};

#endif // SQLEXPLORER_H
