#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sqlexplorer.h"
#include "secrets.h"

#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QLibraryInfo>
#include <pqxx/pqxx>



int main(int argc, char *argv[]) {
    std::string db_name = DB_NAME;
    std::string host_addr = HOST_ADDR;
    std::string port_number = PORT_NUMBER;
    std::string user_name = USER_NAME;
    std::string pass_word = PASS_WORD;

    std::string combine="dbname=";
    combine += db_name;
    combine += " user=";
    combine += user_name;
    combine += " password=";
    combine += pass_word;
    combine += " hostaddr=";
    combine += host_addr;
    combine += " port=";
    combine += port_number;

    try{
        pqxx::connection dbConn(combine);
        if (dbConn.is_open()) {
            std::cout << "Opened database successfully: " << dbConn.dbname() << std::endl;
            pqxx::work txn{dbConn};

            pqxx::result r = txn.exec("SELECT * FROM pg_catalog.pg_tables;");

            for (auto name : r[0])
                {
                    std::cout << name.c_str() << "\n";
                }

        } else {
            std::cout << "Can't open database" << std::endl;
            return 1;
        }
    }catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }

    printf("pqxx VERSION: %s\n", PQXX_VERSION);

    pqxx::connection dbConn(combine);

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
