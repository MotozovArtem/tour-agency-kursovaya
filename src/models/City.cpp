//
// Created by rienel on 11.04.18.
//

#include "City.h"

City::City(QString *name, float price, int idCityType, int idCountry) : name(name), price(price),
                                                                        idCityType(idCityType), idCountry(idCountry) {}

City::City(int id, QString *name, float price, int idCityType, int idCountry) : Model(id), name(name), price(price),
                                                                                idCityType(idCityType),
                                                                                idCountry(idCountry) {}

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

float City::getPrice() const {
    return price;
}

void City::setPrice(float price) {
    City::price = price;
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
