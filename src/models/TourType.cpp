//
// Created by rienel on 11.04.18.
//

#include "TourType.h"

TourType::TourType(int id, QString *name) : Model(id), name(name) {}

TourType::TourType(int id) : Model(id) {}

TourType::TourType(QString *name) : name(name) {}

TourType::TourType() {}

TourType::~TourType() {
    delete this->name;
}

QString *TourType::getName() const {
    return name;
}

void TourType::setName(QString *name) {
    TourType::name = name;
}
