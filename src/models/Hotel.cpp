//
// Created by rienel on 08.04.18.
//

#include "Hotel.h"

Hotel::Hotel(int id, QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, QString *city) : Model(
        id), hotelName(hotelName), address(address), stars(stars), yearOfFoundation(yearOfFoundation), city(city) {}

Hotel::Hotel(QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, QString *city) : hotelName(
        hotelName), address(address), stars(stars), yearOfFoundation(yearOfFoundation), city(city) {}

Hotel::Hotel(int id) : Model(id) {}

Hotel::Hotel() {}

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

QString *Hotel::getCity() const {
    return city;
}

void Hotel::setCity(QString *city) {
    Hotel::city = city;
}

Hotel::~Hotel() {
    delete this->hotelName;
    delete this->address;
    delete this->city;
    delete this->yearOfFoundation;
}
