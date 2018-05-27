//
// Created by rienel on 14.04.18.
//

#include "PlaceArrivalType.h"

PlaceArrivalType::PlaceArrivalType(int id, QString *name) : Model(id), placeArrivalTypeName(name) {}

PlaceArrivalType::PlaceArrivalType(QString *name) : placeArrivalTypeName(name) {}

PlaceArrivalType::PlaceArrivalType(int id) : Model(id) {}

PlaceArrivalType::PlaceArrivalType() {}

PlaceArrivalType::~PlaceArrivalType() {
    delete this->placeArrivalTypeName;
}

QString *PlaceArrivalType::getName() const {
    return placeArrivalTypeName;
}

void PlaceArrivalType::setName(QString *name) {
    PlaceArrivalType::placeArrivalTypeName = name;
}

PlaceArrivalType::PlaceArrivalType(int id, const QString &name) : Model(id) {
    this->placeArrivalTypeName = new QString(name);
}

PlaceArrivalType::PlaceArrivalType(const QString &name) {
    this->placeArrivalTypeName = new QString(name);
}

QStringList PlaceArrivalType::columnList = {"ID", "Name"};

QStringList *PlaceArrivalType::getValueList() {
    return new QStringList({QString::number(this->id), *this->placeArrivalTypeName});
}
