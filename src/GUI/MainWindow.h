//
// Created by rienel on 04.05.18.
//

#ifndef PSQLWORK_MAINWINDOW_H
#define PSQLWORK_MAINWINDOW_H

#include <QtCore>
#include <QtWidgets/QtWidgets>
#include <models/interfaces/ModelDAO.h>

#include "utils/Tables.h"
#include "RightMenuWidget.h"

class MainWindow : public QMainWindow {
Q_OBJECT
private:
    QList<QAction *> actionList;

    QTableWidget *pTable;
    RightMenuWidget *rightMenu;
    QMenuBar *menu;
    QToolBar *toolBar;

    QWidget *mainWidget;
    QGridLayout *mainLayout;
public:

    Tables currentTable;

    MainWindow(QMainWindow *pwgt = 0);

    virtual ~MainWindow();

    QTableWidget *getPTable() const;

    void setPTable(QTableWidget *pTable);

//    QPushButton *getPButton() const;
//
//    void setPButton(QPushButton *pButton);

    RightMenuWidget *getRightMenu() const;

    void setRightMenu(RightMenuWidget *rightMenu);

    void initRightMenu();

    void initToolBar();

    template<class modelClass, class daoClass>
    void _renderTable() {
        QList<modelClass *> objectList = daoClass().getAllFilled();
        this->pTable->setRowCount(objectList.size());
        this->pTable->setColumnCount(modelClass::columnList.length());

        this->pTable->setHorizontalHeaderLabels(modelClass::columnList);

        int i = 0;
                foreach(modelClass *model, objectList) {
                int j = 0;
                QStringListIterator iterator(*model->getValueList());
                while (iterator.hasNext()) {
                    this->pTable->setItem(i, j, new QTableWidgetItem(iterator.next()));
                    j++;
                }
                i++;
            }

        this->pTable->resizeColumnsToContents();
        this->pTable->resizeRowsToContents();
    };

public slots:

    void renderTable(Tables tables);

    void addRow();

    void editRow();

    void deleteRow();

};


#endif //PSQLWORK_MAINWINDOW_H
