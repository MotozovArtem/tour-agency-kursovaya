//
// Created by rienel on 11.04.18.
//

#include "TourType.h"

TourType::TourType(int id, QString *name) : Model(id), tourTypeName(name) {}

TourType::TourType(int id) : Model(id) {}

TourType::TourType(QString *name) : tourTypeName(name) {}

TourType::TourType() {}

TourType::~TourType() {
    if(this->tourTypeName!=nullptr){
        delete this->tourTypeName;
        this->tourTypeName=nullptr;
    }
}

QString *TourType::getName() const {
    return tourTypeName;
}

void TourType::setName(QString *name) {
    TourType::tourTypeName = name;
}

TourType::TourType(int id, const QString &name) : Model(id) {
    this->tourTypeName = new QString(name);
}

TourType::TourType(const QString &name) : Model() {
    this->tourTypeName = new QString(name);
}

QStringList TourType::columnList = {"ID_i", "Name_s"};

QStringList *TourType::getValueList() {
    return new QStringList({QString::number(this->id), *this->tourTypeName});
}

QStringList *TourType::getValForAdd() {
    return getValueList();
}

TourType::TourType(const QStringList &args) : Model(args) {
    this->tourTypeName = new QString(args[1]);
}
