//
// Created by rienel on 08.04.18.
//

#include "HotelRoomType.h"

HotelRoomType::HotelRoomType(int id, QString *name) : Model(id), name(name) {}

HotelRoomType::HotelRoomType(QString *name) : name(name) {}

HotelRoomType::HotelRoomType(int id) : Model(id) {}

HotelRoomType::HotelRoomType() {}

HotelRoomType::HotelRoomType(int id, const QString &name) : Model(id) {
    this->name = new QString(name);
}

HotelRoomType::HotelRoomType(const QString &name) : Model() {
    this->name = new QString(name);
}

QString *HotelRoomType::getName() const {
    return name;
}

void HotelRoomType::setName(QString *name) {
    this->name = name;
}

HotelRoomType::~HotelRoomType() {
    delete this->name;
}

QStringList HotelRoomType::columnList = {"ID", "Name"};

QStringList *HotelRoomType::getValueList() {
    return new QStringList({
                                   QString::number(this->id),
                                   *this->name
                           });
}
