#include "./ui_sqlexplorer.h"
#include "sqlexplorer.h"
#include "credentials.h"

#include <QDebug>
#include <QLibraryInfo>
#include <pqxx/pqxx>
#include <iostream>
#include <QStandardItemModel>


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
    connect(ui->queryButton,&QPushButton::pressed,
            this,&sqlExplorer::queryCommand);

    printf("pqxx VERSION: %s\n", PQXX_VERSION);
    qDebug() << "Version:" << QLibraryInfo::version();

    queryCommand();
}

// void sqlExplorer::newQuery() // std::string queryText
// {
//     queryCommand(queryText);
// }

void sqlExplorer::queryCommand() // std::string queryText
{
    try{
        std::string combine = combinedCreds();
        pqxx::connection dbConn(combine);

        if (dbConn.is_open()) {
            std::cout << "Opened database successfully: " << dbConn.dbname() << std::endl;
            pqxx::work txn{dbConn};

            // pqxx::result r = txn.exec("SELECT table_name FROM information_schema.tables WHERE table_type='BASE TABLE' AND table_schema='public';");
            queryText = ui->queryEditor->toPlainText();
            pqxx::result r = txn.exec(queryText.toStdString());
            
            std::cout << r.columns() << "\n";
            std::cout << r.size() << "\n";
            // std::cout << typeid(r.columns()).name() << "\n";

            model = new QStandardItemModel(r.size(), r.columns());

            for (int row = 0; row < model->rowCount(); ++row) {
                for (int column = 0; column < model->columnCount(); ++column) {
                    QStandardItem *item = new QStandardItem(QString(r[row][column].c_str())); // "row %0, column %1").arg(row).arg(column
                    model->setItem(row, column, item);
                }
            }

            ui->resultsView->setModel(model);
            ui->resultsView->resizeColumnsToContents();


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
