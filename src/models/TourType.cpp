//
// Created by rienel on 11.04.18.
//

#include "TourType.h"

TourType::TourType(int id, QString *name) : Model(id), tourTypeName(name) {}

TourType::TourType(int id) : Model(id) {}

TourType::TourType(QString *name) : tourTypeName(name) {}

TourType::TourType() {}

TourType::~TourType() {
    delete this->tourTypeName;
}

QString *TourType::getName() const {
    return tourTypeName;
}

void TourType::setName(QString *name) {
    TourType::tourTypeName = name;
}

TourType::TourType(int id, const QString &name) : Model(id) {
    this->tourTypeName = new QString(name);
}

TourType::TourType(const QString &name) : Model() {
    this->tourTypeName = new QString(name);
}

QStringList TourType::columnList = {"ID", "Name"};

QStringList *TourType::getValueList() {
    return new QStringList({QString::number(this->id), *this->tourTypeName});
}
