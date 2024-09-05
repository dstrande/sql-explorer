#include "./ui_sqlexplorer.h"
#include "sqlexplorer.h"
#include "credentials.h"
#include "examples.h"
#include "credsdialog.h"

#include <QDebug>
#include <QLibraryInfo>
#include <pqxx/pqxx>
#include <iostream>
#include <QStandardItemModel>
#include <QTextCursor>


sqlExplorer::sqlExplorer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sqlExplorer)
{
    ui->setupUi(this);

    // Initializer the members with values from the ui
    queryText = ui->queryEditor->toPlainText();

    connect(ui->queryButton,&QPushButton::pressed,
            this,&sqlExplorer::queryCommand);

    // Connect example QActions to text
    connect(ui->actionSELECT,&QAction::triggered,[=](){
        ui->queryEditor->setText(selectText);
    });
    connect(ui->actionSELECT,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionINSERT,&QAction::triggered,[=](){
        ui->queryEditor->setText(insertText);
    });
    connect(ui->actionINSERT,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionALTER_TABLE,&QAction::triggered,[=](){
        ui->queryEditor->setText(alterTableText);
    });
    connect(ui->actionALTER_TABLE,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionCREATE_TABLE,&QAction::triggered,[=](){
        ui->queryEditor->setText(createTableText);
    });
    connect(ui->actionCREATE_TABLE,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionDELETE,&QAction::triggered,[=](){
        ui->queryEditor->setText(deleteText);
    });
    connect(ui->actionDELETE,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionDROP_TABLE,&QAction::triggered,[=](){
        ui->queryEditor->setText(dropTableText);
    });
    connect(ui->actionDROP_TABLE,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionJOIN,&QAction::triggered,[=](){
        ui->queryEditor->setText(joinText);
    });
    connect(ui->actionJOIN,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionORDER_BY,&QAction::triggered,[=](){
        ui->queryEditor->setText(orderByText);
    });
    connect(ui->actionORDER_BY,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionUPDATE,&QAction::triggered,[=](){
        ui->queryEditor->setText(updateText);
    });
    connect(ui->actionUPDATE,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    connect(ui->actionWHERE,&QAction::triggered,[=](){
        ui->queryEditor->setText(whereText);
    });
    connect(ui->actionWHERE,&QAction::triggered,
            this,&sqlExplorer::setFontSize);

    printf("pqxx VERSION: %s\n", PQXX_VERSION);
    qDebug() << "Version:" << QLibraryInfo::version();

    credsDialog* creds = new credsDialog();
    connect(creds, &credsDialog::signalCreds, this, static_cast<void (sqlExplorer::*)(QString)>(&sqlExplorer::setCreds));

    creds->exec();
}

void sqlExplorer::queryCommand()
{
    try{
        if (combineSlotStr.empty()) {
            std::cerr << "Error: Credentials string is empty." << std::endl;
            return;  // Exit early if no credentials are available
        }

        std::string combine = combineSlotStr;
        std::cout << "Received credentials: " << combine << std::endl;
        pqxx::connection dbConn(combine);

        if (dbConn.is_open()) {
            std::cout << "Opened database successfully: " << dbConn.dbname() << std::endl;
            pqxx::work txn{dbConn};

            // SELECT table_name FROM information_schema.tables WHERE table_type='BASE TABLE' AND table_schema='public';
            queryText = ui->queryEditor->toPlainText();
            pqxx::result r = txn.exec(queryText.toStdString());

            std::cout << r.columns() << "\n";
            std::cout << r.size() << "\n";

            model = new QStandardItemModel(r.size(), r.columns());

            for (int column = 0; column < model->columnCount(); ++column) {
                QStandardItem *infoItem = new QStandardItem(r.column_name(column));
                model->setHorizontalHeaderItem(column, infoItem);
                for (int row = 0; row < model->rowCount(); ++row) {
                    QStandardItem *item = new QStandardItem(QString(r[row][column].c_str()));
                    model->setItem(row, column, item);
                }
            }

            ui->resultsView->setModel(model);
            ui->resultsView->resizeColumnsToContents();

        } else {
            std::cout << "Can't open database" << std::endl;
        }
    }catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}


void sqlExplorer::setCreds(QString combineSlot)
{
    combineSlotStr = combineSlot.toStdString();

    qDebug() << "Credentials received and stored in combineSlotStr: " << QString::fromStdString(combineSlotStr);
    std::cout << "Received credentials: " << combineSlotStr << std::endl;
}


void sqlExplorer::setFontSize()
{
    QTextCursor cursor = ui->queryEditor->textCursor();
    ui->queryEditor->selectAll();
    ui->queryEditor->setFontFamily("Ubuntu");
    ui->queryEditor->setFontPointSize(12);
    ui->queryEditor->setTextCursor(cursor);
}

sqlExplorer::~sqlExplorer()
{
    delete ui;
}
