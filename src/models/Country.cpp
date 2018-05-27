//
// Created by rienel on 14.04.18.
//

#include "Country.h"

Country::Country(int id, QString *name, QDate *foundationDate) : Model(id), countryName(name),
                                                                 foundationDate(foundationDate) {}

Country::Country(QString *name, QDate *foundationDate) : countryName(name), foundationDate(foundationDate) {}

Country::Country(int id) : Model(id) {}

Country::Country() {}

Country::~Country() {
    delete this->countryName;
    delete this->foundationDate;
}

QString *Country::getName() const {
    return countryName;
}

void Country::setName(QString *name) {
    Country::countryName = name;
}

QDate *Country::getFoundationDate() const {
    return foundationDate;
}

void Country::setFoundationDate(QDate *foundationDate) {
    Country::foundationDate = foundationDate;
}

Country::Country(int id, const QString &name, const QDate &foundationDate) : Model(id) {
    this->countryName = new QString(name);
    this->foundationDate = new QDate(foundationDate);
}

Country::Country(const QString &name, const QDate &foundationDate) : Model() {
    this->countryName = new QString(name);
    this->foundationDate = new QDate(foundationDate);
}

QStringList Country::columnList = {"ID", "Name", "Foundation date"};

QStringList *Country::getValueList() {
    return new QStringList({QString::number(this->id), *this->countryName, this->foundationDate->toString()});
}
