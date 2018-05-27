//
// Created by rienel on 27.05.18.
//

#include "PlaceArrivalDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<PlaceArrival *> PlaceArrivalDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<PlaceArrival *> list;
    if (query.exec("SELECT id, place_arrival_name, address, "
                   "id_city, id_place_arrival_type FROM PlaceArrival ORDER BY id")) {
        while (query.next()) {
            list << new PlaceArrival(
                    query.value("id").toInt(),
                    query.value("place_arrival_name").toString(),
                    query.value("address").toString(),
                    query.value("id_city").toInt(),
                    query.value("id_place_arrival_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

PlaceArrival *PlaceArrivalDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, place_arrival_name, address, id_city, id_place_arrival_type "
                  "FROM PlaceArrival WHERE id=:id");
    query.bindValue(":id", id);
    PlaceArrival *placeArrival = nullptr;
    if (query.exec()) {
        while (query.next()) {
            placeArrival = new PlaceArrival(
                    query.value("id").toInt(),
                    query.value("place_arrival_name").toString(),
                    query.value("address").toString(),
                    query.value("id_city").toInt(),
                    query.value("id_place_arrival_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalDataBaseDAO::getById() error", query.lastError().text()));
    }
    return placeArrival;
}

void PlaceArrivalDataBaseDAO::add(PlaceArrival *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO PlaceArrival(place_arrival_name, address, id_city, id_place_arrival_type) "
                  "VALUES (:place_arrival_name, :address, :id_city, :id_place_arrival_type)");
    query.bindValue(":place_arrival_name", *model->getName());
    query.bindValue(":address", *model->getAddress());
    query.bindValue(":id_city", model->getIdCity());
    query.bindValue(":id_place_arrival_type", model->getIdPlaceArrivalType());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalDataBaseDAO::add() error", query.lastError().text()));
    }
}

void PlaceArrivalDataBaseDAO::update(PlaceArrival *model) {
    QSqlQuery query;
    query.prepare("UPDATE PlaceArrival SET place_arrival_name=:place_arrival_name, address=:address, "
                  "id_city=:id_city, id_place_arrival_type=:id_place_arrival_type WHERE id=:id");
    query.bindValue(":place_arrival_name", *model->getName());
    query.bindValue(":address", *model->getAddress());
    query.bindValue(":id_city", model->getIdCity());
    query.bindValue(":id_place_arrival_type", model->getIdPlaceArrivalType());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalDataBaseDAO::update() error", query.lastError().text()));
    }
}

void PlaceArrivalDataBaseDAO::del(PlaceArrival *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM PlaceArrival WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<PlaceArrival *> PlaceArrivalDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<PlaceArrival *> list;
    if (query.exec("SELECT PlaceArrival.id, PlaceArrival.place_arrival_name, PlaceArrival.address, "
                   "City.city_name,  PlaceArrivalType.place_arrival_type_name, "
                   "PlaceArrival.id_city, PlaceArrival.id_place_arrival_type"
                   "FROM PlaceArrival "
                   "LEFT JOIN City ON (PlaceArrival.id_city=City.id)"
                   "LEFT JOIN PlaceArrivalType ON (PlaceArrival.id_place_arrival_type=PlaceArrivalType.id)"
                   "ORDER BY id")) {
        while (query.next()) {
            PlaceArrival *placeArrival = new PlaceArrival(
                    query.value("id").toInt(),
                    query.value("place_arrival_name").toString(),
                    query.value("address").toString(),
                    query.value("id_city").toInt(),
                    query.value("id_place_arrival_type").toInt()
            );
            placeArrival->setCity(new QString(query.value("city_name").toString()));
            placeArrival->setPlaceArrivalType(new QString(query.value("place_arrival_type_name").toString()));
            list << placeArrival;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}

