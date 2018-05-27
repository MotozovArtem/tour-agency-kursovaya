//
// Created by rienel on 11.04.18.
//

#include "Sight.h"

Sight::Sight(int id, QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity) : Model(id),
                                                                                                             sightName(name),
                                                                                                             address(address),
                                                                                                             yearOfCreation(
                                                                                                                     yearOfCreation),
                                                                                                             toponym(toponym),
                                                                                                             idCity(idCity) {}

Sight::Sight(QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity) : sightName(name),
                                                                                                     address(address),
                                                                                                     yearOfCreation(
                                                                                                             yearOfCreation),
                                                                                                     toponym(toponym),
                                                                                                     idCity(idCity) {}

Sight::Sight(int id) : Model(id) {}

Sight::Sight() {}

Sight::~Sight() {
    delete this->sightName;
    delete this->address;
    delete this->toponym;
    delete this->yearOfCreation;
}

QString *Sight::getName() const {
    return sightName;
}

void Sight::setName(QString *name) {
    Sight::sightName = name;
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

Sight::Sight(int id, const QString &name, const QString &address, const QDate &yearOfCreation, const QString &toponym,
             int idCity) : Model(id) {
    this->sightName = new QString(name);
    this->address = new QString(address);
    this->yearOfCreation = new QDate(yearOfCreation);
    this->toponym = new QString(toponym);
}

Sight::Sight(const QString &name, const QString &address, const QDate &yearOfCreation, const QString &toponym,
             int idCity) : Model() {
    this->sightName = new QString(name);
    this->address = new QString(address);
    this->yearOfCreation = new QDate(yearOfCreation);
    this->toponym = new QString(toponym);
}

QString *Sight::getCity() const {
    return city;
}

void Sight::setCity(QString *city) {
    Sight::city = city;
}

QStringList Sight::columnList = {"ID", "Name", "Address", "Year of creation", "Toponym", "City_f"};

QStringList *Sight::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->sightName, *this->address, this->yearOfCreation->toString(), *this->toponym,
             *this->city});
}
