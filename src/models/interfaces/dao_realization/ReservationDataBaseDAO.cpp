//
// Created by rienel on 27.05.18.
//

#include <QtSql/QtSql>
#include "ReservationDataBaseDAO.h"
#include "utils/Logger.h"

QList<Reservation *> ReservationDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Reservation *> list;
    if (query.exec("SELECT id, date_of_begining, date_of_ending, "
                   "id_hotel_room, id_contract FROM Reservation ORDER BY id")) {
        while (query.next()) {
            list << new Reservation(
                    query.value("id").toInt(),
                    query.value("date_of_begining").toDate(),
                    query.value("date_of_ending").toDate(),
                    query.value("id_hotel_room").toInt(),
                    query.value("id_contract").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservationDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Reservation *ReservationDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, date_of_begining, date_of_ending, if_hotel_room, id_contract "
                  "FROM Reservation WHERE id=:id");
    query.bindValue(":id", id);
    Reservation *reservation = nullptr;
    if (query.exec()) {
        while (query.next()) {
            reservation = new Reservation(
                    query.value("id").toInt(),
                    query.value("date_of_begining").toDate(),
                    query.value("date_of_ending").toDate(),
                    query.value("id_hotel_room").toInt(),
                    query.value("id_contract").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservationDataBaseDAO::getById() error", query.lastError().text()));
    }
    return reservation;
}

void ReservationDataBaseDAO::add(Reservation *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Reservation(date_of_begining, date_of_ending, id_hotel_room, id_contract) "
                  "VALUES (:date_of_begining, :date_of_ending, :id_hotel_room, :id_contract)");
    query.bindValue(":date_of_begining", *model->getDateOfBegining());
    query.bindValue(":date_of_ending", *model->getDateOfEnding());
    query.bindValue(":id_hotel_room", model->getIdHotelRoom());
    query.bindValue(":id_contract", model->getIdContract());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservationDataBaseDAO::add() error", query.lastError().text()));
    }
}

void ReservationDataBaseDAO::update(Reservation *model) {
    QSqlQuery query;
    query.prepare("UPDATE Reservation SET date_of_begining=:date_of_begining, date_of_ending=:date_of_ending, "
                  "id_hotel_room=:id_hotel_room, id_contract=:id_contract WHERE id=:id");
    query.bindValue(":date_of_begining", *model->getDateOfBegining());
    query.bindValue(":date_of_ending", *model->getDateOfEnding());
    query.bindValue(":id_hotel_room", model->getIdHotelRoom());
    query.bindValue(":id_contract", model->getIdContract());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservationDataBaseDAO::update() error", query.lastError().text()));
    }
}

void ReservationDataBaseDAO::del(Reservation *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Reservation WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservationDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Reservation *> ReservationDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<Reservation *> list;
    if (query.exec("SELECT Reservation.id, Reservation.date_of_begining, Reservation.date_of_ending, "
                   "Reservation.id_hotel_room, Reservation.id_contract, "
                   "HotelRoom.hotel_room_name, Contract.contract_name FROM Reservation "
                   "LEFT JOIN HotelRoom ON (Reservation.id_hotel_room=HotelRoom.id)"
                   "LEFT JOIN Contract ON (Reservation.id_contract=Contract.id)"
                   "ORDER BY id")) {
        while (query.next()) {
            Reservation *reservation = new Reservation(
                    query.value("id").toInt(),
                    query.value("date_of_begining").toDate(),
                    query.value("date_of_ending").toDate(),
                    query.value("id_hotel_room").toInt(),
                    query.value("id_contract").toInt()
            );
            reservation->setContract(new QString(query.value("contract_name").toString()));
            reservation->setHotelRoom(new QString(query.value("hotel_room_name").toString()));
            list << reservation;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservationDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
