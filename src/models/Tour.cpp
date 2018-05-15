//
// Created by rienel on 11.04.18.
//

#include "Tour.h"

Tour::Tour(int id, QString *name, int days, int idCity, int idTourType) : Model(id), name(name), days(days),
                                                                          idCity(idCity), idTourType(idTourType) {}

Tour::Tour(QString *name, int days, int idCity, int idTourType) : name(name), days(days), idCity(idCity),
                                                                  idTourType(idTourType) {}

Tour::Tour(int id) : Model(id) {}

Tour::Tour() {}

Tour::~Tour() {
    delete this->name;
}

QString *Tour::getName() const {
    return name;
}

void Tour::setName(QString *name) {
    Tour::name = name;
}

int Tour::getDays() const {
    return days;
}

void Tour::setDays(int days) {
    Tour::days = days;
}

int Tour::getIdCity() const {
    return idCity;
}

void Tour::setIdCity(int idCity) {
    Tour::idCity = idCity;
}

int Tour::getIdTourType() const {
    return idTourType;
}

void Tour::setIdTourType(int idTourType) {
    Tour::idTourType = idTourType;
}

Tour::Tour(int id, const QString &name, int days, int idCity, int idTourType) : Model(id) {
    this->name = new QString(name);
    this->days = days;
    this->idCity = idCity;
    this->idTourType = idTourType;
}

Tour::Tour(const QString &name, int days, int idCity, int idTourType): Model() {
    this->name = new QString(name);
    this->days = days;
    this->idCity = idCity;
    this->idTourType = idTourType;
}


