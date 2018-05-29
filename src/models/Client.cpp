//
// Created by rienel on 14.04.18.
//

#include "Client.h"

Client::Client(int id, QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
               QString *placeOfBirth, bool sex) : Model(id), passportData(passportData), surname(surname),
                                                  clientName(name),
                                                  patronymic(patronymic), dateOfBirth(dateOfBirth),
                                                  placeOfBirth(placeOfBirth), sex(sex) {}

Client::Client(QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
               QString *placeOfBirth, bool sex) : passportData(passportData), surname(surname), clientName(name),
                                                  patronymic(patronymic), dateOfBirth(dateOfBirth),
                                                  placeOfBirth(placeOfBirth), sex(sex) {}

Client::Client(int id) : Model(id) {}

Client::Client() {}

Client::~Client() {
    delete this->surname;
    delete this->clientName;
    delete this->patronymic;
    delete this->dateOfBirth;
    delete this->placeOfBirth;
    delete this->passportData;
}

QString *Client::getPassportData() const {
    return passportData;
}

void Client::setPassportData(QString *passportData) {
    Client::passportData = passportData;
}

QString *Client::getSurname() const {
    return surname;
}

void Client::setSurname(QString *surname) {
    Client::surname = surname;
}

QString *Client::getName() const {
    return clientName;
}

void Client::setName(QString *name) {
    Client::clientName = name;
}

QString *Client::getPatronymic() const {
    return patronymic;
}

void Client::setPatronymic(QString *patronymic) {
    Client::patronymic = patronymic;
}

QDate *Client::getDateOfBirth() const {
    return dateOfBirth;
}

void Client::setDateOfBirth(QDate *dateOfBirth) {
    Client::dateOfBirth = dateOfBirth;
}

QString *Client::getPlaceOfBirth() const {
    return placeOfBirth;
}

void Client::setPlaceOfBirth(QString *placeOfBirth) {
    Client::placeOfBirth = placeOfBirth;
}

bool Client::isSex() const {
    return sex;
}

void Client::setSex(bool sex) {
    Client::sex = sex;
}

Client::Client(int id, const QString &passportData, const QString &surname, const QString &name,
               const QString &patronymic, const QDate &dateOfBirth, const QString &placeOfBirth, bool sex) : Model(
        id) {
    this->passportData = new QString(passportData);
    this->surname = new QString(surname);
    this->clientName = new QString(name);
    this->patronymic = new QString(patronymic);
    this->dateOfBirth = new QDate(dateOfBirth);
    this->sex = sex;
}

Client::Client(const QString &passportData, const QString &surname, const QString &name,
               const QString &patronymic, const QDate &dateOfBirth, const QString *&placeOfBirth, bool sex) : Model() {
    this->passportData = new QString(passportData);
    this->surname = new QString(surname);
    this->clientName = new QString(name);
    this->patronymic = new QString(patronymic);
    this->dateOfBirth = new QDate(dateOfBirth);
    this->sex = sex;
}

QStringList Client::columnList = {"ID_i", "Passport Data_s", "Surname_s", "Name_s", "Patronymic_s", "Date of birth_d",
                                  "Place of birth_s", "Sex_b"};

QStringList *Client::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->passportData, *this->surname, *this->clientName, *this->patronymic,
             this->dateOfBirth->toString(), *this->placeOfBirth, (this->sex ? "+" : "-")});
}

QStringList *Client::getValForAdd() {
    return new QStringList(
            {QString::number(this->id), *this->surname, *this->clientName, *this->patronymic,
             this->dateOfBirth->toString()});
}
