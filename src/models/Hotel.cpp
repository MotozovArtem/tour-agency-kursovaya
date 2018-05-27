//
// Created by rienel on 08.04.18.
//

#include "Hotel.h"

Hotel::Hotel(int id, QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, int idCity) : Model(
        id), hotelName(hotelName), address(address), stars(stars), yearOfFoundation(yearOfFoundation), idCity(idCity) {
    this->cityName = nullptr;
}

Hotel::Hotel(QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, int idCity) : hotelName(
        hotelName), address(address), stars(stars), yearOfFoundation(yearOfFoundation), idCity(idCity) {
    this->cityName = nullptr;

}

Hotel::Hotel(int id) : Model(id) {
    this->cityName = nullptr;
}

Hotel::Hotel() {
    this->cityName = nullptr;
}

QString *Hotel::getHotelName() const {
    return hotelName;
}

void Hotel::setHotelName(QString *hotelName) {
    Hotel::hotelName = hotelName;
}

QString *Hotel::getAddress() const {
    return address;
}

void Hotel::setAddress(QString *address) {
    Hotel::address = address;
}

int Hotel::getStars() const {
    return stars;
}

void Hotel::setStars(int stars) {
    Hotel::stars = stars;
}

QDate *Hotel::getYearOfFoundation() const {
    return yearOfFoundation;
}

void Hotel::setYearOfFoundation(QDate *yearOfFoundation) {
    Hotel::yearOfFoundation = yearOfFoundation;
}


Hotel::~Hotel() {
    delete this->hotelName;
    delete this->address;
    delete this->yearOfFoundation;
    if (this->cityName != nullptr) {
        delete this->cityName;
        this->cityName = nullptr;
    }
}

int Hotel::getIdCity() const {
    return idCity;
}

void Hotel::setIdCity(int idCity) {
    Hotel::idCity = idCity;
}

Hotel::Hotel(int id, const QString &hotelName, const QString &address, int stars, const QDate &yearOfFoundation,
             int idCity) : Model(id) {
    this->hotelName = new QString(hotelName);
    this->address = new QString(address);
    this->yearOfFoundation = new QDate(yearOfFoundation);
    this->stars = stars;
    this->idCity = idCity;

    this->cityName = nullptr;
}

Hotel::Hotel(const QString &hotelName, const QString &address, int stars, const QDate &yearOfFoundation, int idCity)
        : Model() {
    this->hotelName = new QString(hotelName);
    this->address = new QString(address);
    this->yearOfFoundation = new QDate(yearOfFoundation);
    this->stars = stars;
    this->idCity = idCity;

    this->cityName = nullptr;
}

QStringList Hotel::columnList = {"ID", "Hotel Name", "Address", "Year of Foundation", "Stars", "City"};


QStringList *Hotel::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->hotelName, *this->address, this->yearOfFoundation->toString(),
             QString::number(this->stars), *this->cityName});
}

QString *Hotel::getCityName() const {
    return cityName;
}

void Hotel::setCityName(QString *cityName) {
    Hotel::cityName = cityName;
}
