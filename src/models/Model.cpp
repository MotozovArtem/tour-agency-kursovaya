//
// Created by rienel on 02.03.18.
//

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
    QDate date = QDate::fromString(dateString, "dd.MM.yyyy");
    return new QDate(date.year(), date.month(), date.day());
}

QTime *Model::toTime(const QString timeString) {
    QTime time = QTime::fromString(timeString, "HH:mm");
    return new QTime(time.hour(), time.minute());
}

bool Model::toBool(const QString boolString) {
    return boolString == "+";
}

Model::~Model() = default;