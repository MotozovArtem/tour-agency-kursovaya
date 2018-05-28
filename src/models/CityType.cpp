//
// Created by rienel on 11.04.18.
//

#include "CityType.h"

CityType::CityType(int id, QString *name) : Model(id), cityTypeName(name) {}

CityType::CityType(QString *name) : cityTypeName(name) {}

CityType::CityType(int id) : Model(id) {}

CityType::CityType() {}

CityType::~CityType() {
    delete this->cityTypeName;
}

QString *CityType::getName() const {
    return cityTypeName;
}

void CityType::setName(QString *name) {
    CityType::cityTypeName = name;
}

CityType::CityType(int id, const QString &name) : Model(id) {
    this->cityTypeName = new QString(name);
}

CityType::CityType(const QString &name) : Model() {
    this->cityTypeName = new QString(name);
}

QStringList CityType::columnList = {"ID_i", "Name_s"};

QStringList *CityType::getValueList() {
    return new QStringList({QString::number(this->id), *this->cityTypeName});
}
