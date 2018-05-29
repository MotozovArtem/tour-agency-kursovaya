//
// Created by rienel on 02.03.18.
//

#include <iostream>
#include "Model.h"
#include <QDate>

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
    QStringList dateSplited = dateString.split(QRegExp("[.-/]"));
    return new QDate(dateSplited[0].toInt(), dateSplited[1].toInt(), dateSplited[2].toInt());
}

QTime *Model::toTime(const QString timeString) {
    QStringList timeSplited = timeString.split(QRegExp("[:.-]"));
    return new QTime(timeSplited[0].toInt(), timeSplited[1].toInt());
}

Model::~Model() = default;