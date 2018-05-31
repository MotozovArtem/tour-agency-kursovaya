//
// Created by rienel on 27.05.18.
//

#include "FlightDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<Flight *> FlightDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Flight *> list;
    if (query.exec("SELECT id, date_of_purchase, date_of_departure, "
                   "departure_time, arrival_time, arrival_date FROM Flight ORDER BY id")) {
        while (query.next()) {
            list << new Flight(
                    query.value("id").toInt(),
                    query.value("date_of_purchase").toDate(),
                    query.value("date_of_departure").toDate(),
                    query.value("departure_time").toTime(),
                    query.value("arrival_time").toTime(),
                    query.value("arrival_date").toDate()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("FlightDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Flight *FlightDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, date_of_purchase, date_of_departure, departure_time, arrival_time, arrival_date "
                  "FROM Flight WHERE id=:id");
    query.bindValue(":id", id);
    Flight *flight = nullptr;
    if (query.exec()) {
        while (query.next()) {
            flight = new Flight(
                    query.value("id").toInt(),
                    query.value("date_of_purchase").toDate(),
                    query.value("date_of_departure").toDate(),
                    query.value("departure_time").toTime(),
                    query.value("arrival_time").toTime(),
                    query.value("arrival_date").toDate()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("FlightDataBaseDAO::getById() error", query.lastError().text()));
    }
    return flight;
}

void FlightDataBaseDAO::add(Flight *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Flight(date_of_purchase, date_of_departure, departure_time, arrival_time, arrival_date) "
                  "VALUES (:date_of_purchase, :date_of_departure, :departure_time, :arrival_time, :arrival_date)");
    query.bindValue(":date_of_purchase", model->getDateOfPurchase()->toString("dd.MM.yyyy"));
    query.bindValue(":date_of_departure", model->getDateOfDeparture()->toString("dd.MM.yyyy"));
    query.bindValue(":departure_time", model->getDepartureTime()->toString("HH:mm"));
    query.bindValue(":arrival_time", model->getArrivalTime()->toString("HH:mm"));
    query.bindValue(":arrival_date", model->getArrivalDate()->toString("dd.MM.yyyy"));
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("FlightDataBaseDAO::add() error", query.lastError().text()));
    }
}

void FlightDataBaseDAO::update(Flight *model) {
    QSqlQuery query;
    query.prepare("UPDATE Flight SET date_of_purchase=:date_of_purchase, date_of_departure=:date_of_departure, "
                  "departure_time=:departure_time, arrival_time=:arrival_time, arrival_date=:arrival_date WHERE id=:id");
    query.bindValue(":date_of_purchase", model->getDateOfPurchase()->toString("dd.MM.yyyy"));
    query.bindValue(":date_of_departure", model->getDateOfDeparture()->toString("dd.MM.yyyy"));
    query.bindValue(":departure_time", model->getDepartureTime()->toString("HH:mm"));
    query.bindValue(":arrival_time", model->getArrivalTime()->toString("HH:mm"));
    query.bindValue(":arrival_date", model->getArrivalDate()->toString("dd.MM.yyyy"));
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("FlightDataBaseDAO::update() error", query.lastError().text()));
    }
}

void FlightDataBaseDAO::del(Flight *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Flight WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("FlightDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Flight *> FlightDataBaseDAO::getAllFilled() {
    return FlightDataBaseDAO::getAll();
}

