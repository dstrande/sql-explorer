#include "sqlexplorer.h"
#include "./ui_sqlexplorer.h"
#include "credentials.h"

#include <QDebug>
#include <QLibraryInfo>
#include <pqxx/pqxx>
#include <iostream>

sqlExplorer::sqlExplorer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sqlExplorer)
{
    ui->setupUi(this);

    //Initializer the members with values from the ui
    queryText = ui->queryEditor->toPlainText();

//     //Connect ui components to respective slots
//     connect(ui->queryEditor,&QTextEdit::textChanged,
//             this,&Widget::weight_changed);

    printf("pqxx VERSION: %s\n", PQXX_VERSION);
    qDebug() << "Version:" << QLibraryInfo::version();

    queryCommand(queryText.toStdString());
}

void sqlExplorer::queryCommand(std::string queryText)
{
    try{
        std::string combine = combinedCreds();
        pqxx::connection dbConn(combine);

        if (dbConn.is_open()) {
            std::cout << "Opened database successfully: " << dbConn.dbname() << std::endl;
            pqxx::work txn{dbConn};

            // pqxx::result r = txn.exec("SELECT table_name FROM information_schema.tables WHERE table_type='BASE TABLE' AND table_schema='public';");
            pqxx::result r = txn.exec(queryText);
            
            std::cout << r.columns() << "\n";
            std::cout << r.size() << "\n";
            
            std::cout << r[1][1] << "\n";

            for (auto row : r)
                {
                    for (auto col : row)
                        {std::cout << col << "\n";}
                }

            // std::cout << "Columns:\n";
            // for (pqxx::row_size_type col = 0; col < r.columns(); ++col)
            //     {
            //         for (int row = 0; row < r.size(); ++row)
            //         {
            //             std::cout << col << ", " << row << ": " << r[row][col].c_str() << '\n';
            //         }
            //     }
            
            // for (auto row : r[0])
            //     {
            //         std::cout << row << "\n";
            //     }

        } else {
            std::cout << "Can't open database" << std::endl;
        }
    }catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}

sqlExplorer::~sqlExplorer()
{
    delete ui;
}
