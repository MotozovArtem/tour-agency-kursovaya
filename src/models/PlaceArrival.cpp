//
// Created by rienel on 14.04.18.
//

#include "PlaceArrival.h"


PlaceArrival::PlaceArrival(int id, QString *name, QString *address, int idCity, int idPlaceArrivalType) : Model(id),
                                                                                                          name(name),
                                                                                                          address(address),
                                                                                                          idCity(idCity),
                                                                                                          idPlaceArrivalType(
                                                                                                                  idPlaceArrivalType) {}

PlaceArrival::PlaceArrival(QString *name, QString *address, int idCity, int idPlaceArrivalType) : name(name),
                                                                                                  address(address),
                                                                                                  idCity(idCity),
                                                                                                  idPlaceArrivalType(
                                                                                                          idPlaceArrivalType) {}

PlaceArrival::PlaceArrival(int id) : Model(id) {}

PlaceArrival::PlaceArrival() {}

PlaceArrival::~PlaceArrival() {
    delete this->name;
    delete this->address;
}

QString *PlaceArrival::getName() const {
    return name;
}

void PlaceArrival::setName(QString *name) {
    PlaceArrival::name = name;
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
    this->name = new QString(name);
    this->address = new QString(address);
    this->idCity = idCity;
    this->idPlaceArrivalType = idPlaceArrivalType;
}
