#ifndef SQLSEARCH_H
#define SQLSEARCH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class sqlSearch;
}
QT_END_NAMESPACE

class sqlSearch : public QMainWindow
{
    Q_OBJECT

public:
    sqlSearch(QWidget *parent = nullptr);
    ~sqlSearch();

private:
    Ui::sqlSearch *ui;
};
#endif // SQLSEARCH_H
