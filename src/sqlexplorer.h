#ifndef SQLSEARCH_H
#define SQLSEARCH_H

#include <QMainWindow>
#include "query.h"

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
    QString queryText;

private slots:
    void queryCommand(std::string queryText);
};
#endif // SQLSEARCH_H
