//
// Created by rienel on 11.04.18.
//

#include "CityType.h"

CityType::CityType(int id, QString *name) : Model(id), name(name) {}

CityType::CityType(QString *name) : name(name) {}

CityType::CityType(int id) : Model(id) {}

CityType::CityType() {}

CityType::~CityType() {
    delete this->name;
}

QString *CityType::getName() const {
    return name;
}

void CityType::setName(QString *name) {
    CityType::name = name;
}
