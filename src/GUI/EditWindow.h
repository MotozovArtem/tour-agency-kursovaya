//
// Created by rienel on 29.05.18.
//

#ifndef PSQLWORK_EDITWINDOW_H
#define PSQLWORK_EDITWINDOW_H

#include "AddWindow.h"
#include <QMessageBox>
#include <QString>

class EditWindow : public AddWindow {
    Q_OBJECT
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
                auto *editField = dynamic_cast<QComboBox *>(editWidget);
                int index;
                if ((index = editField->findText(valuesFromModel->value(i), Qt::MatchContains))!=-1){
                    editField->setCurrentIndex(index);
                }
            } else if (typeName == "QDateEdit") {
                dynamic_cast<QDateEdit *>(editWidget)->setDate(QDate::fromString(valuesFromModel->value(i), "dd.MM.yyyy"));
            } else if (typeName == "QTimeEdit") {
                dynamic_cast<QDateEdit *>(editWidget)->setTime(QTime::fromString(valuesFromModel->value(i), "HH:mm"));
            } else if (typeName == "QSpinBox") {
                dynamic_cast<QSpinBox *>(editWidget)->setValue(valuesFromModel->value(i).toInt());
            } else if (typeName == "QCheckBox") {
                dynamic_cast<QCheckBox *>(editWidget)->setChecked((valuesFromModel->value(i)=="+"));
            }else if (typeName == "QDoubleSpinBox") {
                dynamic_cast<QDoubleSpinBox *>(editWidget)->setValue(valuesFromModel->value(i).toDouble());
            }
        }
    };

    void fillEditFields();
};


#endif //PSQLWORK_EDITWINDOW_H
