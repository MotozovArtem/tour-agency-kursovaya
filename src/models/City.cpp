//
// Created by rienel on 11.04.18.
//

#include "City.h"

City::City(int id, QString *name, int idCityType, int idCountry) : Model(id), cityName(name), idCityType(idCityType),
                                                                   idCountry(idCountry) {
    this->cityName = nullptr;
    this->cityTypeName = nullptr;
}

City::City(QString *name, int idCityType, int idCountry) : cityName(name), idCityType(idCityType),
                                                           idCountry(idCountry) {
    this->cityName = nullptr;
    this->cityTypeName = nullptr;
}

City::City(int id) : Model(id) {
    this->cityName = nullptr;
    this->cityTypeName = nullptr;
}

City::City() {
    this->cityName = nullptr;
    this->cityTypeName = nullptr;
}

City::~City() {
    delete this->cityName;
    if (this->countryName != nullptr) {
        delete this->countryName;
        this->countryName = nullptr;
    }
    if (this->cityTypeName != nullptr) {
        delete this->cityTypeName;
        this->cityTypeName = nullptr;
    }
}

QString *City::getName() const {
    return cityName;
}

void City::setName(QString *name) {
    City::cityName = name;
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
    this->cityName = new QString(name);
    this->idCityType = idCityType;
    this->idCountry = idCountry;
}

City::City(const QString &name, int idCityType, int idCountry) : Model() {
    this->cityName = new QString(name);
    this->idCityType = idCityType;
    this->idCountry = idCountry;
}

QString *City::getCityTypeName() const {
    return cityTypeName;
}

void City::setCityTypeName(QString *cityTypeName) {
    City::cityTypeName = cityTypeName;
}

QString *City::getCountryName() const {
    return countryName;
}

void City::setCountryName(QString *countryName) {
    City::countryName = countryName;
}

QStringList City::columnList = {"ID", "Name", "id City Type", "id Country"};

QStringList *City::getValueList() {
    return new QStringList({QString::number(this->id), *this->cityName, *this->cityTypeName, *this->countryName});
}
