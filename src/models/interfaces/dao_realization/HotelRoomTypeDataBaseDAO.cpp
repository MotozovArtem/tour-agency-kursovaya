//
// Created by rienel on 16.05.18.
//

#include <QtSql/QtSql>
#include "HotelRoomTypeDataBaseDAO.h"
#include <utils/Logger.h>

QList<HotelRoomType *> HotelRoomTypeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<HotelRoomType *> list;
    if (query.exec("SELECT id, hotelRoomTypeName FROM HotelRoomType")) {
        while (query.next()) {
            list << new HotelRoomType(
                    query.value("id").toInt(),
                    query.value("hotelRoomTypeName").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomTypeDataBaseDAO::getAll error", query.lastError().text()));
    }
    return list;
}

HotelRoomType *HotelRoomTypeDataBaseDAO::getById(int id) {
    QSqlQuery query;
    HotelRoomType *hotelRoomType = nullptr;
    query.prepare("SELECT id, hotel_room_type_name FROM HotelRoomType WHERE id=:id");
    query.bindValue(":id", id);
    if (query.exec()) {
        hotelRoomType = new HotelRoomType(
                query.value("id").toInt(),
                query.value("hotel_room_type_name").toString()
        );
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomTypeDataBaseDAO::getById error", query.lastError().text()));
    }
    return hotelRoomType;
}

void HotelRoomTypeDataBaseDAO::add(HotelRoomType *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO HotelRoomType(hotel_room_type_name) VALUES (:hotelRoomTypeName)");
    query.bindValue(":hotel_room_type_name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomTypeDataBaseDAO::add error", query.lastError().text()));
    }
}

void HotelRoomTypeDataBaseDAO::update(HotelRoomType *model) {
    QSqlQuery query;
    query.prepare("UPDATE HotelRoomType SET hotel_room_type_name=:hotel_room_type_name WHERE id=:id");
    query.bindValue(":hotel_room_type_name", *model->getName());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomTypeDataBaseDAO::update error", query.lastError().text()));
    }
}

void HotelRoomTypeDataBaseDAO::del(HotelRoomType *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM HotelRoomType WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomTypeDataBaseDAO::del error", query.lastError().text()));
    }
}

QList<HotelRoomType *> HotelRoomTypeDataBaseDAO::getAllFilled() {
    return HotelRoomTypeDataBaseDAO::getAll();
}
