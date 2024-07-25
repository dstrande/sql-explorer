#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sqlexplorer.h"
#include <iostream>

#include <QApplication>
#include <QDebug>
#include <QLibraryInfo>
#include <pqxx/pqxx>


int main(int argc, char *argv[]) {
    printf("pqxx VERSION: %s\n", PQXX_VERSION);
    qDebug() << "Version:" << QLibraryInfo::version();
    qDebug() << "Prefix :" << QLibraryInfo::location(QLibraryInfo::PrefixPath);
    qDebug() << "Libs   :" << QLibraryInfo::location(QLibraryInfo::LibrariesPath);
    qDebug() << "Plugins:" << QLibraryInfo::location(QLibraryInfo::PluginsPath);
    qDebug() << "Libexec:" << QLibraryInfo::location(QLibraryInfo::LibraryExecutablesPath);

    QApplication a(argc, argv);
    sqlExplorer w;
    w.show();
    return a.exec();
}
