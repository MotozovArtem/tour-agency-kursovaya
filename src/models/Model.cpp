//
// Created by rienel on 02.03.18.
//

#include <iostream>
#include "Model.h"
#include <QDate>
#include <QtWidgets/QMessageBox>

int Model::getId() const {
    return this->id;
}

void Model::setId(int id) {
    this->id = id;
}

Model::Model() = default;

Model::Model(int id) {
    this->id = id;
}

Model::Model(QStringList args) {
    this->id=args[0].toInt();
}

QDate *Model::toDate(const QString dateString) {
//    QStringList dateSplited = dateString.split(QRegExp("[.-/]"));
//    QMessageBox(QMessageBox::Information, "MSG", dateSplited[0]).exec();
//    QMessageBox(QMessageBox::Information, "MSG", dateSplited[1]).exec();
//    QMessageBox(QMessageBox::Information, "MSG", dateSplited[2]).exec();
    QDate date = QDate::fromString(dateString, "dd.MM.yyyy");
    return new QDate(date.year(), date.month(), date.day());
}

QTime *Model::toTime(const QString timeString) {
//    QStringList timeSplited = timeString.split(QRegExp("[:.-]"));
    QTime time = QTime::fromString(timeString, "HH:mm");
    return new QTime(time.hour(), time.minute());
}

bool Model::toBool(const QString boolString) {
    QMessageBox(QMessageBox::Information, "MSG", boolString).exec();
    bool res = boolString == "+";
    return res;
}

Model::~Model() = default;