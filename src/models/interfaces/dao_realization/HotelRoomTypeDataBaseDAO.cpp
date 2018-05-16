//
// Created by rienel on 16.05.18.
//

#include <QtSql/QtSql>
#include "HotelRoomTypeDataBaseDAO.h"
#include <utils/Logger.h>

QList<HotelRoomType *> HotelRoomTypeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<HotelRoomType *> list;
    if (query.exec("SELECT id, name FROM HotelRoomType")) {
        while (query.next()) {
            list << new HotelRoomType(
                    query.value("id").toInt(),
                    query.value("name").toString()
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
    query.prepare("SELECT id, name FROM HotelRoomType WHERE id=:id");
    query.bindValue(":id", id);
    if (query.exec()) {
        hotelRoomType = new HotelRoomType(
                query.value("id").toInt(),
                query.value("name").toString()
        );
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomTypeDataBaseDAO::getById error", query.lastError().text()));
    }
    return hotelRoomType;
}

void HotelRoomTypeDataBaseDAO::add(HotelRoomType *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO HotelRoomType(name) VALUES (:name)");
    query.bindValue(":name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomTypeDataBaseDAO::add error", query.lastError().text()));
    }
}

void HotelRoomTypeDataBaseDAO::update(HotelRoomType *model) {
    QSqlQuery query;
    query.prepare("UPDATE HotelRoomType SET name=:name WHERE id=:id");
    query.bindValue(":name", *model->getName());
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
