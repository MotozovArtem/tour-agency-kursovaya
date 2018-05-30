//
// Created by rienel on 11.04.18.
//

#include "Sight.h"

Sight::Sight(int id, QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity) :
        Model(id),
        sightName(name),
        address(address),
        yearOfCreation(yearOfCreation),
        toponym(toponym),
        idCity(idCity) { this->city = nullptr; }

Sight::Sight(QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity) :
        sightName(name),
        address(address),
        yearOfCreation(yearOfCreation),
        toponym(toponym),
        idCity(idCity) { this->city = nullptr; }

Sight::Sight(int id) : Model(id) { this->city = nullptr; }

Sight::Sight() { this->city = nullptr; }

Sight::~Sight() {
    if(this->sightName!=nullptr){
        delete this->sightName;
        this->sightName=nullptr;
    }
    if(this->address!=nullptr){
        delete this->address;
        this->address=nullptr;
    }
    if(this->toponym!=nullptr){
        delete this->toponym;
        this->toponym=nullptr;
    }
    if(this->yearOfCreation!=nullptr){
        delete this->yearOfCreation;
        this->yearOfCreation=nullptr;
    }

    if (this->city != nullptr) {
        delete this->city;
        this->city = nullptr;
    }
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

    this->city = nullptr;
}

Sight::Sight(const QString &name, const QString &address, const QDate &yearOfCreation, const QString &toponym,
             int idCity) : Model() {
    this->sightName = new QString(name);
    this->address = new QString(address);
    this->yearOfCreation = new QDate(yearOfCreation);
    this->toponym = new QString(toponym);

    this->city = nullptr;
}

QString *Sight::getCity() const {
    return city;
}

void Sight::setCity(QString *city) {
    Sight::city = city;
}

QStringList Sight::columnList = {"ID_i", "Name_s", "Address_s", "Year of creation_d", "Toponym_s", "City_f"};

QStringList *Sight::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->sightName, *this->address, this->yearOfCreation->toString(),
             *this->toponym,
             *this->city});
}

QStringList *Sight::getValForAdd() {
    return new QStringList(
            {QString::number(this->id), *this->sightName, *this->city});
}

Sight::Sight(const QStringList &args) : Model(args) {
    this->sightName = new QString(args[1]);
    this->address = new QString(args[2]);
    this->yearOfCreation = toDate(args[3]);
    this->toponym = new QString(args[4]);
    this->idCity = args[5].toInt();

    this->city = nullptr;
}
