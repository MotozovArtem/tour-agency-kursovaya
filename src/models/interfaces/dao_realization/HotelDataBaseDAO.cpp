//
// Created by rienel on 16.04.18.
//

#include "HotelDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"


QList<Hotel *> HotelDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Hotel *> hotelList;
    if (query.exec("SELECT * FROM Hotel")) {
        QSqlRecord rec = query.record();
        while (query.next()) {
            hotelList << new Hotel(
                    query.value(rec.indexOf("id")).toInt(),
                    query.value(rec.indexOf("hotel_name")).toString(),
                    query.value(rec.indexOf("address")).toString(),
                    query.value(rec.indexOf("stars")).toInt(),
                    query.value(rec.indexOf("year_of_foundation")).toDate(),
                    query.value(rec.indexOf("id_city")).toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelDataBaseDAO::getAll error", query.lastError().text()));
    }
    return hotelList;
}

Hotel *HotelDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM Hotel WHERE id=:id");
    query.bindValue(":id", id);
    Hotel *hotel = nullptr;
    if (query.exec()) {
        QSqlRecord rec = query.record();
        while (query.next()) {
            hotel = new Hotel(
                    query.value(rec.indexOf("id")).toInt(),
                    query.value(rec.indexOf("hotel_name")).toString(),
                    query.value(rec.indexOf("address")).toString(),
                    query.value(rec.indexOf("stars")).toInt(),
                    query.value(rec.indexOf("year_of_foundation")).toDate(),
                    query.value(rec.indexOf("id_city")).toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelDataBaseDAO::getById error", query.lastError().text()));
    }
    return hotel;
}

void HotelDataBaseDAO::add(Hotel *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Hotel(hotel_name, address, stars, year_of_foundation, id_city) "
                  "VALUES (:hotel_name, :address, :stars, :year_of_foundation, :id_city)");
    query.bindValue(":hotel_name", *model->getHotelName());
    query.bindValue(":address", *model->getAddress());
    query.bindValue(":stars", model->getStars());
    query.bindValue(":year_of_foundation", *model->getYearOfFoundation());
    query.bindValue(":id_city", model->getIdCity());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelDataBaseDAO::add error", query.lastError().text()));
    }
}

void HotelDataBaseDAO::update(Hotel *model) {
    QSqlQuery query;
    query.prepare("UPDATE Hotel SET address=:address, hotel_name=:hotel_name, "
                  "stars=:stars, year_of_foundation=:year_of_foundation, "
                  "id_city=:id_city WHERE id=:id");
    query.bindValue(":address", *model->getAddress());
    query.bindValue(":hotel_name", *model->getHotelName());
    query.bindValue(":stars", model->getStars());
    query.bindValue(":year_of_foundation", *model->getYearOfFoundation());
    query.bindValue(":id_city", model->getIdCity());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelDataBaseDAO::update error", query.lastError().text()));
    }
}

void HotelDataBaseDAO::del(Hotel *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Hotel WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelDataBaseDAO::del error", query.lastError().text()));
    }
}

QList<Hotel *> HotelDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<Hotel *> hotelList;
    if (query.exec("SELECT Hotel.id, Hotel.hotel_name, Hotel.address, Hotel.stars, "
                   "Hotel.years, Hotel.year_of_foundation, City.city_name FROM Hotel "
                   "LEFT JOIN City ON (Hotel.id_city=City.id)"
                   "ORDER BY id")) {
        QSqlRecord rec = query.record();
        while (query.next()) {
            Hotel *hotel = new Hotel(
                    query.value(rec.indexOf("id")).toInt(),
                    query.value(rec.indexOf("hotel_name")).toString(),
                    query.value(rec.indexOf("address")).toString(),
                    query.value(rec.indexOf("stars")).toInt(),
                    query.value(rec.indexOf("year_of_foundation")).toDate(),
                    0
            );
            hotel->setCityName(new QString(query.value("city_name").toString()));
            hotelList << hotel;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("HotelDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return hotelList;
}
