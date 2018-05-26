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

CityType::CityType(int id, const QString &name) : Model(id) {
    this->name = new QString(name);
}

CityType::CityType(const QString &name) : Model() {
    this->name = new QString(name);
}

QStringList CityType::columnList = {"ID", "Name"};

QStringList *CityType::getValueList() {
    return new QStringList({QString::number(this->id), *this->name});
}
