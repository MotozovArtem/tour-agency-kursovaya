//
// Created by rienel on 11.04.18.
//

#include "City.h"

City::City(int id, QString *name, float price, int idCity, int idCityType) : Model(id), name(name), price(price),
                                                                             idCity(idCity), idCityType(idCityType) {}

City::City(QString *name, float price, int idCity, int idCityType) : name(name), price(price), idCity(idCity),
                                                                     idCityType(idCityType) {}

City::City(int id) : Model(id) {}

City::City(QString *name) : name(name) {}

City::~City() {
    delete this->name;
}

QString *City::getName() const {
    return name;
}

void City::setName(QString *name) {
    City::name = name;
}

float City::getPrice() const {
    return price;
}

void City::setPrice(float price) {
    City::price = price;
}

int City::getIdCity() const {
    return idCity;
}

void City::setIdCity(int idCity) {
    City::idCity = idCity;
}

int City::getIdCityType() const {
    return idCityType;
}

void City::setIdCityType(int idCityType) {
    City::idCityType = idCityType;
}
