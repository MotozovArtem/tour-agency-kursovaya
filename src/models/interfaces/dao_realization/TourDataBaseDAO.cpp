//
// Created by rienel on 27.05.18.
//

#include <QtSql/QtSql>
#include "TourDataBaseDAO.h"
#include "utils/Logger.h"

QList<Tour *> TourDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Tour *> list;
    if (query.exec("SELECT id, tour_name, days, id_city, id_tour_type FROM Tour ORDER BY id")) {
        while (query.next()) {
            list << new Tour(
                    query.value("id").toInt(),
                    query.value("tour_name").toString(),
                    query.value("days").toInt(),
                    query.value("id_city").toInt(),
                    query.value("id_tour_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Tour *TourDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT Tour.id, Tour.tour_name, Tour.days, Tour.id_city, Tour.id_tour_type, City.city_name, TourType.tour_type_name "
                  "FROM Tour "
                  "LEFT JOIN City ON (Tour.id_city=City.id) "
                  "LEFT JOIN TourType ON (Tour.id_tour_type=TourType.id) "
                  "WHERE Tour.id=:id");
    query.bindValue(":id", id);
    Tour *tour = nullptr;
    if (query.exec()) {
        while (query.next()) {
            tour = new Tour(
                    query.value("id").toInt(),
                    query.value("tour_name").toString(),
                    query.value("days").toInt(),
                    query.value("id_city").toInt(),
                    query.value("id_tour_type").toInt()
            );
            tour->setTourType(new QString(query.value("tour_type_name").toString()));
            tour->setCity(new QString(query.value("city_name").toString()));
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourDataBaseDAO::getById() error", query.lastError().text()));
    }
    return tour;
}

void TourDataBaseDAO::add(Tour *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Tour(tour_name, days, id_city, id_tour_type) "
                  "VALUES (:tour_name, :days, :id_city, :id_tour_type)");
    query.bindValue(":tour_name", *model->getName());
    query.bindValue(":days", model->getDays());
    query.bindValue(":id_city", model->getIdCity());
    query.bindValue(":id_tour_type", model->getIdTourType());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourDataBaseDAO::add() error", query.lastError().text()));
    }
}

void TourDataBaseDAO::update(Tour *model) {
    QSqlQuery query;
    query.prepare(
            "UPDATE Tour SET tour_name=:tour_name, days=:days, id_city=:id_city, id_tour_type=:id_tour_type WHERE id=:id");
    query.bindValue(":tour_name", *model->getName());
    query.bindValue(":days", model->getDays());
    query.bindValue(":id_city", model->getIdCity());
    query.bindValue(":id_tour_type", model->getIdTourType());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourDataBaseDAO::update() error", query.lastError().text()));
    }
}

void TourDataBaseDAO::del(Tour *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Tour WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Tour *> TourDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<Tour *> list;
    if (query.exec("SELECT Tour.id, Tour.tour_name, Tour.days, "
                   "Tour.id_city, Tour.id_tour_type, "
                   "City.city_name, TourType.tour_type_name FROM Tour "
                   "LEFT JOIN City ON (Tour.id_hotel_room=City.id)"
                   "LEFT JOIN TourType ON (Tour.id_contract=TourType.id)"
                   "ORDER BY id")) {
        while (query.next()) {
            Tour *tour = new Tour(
                    query.value("id").toInt(),
                    query.value("tour_name").toString(),
                    query.value("days").toInt(),
                    query.value("id_city").toInt(),
                    query.value("id_tour_type").toInt()
            );
            tour->setCity(new QString(query.value("city_name").toString()));
            tour->setTourType(new QString(query.value("tour_type_name").toString()));
            list << tour;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
