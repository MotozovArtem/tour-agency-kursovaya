//
// Created by rienel on 08.04.18.
//

#include "HotelRoomType.h"

HotelRoomType::HotelRoomType(int id, QString *name) : Model(id), name(name) {}

HotelRoomType::HotelRoomType(QString *name) : name(name) {}

HotelRoomType::HotelRoomType(int id) : Model(id) {}

HotelRoomType::HotelRoomType() {}

QString *HotelRoomType::getName() const {
    return name;
}

void HotelRoomType::setName(QString *name) {
    this->name = name;
}

HotelRoomType::~HotelRoomType() {
    delete this->name;
}
