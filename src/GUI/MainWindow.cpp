//
// Created by rienel on 04.05.18.
//

#include <QtSql/QSqlRelationalTableModel>
#include "MainWindow.h"


MainWindow::MainWindow(QMainWindow *pwgt) : QMainWindow(pwgt) {
    this->pTable = new QTableWidget();
    this->pButton = new QPushButton();
    this->menu = new QMenuBar;

    QMenu *files = new QMenu("&Files");
    menu->addMenu(files);

    QAction *exit = new QAction("&Close");

    connect(exit, &QAction::triggered, this, &MainWindow::close);
    files->addAction(exit);
    this->setCentralWidget(pTable);
    this->setMenuBar(menu);
}

QTableWidget *MainWindow::getPTable() const {
    return pTable;
}

void MainWindow::setPTable(QTableWidget *pTable) {
    MainWindow::pTable = pTable;
}

QPushButton *MainWindow::getPButton() const {
    return pButton;
}

void MainWindow::setPButton(QPushButton *pButton) {
    MainWindow::pButton = pButton;
}

QTabWidget *MainWindow::getTabWidget() const {
    return tabWidget;
}

void MainWindow::setTabWidget(QTabWidget *tabWidget) {
    MainWindow::tabWidget = tabWidget;
}

MainWindow::~MainWindow() {
    delete this->pButton;
    delete this->pTable;
    delete this->tabWidget;
    delete this->menu;
}

template<class modelClass, class daoClass>
void MainWindow::renderTable() {
    QList<modelClass *> objectList = daoClass().getAll();
    this->pTable->setRowCount(objectList.size());
    this->pTable->setColumnCount(modelClass::columnList.length());

    this->pTable->setHorizontalHeaderLabels(modelClass::columnList);

//    this->
}
