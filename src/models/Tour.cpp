//
// Created by rienel on 11.04.18.
//

#include "Tour.h"

Tour::Tour(int id, QString *name, int days, int idCity, int idTourType) :
        Model(id), tourName(name), days(days),
        idCity(idCity), idTourType(idTourType) {
    this->city = nullptr;
    this->tourType = nullptr;
}

Tour::Tour(QString *name, int days, int idCity, int idTourType) :
        tourName(name), days(days), idCity(idCity),
        idTourType(idTourType) {
    this->city = nullptr;
    this->tourType = nullptr;
}

Tour::Tour(int id) : Model(id) {
    this->city = nullptr;
    this->tourType = nullptr;
}

Tour::Tour() {
    this->city = nullptr;
    this->tourType = nullptr;
}

Tour::Tour(int id, const QString &name, int days, int idCity, int idTourType) : Model(id) {
    this->tourName = new QString(name);
    this->days = days;
    this->idCity = idCity;
    this->idTourType = idTourType;

    this->city = nullptr;
    this->tourType = nullptr;
}

Tour::Tour(const QString &name, int days, int idCity, int idTourType) : Model() {
    this->tourName = new QString(name);
    this->days = days;
    this->idCity = idCity;
    this->idTourType = idTourType;

    this->city = nullptr;
    this->tourType = nullptr;
}

Tour::~Tour() {
    delete this->tourName;

    if(this->city!=nullptr){
        delete this->city;
        this->city=nullptr;
    }
    if(this->tourType!=nullptr){
        delete this->tourType;
        this->tourType=nullptr;
    }
}

QString *Tour::getName() const {
    return tourName;
}

void Tour::setName(QString *name) {
    Tour::tourName = name;
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

QString *Tour::getCity() const {
    return city;
}

void Tour::setCity(QString *city) {
    Tour::city = city;
}

QString *Tour::getTourType() const {
    return tourType;
}

void Tour::setTourType(QString *tourType) {
    Tour::tourType = tourType;
}

QStringList Tour::columnList = {"ID", "Name", "Days", "City_f", "Tour Type_f"};

QStringList *Tour::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->tourName, QString::number(this->days), *this->city, *this->tourType});
}
