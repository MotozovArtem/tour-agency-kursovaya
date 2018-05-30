//
// Created by rienel on 29.05.18.
//

#ifndef PSQLWORK_EDITWINDOW_H
#define PSQLWORK_EDITWINDOW_H

#include "AddWindow.h"
#include <QMessageBox>
#include <QString>

class EditWindow : public AddWindow {
protected:
    int id;
public:
    EditWindow(QWidget *parent, const Qt::WindowFlags &f, Tables table, int id);

    template<class modelClass, class modelDaoClass>
    void _fillEditFields() {
        modelClass *objOfModel = modelDaoClass().getById(this->id);
        QStringList *valuesFromModel = objOfModel->getValueList();
        QStringList columnList = modelClass::columnList;
        for (int i = 1; i < valuesFromModel->length(); i++) {
            QWidget *editWidget = this->editList[i-1];
            QString typeName = editWidget->metaObject()->className();
            if (typeName == "QLineEdit") {
                dynamic_cast<QLineEdit *>(editWidget)->setText(valuesFromModel->value(i));
            } else if (typeName == "QComboBox") {
//                dynamic_cast<QComboBox *>(editWidget)->setCurrentText();
            } else if (typeName == "QDateEdit") {
                dynamic_cast<QDateEdit *>(editWidget)->setDate(*objOfModel->toDate(valuesFromModel->value(i)));
            } else if (typeName == "QTimeEdit") {
                dynamic_cast<QDateEdit *>(editWidget)->setTime(*objOfModel->toTime(valuesFromModel->value(i)));
            } else if (typeName == "QSpinBox") {
                dynamic_cast<QSpinBox *>(editWidget)->setValue(valuesFromModel->value(i).toInt());
            } else if (typeName == "QCheckBox") {
                dynamic_cast<QCheckBox *>(editWidget)->setChecked(false);
            }
        }
    };

    void fillEditFields();
};


#endif //PSQLWORK_EDITWINDOW_H
