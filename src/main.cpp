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
    char buffer_in [256] = {"Conan is a MIT-licensed, Open Source package manager for C and C++ development, "
                            "allowing development teams to easily and efficiently manage their packages and "
                            "dependencies across platforms and build systems."};
    char buffer_out [256] = {0};

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
