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

Hotel::~Hotel() {
    if(this->hotelName!=nullptr){
        delete this->hotelName;
        this->hotelName=nullptr;
    }
    if(this->address!=nullptr){
        delete this->address;
        this->address=nullptr;
    }
    if(this->yearOfFoundation!=nullptr){
        delete this->yearOfFoundation;
        this->yearOfFoundation=nullptr;
    }


    if (this->cityName != nullptr) {
        delete this->cityName;
        this->cityName = nullptr;
    }
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

QStringList Hotel::columnList = {"ID_i", "Hotel Name_s", "Address_s", "Year of Foundation_d", "Stars_i", "City_f"};


QStringList *Hotel::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->hotelName, *this->address, this->yearOfFoundation->toString("dd.MM.yyyy"),
             QString::number(this->stars), *this->cityName});
}

QString *Hotel::getCityName() const {
    return cityName;
}

void Hotel::setCityName(QString *cityName) {
    Hotel::cityName = cityName;
}

QStringList *Hotel::getValForAdd() {
    return new QStringList(
            {QString::number(this->id), *this->hotelName});
}

Hotel::Hotel(const QStringList &args) : Model(args) {
    this->hotelName = new QString(args[1]);
    this->address = new QString(args[2]);
    this->stars = args[3].toInt();
    this->yearOfFoundation = toDate(args[4]);
    this->idCity = args[5].toInt();

    this->cityName = nullptr;
}
