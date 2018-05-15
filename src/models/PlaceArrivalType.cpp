//
// Created by rienel on 14.04.18.
//

#include "PlaceArrivalType.h"

PlaceArrivalType::PlaceArrivalType(int id, QString *name) : Model(id), name(name) {}

PlaceArrivalType::PlaceArrivalType(QString *name) : name(name) {}

PlaceArrivalType::PlaceArrivalType(int id) : Model(id) {}

PlaceArrivalType::PlaceArrivalType() {}

PlaceArrivalType::~PlaceArrivalType() {
    delete this->name;
}

QString *PlaceArrivalType::getName() const {
    return name;
}

void PlaceArrivalType::setName(QString *name) {
    PlaceArrivalType::name = name;
}

PlaceArrivalType::PlaceArrivalType(int id, const QString &name) : Model(id) {
    this->name = new QString(name);
}

PlaceArrivalType::PlaceArrivalType(const QString &name) {
    this->name = new QString(name);
}
