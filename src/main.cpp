#include "sqlexplorer.h"
#include "credsdialog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    credsDialog dia;
    dia.show();

    sqlExplorer wid;
    wid.show();
    return app.exec();
}
