//
// Created by rienel on 26.05.18.
//

#include "HotelRoomDataBaseDAO.h"
#include "utils/Logger.h"
#include <QtSql/QtSql>
//#include <QString>

QList<HotelRoom *> HotelRoomDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<HotelRoom *> hotelRoomList;
    if (query.exec("SELECT id, hotel_room_name, places, shower, second_restroom, balcony,"
                   " id_hotel, id_hotel_room_type FROM HotelRoom ORDER BY id")) {
        while (query.next()) {
            hotelRoomList << new HotelRoom(
                    query.value("id").toInt(),
                    query.value("hotel_room_name").toString(),
                    query.value("places").toInt(),
                    query.value("shower").toBool(),
                    query.value("second_restroom").toBool(),
                    query.value("balcony").toBool(),
                    query.value("id_hotel").toInt(),
                    query.value("id_hotel_room_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return hotelRoomList;
}

HotelRoom *HotelRoomDataBaseDAO::getById(int id) {
    QSqlQuery query;
    HotelRoom *hotelRoom = nullptr;
    query.prepare("SELECT id, hotel_room_name, places, shower, second_restroom, balcony,"
                  " id_hotel, id_hotel_room_type FROM HotelRoom WHERE id=:id ORDER BY id");
    query.bindValue(":id", id);
    if (query.exec()) {
        while (query.next()) {
            hotelRoom = new HotelRoom(
                    query.value("id").toInt(),
                    query.value("hotel_room_name").toString(),
                    query.value("places").toInt(),
                    query.value("shower").toBool(),
                    query.value("second_restroom").toBool(),
                    query.value("balcony").toBool(),
                    query.value("id_hotel").toInt(),
                    query.value("id_hotel_room_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomDataBaseDAO::getById() error", query.lastError().text()));
    }
    return hotelRoom;
}

void HotelRoomDataBaseDAO::add(HotelRoom *model) {
    QSqlQuery query;
    query.prepare(
            "INSERT INTO HotelRoo(hotel_room_name, places, shower, second_restroom, balcony, id_hotel, id_hotel_room_type)"
            "VALUES(:hotel_room_name, :places, :shower, :second_restroom, :balcony, :id_hotel, :id_hotel_room_type)");
    query.bindValue(":hotel_room_name", *model->getHotelRoomName());
    query.bindValue(":places", model->getPlaces());
    query.bindValue(":shower", model->isShower());
    query.bindValue(":second_restroom", model->isSecondRestroom());
    query.bindValue(":balcony", model->isBalcony());
    query.bindValue(":id_hotel", model->getIdHotel();
    query.bindValue(":id_hotel_room_type", model->getIdHotelRoomType());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomDataBaseDAO::add() error", query.lastError().text()));
    }
}

void HotelRoomDataBaseDAO::update(HotelRoom *model) {
    QSqlQuery query;
    query.prepare("UPDATE HotelRoom SET hotel_room_name=:hotel_room_name, places=:places, shower=:shower, "
                  "second_restroom=:second_restroom, balcony=:balcony, id_hotel=:id_hotel, "
                  "id_hotel_room_type=:id_hotel_room_type WHERE id=:id");
    query.bindValue(":hotel_room_name", *model->getHotelRoomName());
    query.bindValue(":places", model->getPlaces());
    query.bindValue(":shower", model->isShower());
    query.bindValue(":second_restroom", model->isSecondRestroom());
    query.bindValue(":balcony", model->isBalcony());
    query.bindValue(":id_hotel", model->getIdHotel();
    query.bindValue(":id_hotel_room_type", model->getIdHotelRoomType());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomDataBaseDAO::update() error", query.lastError().text()));
    }
}

void HotelRoomDataBaseDAO::del(HotelRoom *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM HotelRoom WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelRoomDataBaseDAO::del() error", query.lastError().text()));
    }
}
