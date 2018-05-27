//
// Created by rienel on 08.04.18.
//

#include "HotelRoomType.h"

HotelRoomType::HotelRoomType(int id, QString *name) : Model(id), hotelRoomTypeName(name) {}

HotelRoomType::HotelRoomType(QString *name) : hotelRoomTypeName(name) {}

HotelRoomType::HotelRoomType(int id) : Model(id) {}

HotelRoomType::HotelRoomType() {}

HotelRoomType::HotelRoomType(int id, const QString &name) : Model(id) {
    this->hotelRoomTypeName = new QString(name);
}

HotelRoomType::HotelRoomType(const QString &name) : Model() {
    this->hotelRoomTypeName = new QString(name);
}

QString *HotelRoomType::getName() const {
    return hotelRoomTypeName;
}

void HotelRoomType::setName(QString *name) {
    this->hotelRoomTypeName = name;
}

HotelRoomType::~HotelRoomType() {
    delete this->hotelRoomTypeName;
}

QStringList HotelRoomType::columnList = {"ID", "Name"};

QStringList *HotelRoomType::getValueList() {
    return new QStringList({
                                   QString::number(this->id),
                                   *this->hotelRoomTypeName
                           });
}
