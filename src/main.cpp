#include "sqlexplorer.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sqlExplorer w;
    w.show();
    return a.exec();
}
