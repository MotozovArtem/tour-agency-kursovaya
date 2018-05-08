//
// Created by rienel on 04.05.18.
//

#include <QtSql/QSqlRelationalTableModel>
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *pwgt) : QWidget(pwgt) {
    this->pLayout= new QVBoxLayout();
    this->pTable = new QTableWidget();
    this->pButton = new QPushButton("Submit");

    this->tabWidget = new QTabWidget();

    pLayout->addWidget(pTable);
    pLayout->addWidget(pButton);
    pLayout->addWidget(tabWidget);
    pTable->show();

    QWidget::setLayout(pLayout);
}

MainWindow::~MainWindow() {
    delete this->pLayout;
    delete this->pTable;
    delete this->pButton;
    delete this->tabWidget;
}

QTabWidget *MainWindow::getTabWidget() const {
    return tabWidget;
}

void MainWindow::setTabWidget(QTabWidget *tabWidget) {
    MainWindow::tabWidget = tabWidget;
}

QVBoxLayout *MainWindow::getPLayout() const {
    return pLayout;
}

void MainWindow::setPLayout(QVBoxLayout *pLayout) {
    MainWindow::pLayout = pLayout;
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

