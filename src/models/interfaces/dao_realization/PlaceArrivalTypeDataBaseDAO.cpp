//
// Created by rienel on 27.05.18.
//

#include "PlaceArrivalTypeDataBaseDAO.h"
#include "utils/Logger.h"
#include <QtSql/QtSql>

QList<PlaceArrivalType *> PlaceArrivalTypeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<PlaceArrivalType *> list;
    if (query.exec("SELECT id, place_arrival_type_name FROM PlaceArrivalType ORDER BY id")) {
        while (query.next()) {
            list << new PlaceArrivalType(
                    query.value("id").toInt(),
                    query.value("place_arrival_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalTypeDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

PlaceArrivalType *PlaceArrivalTypeDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, place_arrival_type_name FROM PlaceArrivalType WHERE id=:id");
    query.bindValue(":id", id);
    PlaceArrivalType *placeArrivalType = nullptr;
    if (query.exec()) {
        while (query.next()) {
            placeArrivalType = new PlaceArrivalType(
                    query.value("id").toInt(),
                    query.value("place_arrival_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalTypeDataBaseDAO::getById() error", query.lastError().text()));
    }
    return placeArrivalType;
}

void PlaceArrivalTypeDataBaseDAO::add(PlaceArrivalType *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO PlaceArrivalType(place_arrival_type_name) "
                  "VALUES (:place_arrival_type_name)");
    query.bindValue(":place_arrival_type_name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalTypeDataBaseDAO::add() error", query.lastError().text()));
    }
}

void PlaceArrivalTypeDataBaseDAO::update(PlaceArrivalType *model) {
    QSqlQuery query;
    query.prepare("UPDATE PlaceArrivalType SET place_arrival_type_name=:place_arrival_type_name WHERE id=:id");
    query.bindValue(":place_arrival_type_name", *model->getName());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalTypeDataBaseDAO::update() error", query.lastError().text()));
    }
}

void PlaceArrivalTypeDataBaseDAO::del(PlaceArrivalType *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM PlaceArrivalType WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("PlaceArrivalTypeDataBaseDAO::del() error", query.lastError().text()));
    }
}


QList<PlaceArrivalType *> PlaceArrivalTypeDataBaseDAO::getAllFilled() {
    return PlaceArrivalTypeDataBaseDAO::getAll();
}
