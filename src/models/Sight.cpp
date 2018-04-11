//
// Created by rienel on 11.04.18.
//

#include "Sight.h"

Sight::Sight(int id, QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity) : Model(id),
                                                                                                             name(name),
                                                                                                             address(address),
                                                                                                             yearOfCreation(
                                                                                                                     yearOfCreation),
                                                                                                             toponym(toponym),
                                                                                                             idCity(idCity) {}

Sight::Sight(QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity) : name(name),
                                                                                                     address(address),
                                                                                                     yearOfCreation(
                                                                                                             yearOfCreation),
                                                                                                     toponym(toponym),
                                                                                                     idCity(idCity) {}

Sight::Sight(int id) : Model(id) {}

Sight::Sight() {}

Sight::~Sight() {
    delete this->name;
    delete this->address;
    delete this->toponym;
    delete this->yearOfCreation;
}

QString *Sight::getName() const {
    return name;
}

void Sight::setName(QString *name) {
    Sight::name = name;
}

QString *Sight::getAddress() const {
    return address;
}

void Sight::setAddress(QString *address) {
    Sight::address = address;
}

QDate *Sight::getYearOfCreation() const {
    return yearOfCreation;
}

void Sight::setYearOfCreation(QDate *yearOfCreation) {
    Sight::yearOfCreation = yearOfCreation;
}

QString *Sight::getToponym() const {
    return toponym;
}

void Sight::setToponym(QString *toponym) {
    Sight::toponym = toponym;
}

int Sight::getIdCity() const {
    return idCity;
}

void Sight::setIdCity(int idCity) {
    Sight::idCity = idCity;
}
