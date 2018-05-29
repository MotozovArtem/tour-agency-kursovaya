//
// Created by rienel on 14.04.18.
//

#include "PlaceArrival.h"


PlaceArrival::PlaceArrival(int id, QString *name, QString *address, int idCity, int idPlaceArrivalType) :
        Model(id),
        placeArrivalName(name),
        address(address),
        idCity(idCity),
        idPlaceArrivalType(idPlaceArrivalType) {
    this->placeArrivalType = nullptr;
    this->city = nullptr;
}

PlaceArrival::PlaceArrival(QString *name, QString *address, int idCity, int idPlaceArrivalType) :
        placeArrivalName(name),
        address(address),
        idCity(idCity),
        idPlaceArrivalType(idPlaceArrivalType) {
    this->placeArrivalType = nullptr;
    this->city = nullptr;
}

PlaceArrival::PlaceArrival(int id) : Model(id) {
    this->placeArrivalType = nullptr;
    this->city = nullptr;
}

PlaceArrival::PlaceArrival() {
    this->placeArrivalType = nullptr;
    this->city = nullptr;
}

PlaceArrival::~PlaceArrival() {
    delete this->placeArrivalName;
    delete this->address;

    if (this->city != nullptr) {
        delete this->city;
        this->city = nullptr;
    }
    if (this->placeArrivalType != nullptr) {
        delete this->placeArrivalType;
        this->placeArrivalType = nullptr;
    }

}

QString *PlaceArrival::getName() const {
    return placeArrivalName;
}

void PlaceArrival::setName(QString *name) {
    PlaceArrival::placeArrivalName = name;
}

QString *PlaceArrival::getAddress() const {
    return address;
}

void PlaceArrival::setAddress(QString *address) {
    PlaceArrival::address = address;
}

int PlaceArrival::getIdCity() const {
    return idCity;
}

void PlaceArrival::setIdCity(int idCity) {
    PlaceArrival::idCity = idCity;
}

int PlaceArrival::getIdPlaceArrivalType() const {
    return idPlaceArrivalType;
}

void PlaceArrival::setIdPlaceArrivalType(int idPlaceArrivalType) {
    PlaceArrival::idPlaceArrivalType = idPlaceArrivalType;
}

PlaceArrival::PlaceArrival(int id, const QString &name, const QString &address, int idCity, int idPlaceArrivalType)
        : Model(id) {
    this->placeArrivalName = new QString(name);
    this->address = new QString(address);
    this->idCity = idCity;
    this->idPlaceArrivalType = idPlaceArrivalType;

    this->placeArrivalType = nullptr;
    this->city = nullptr;
}

PlaceArrival::PlaceArrival(const QString &name, const QString &address, int idCity, int idPlaceArrivalType) : Model() {
    this->placeArrivalName = new QString(name);
    this->address = new QString(address);
    this->idCity = idCity;
    this->idPlaceArrivalType = idPlaceArrivalType;

    this->placeArrivalType = nullptr;
    this->city = nullptr;
}

QString *PlaceArrival::getCity() const {
    return city;
}

void PlaceArrival::setCity(QString *city) {
    PlaceArrival::city = city;
}

QString *PlaceArrival::getPlaceArrivalType() const {
    return placeArrivalType;
}

void PlaceArrival::setPlaceArrivalType(QString *placeArrivalType) {
    PlaceArrival::placeArrivalType = placeArrivalType;
}

QStringList PlaceArrival::columnList = {"ID_i", "Name_s", "Address_s", "City_f", "Place arrival type_f"};

QStringList *PlaceArrival::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->placeArrivalName, *this->address, *this->city, *this->placeArrivalType});
}

QStringList *PlaceArrival::getValForAdd() {
    return new QStringList({QString::number(this->id), *this->placeArrivalName, *this->city, *this->placeArrivalType});
}

PlaceArrival::PlaceArrival(const QStringList &args) : Model(args) {
    this->placeArrivalName = new QString(args[1]);
    this->address = new QString(args[2]);
    this->idCity = args[3].toInt();
    this->idPlaceArrivalType = args[4].toInt();

    this->placeArrivalType = nullptr;
    this->city = nullptr;
}
