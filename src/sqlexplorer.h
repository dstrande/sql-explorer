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

private:
    Ui::sqlExplorer *ui;
    QStandardItemModel *model;
    QString queryText;

private slots:
    void queryCommand();
    void setFontSize();
    // void newQuery(std::string queryText);
};

#endif // SQLEXPLORER_H
