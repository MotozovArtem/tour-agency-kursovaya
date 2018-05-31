//
// Created by rienel on 04.05.18.
//

#ifndef PSQLWORK_MAINWINDOW_H
#define PSQLWORK_MAINWINDOW_H

#include <QtCore>
#include <QtWidgets/QtWidgets>
#include <models/interfaces/ModelDAO.h>
#include <iostream>

#include "utils/Tables.h"
#include "RightMenuWidget.h"
#include "EditWindow.h"

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

    RightMenuWidget *getRightMenu() const;

    void setRightMenu(RightMenuWidget *rightMenu);

    void initRightMenu();

    void initToolBar();

    void getValuesFromDialog(AddWindow *window);

    void getValuesForEdit(EditWindow *window, int idRow);

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

        this->pTable->setSelectionMode(QAbstractItemView::SingleSelection);
        this->pTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        this->pTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    };

    template<class modelClass>
    modelClass *_getValuesFromDialog(AddWindow *window) {
        QList<QWidget *> editList = window->getEditList();
        QStringList valuesFromEditLines;
        valuesFromEditLines << QString::number(0);
                foreach(QWidget *lineEdit, editList) {
                QString typeName(lineEdit->metaObject()->className());
                if (typeName == "QLineEdit") {
                    valuesFromEditLines << dynamic_cast<QLineEdit *>(lineEdit)->text();
                } else if (typeName == "QComboBox") {
                    valuesFromEditLines << QString(dynamic_cast<QComboBox *>(lineEdit)->currentText().split(" ")[0]);
                } else if (typeName == "QDateEdit") {
                    valuesFromEditLines << dynamic_cast<QDateEdit *>(lineEdit)->date().toString("dd.MM.yyyy");
                } else if (typeName == "QTimeEdit") {
                    valuesFromEditLines << dynamic_cast<QTimeEdit *>(lineEdit)->time().toString("HH:mm");
                } else if (typeName == "QSpinBox") {
                    valuesFromEditLines << QString::number(dynamic_cast<QSpinBox *>(lineEdit)->value());
                } else if (typeName == "QCheckBox") {
                    valuesFromEditLines << (dynamic_cast<QCheckBox *>(lineEdit)->isChecked() ? "+" : "-");
                } else if (typeName == "QDoubleSpinBox") {
                    valuesFromEditLines << QString::number(dynamic_cast<QDoubleSpinBox *>(lineEdit)->value());
                }
            }
        modelClass *model = new modelClass(valuesFromEditLines);
        return model;
    }

    template<class modelClass, class modelDaoClass>
    void _addInDataBase(modelClass *model) {
        modelDaoClass().add(model);
    }

    template<class modelClass, class modelDaoClass>
    void _deleteFromDataBase(int id) {
        auto *obj = new modelClass(id);
        modelDaoClass().del(obj);
        delete obj;
    };

    template<class modelClass, class modelDaoClass>
    void _editInDataBase(modelClass *model) {
        modelDaoClass().update(model);
    };


public slots:

    void renderTable(Tables tables);

    void addRow();

    void editRow();

    void deleteRow();

};


#endif //PSQLWORK_MAINWINDOW_H
