//
// Created by rienel on 14.04.18.
//

#include "PlaceArrival.h"


PlaceArrival::PlaceArrival(int id, QString *name, QString *address, int idCity, int idPlaceArrivalType) : Model(id),
                                                                                                          placeArrivalName(name),
                                                                                                          address(address),
                                                                                                          idCity(idCity),
                                                                                                          idPlaceArrivalType(
                                                                                                                  idPlaceArrivalType) {}

PlaceArrival::PlaceArrival(QString *name, QString *address, int idCity, int idPlaceArrivalType) : placeArrivalName(name),
                                                                                                  address(address),
                                                                                                  idCity(idCity),
                                                                                                  idPlaceArrivalType(
                                                                                                          idPlaceArrivalType) {}

PlaceArrival::PlaceArrival(int id) : Model(id) {}

PlaceArrival::PlaceArrival() {}

PlaceArrival::~PlaceArrival() {
    delete this->placeArrivalName;
    delete this->address;
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
}

PlaceArrival::PlaceArrival(const QString &name, const QString &address, int idCity, int idPlaceArrivalType) : Model() {
    this->placeArrivalName = new QString(name);
    this->address = new QString(address);
    this->idCity = idCity;
    this->idPlaceArrivalType = idPlaceArrivalType;
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

QStringList PlaceArrival::columnList = {"ID", "Name", "Address", "City_f", "Place arrival type_f"};

QStringList *PlaceArrival::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->placeArrivalName, *this->address, *this->city, *this->placeArrivalType});
}
