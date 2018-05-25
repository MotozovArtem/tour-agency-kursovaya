//
// Created by rienel on 11.04.18.
//

#include "City.h"

City::City(int id, QString *name, int idCityType, int idCountry) : Model(id), name(name), idCityType(idCityType),
                                                                   idCountry(idCountry) {}

City::City(QString *name, int idCityType, int idCountry) : name(name), idCityType(idCityType), idCountry(idCountry) {}

City::City(int id) : Model(id) {}

City::City() {}

City::~City() {
    delete this->name;
}

QString *City::getName() const {
    return name;
}

void City::setName(QString *name) {
    City::name = name;
}

int City::getIdCityType() const {
    return idCityType;
}

void City::setIdCityType(int idCityType) {
    City::idCityType = idCityType;
}

int City::getIdCountry() const {
    return idCountry;
}

void City::setIdCountry(int idCountry) {
    City::idCountry = idCountry;
}

City::City(int id, const QString &name, int idCityType, int idCountry) : Model(id) {
    this->name = new QString(name);
    this->idCityType = idCityType;
    this->idCountry = idCountry;
}

City::City(const QString &name, int idCityType, int idCountry) : Model() {
    this->name = new QString(name);
    this->idCityType = idCityType;
    this->idCountry = idCountry;
}

QStringList City::columnList = {"ID", "Name", "id City Type", "id Country"};
