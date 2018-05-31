//
// Created by rienel on 27.05.18.
//

#include "ReservByAgreementDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<ReservByAgreement *> ReservByAgreementDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<ReservByAgreement *> list;
    if (query.exec("SELECT id, date_of_begining, id_hotel_room, id_contract FROM ReservByAgreement ORDER BY id")) {
        while (query.next()) {
            list << new ReservByAgreement(
                    query.value("id").toInt(),
                    query.value("date_of_begining").toDate(),
                    query.value("id_hotel_room").toInt(),
                    query.value("id_contract").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservByAgreementDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

ReservByAgreement *ReservByAgreementDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT ReservByAgreement.id, ReservByAgreement.date_of_begining, ReservByAgreement.id_hotel_room, ReservByAgreement.id_contract, "
                  "HotelRoom.hotel_room_name, Contract.contract_name "
                  "FROM ReservByAgreement "
                  "LEFT JOIN HotelRoom ON (ReservByAgreement.id_hotel_room=HotelRoom.id) "
                  "LEFT JOIN Contract ON (ReservByAgreement.id_contract=Contract.id) "
                  "WHERE ReservByAgreement.id=:id");
    query.bindValue(":id", id);
    ReservByAgreement *reserv = nullptr;
    if (query.exec()) {
        while (query.next()) {
            reserv = new ReservByAgreement(
                    query.value("id").toInt(),
                    query.value("date_of_begining").toDate(),
                    query.value("id_hotel_room").toInt(),
                    query.value("id_contract").toInt()
            );
            reserv->setContract(new QString(query.value("contract_name").toString()));
            reserv->setHotelRoom(new QString(query.value("hotel_room_name").toString()));
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservByAgreementDataBaseDAO::getById() error", query.lastError().text()));
    }
    return reserv;
}

void ReservByAgreementDataBaseDAO::add(ReservByAgreement *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO ReservByAgreement(date_of_begining, id_hotel_room, id_contract) "
                  "VALUES (:date_of_begining, :id_hotel_room, :id_contract)");
    query.bindValue(":date_of_begining", model->getDateOfBegining()->toString("dd.MM.yyyy"));
    query.bindValue(":id_hotel_room", model->getIdHotelRoom());
    query.bindValue(":id_contract", model->getIdContract());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservByAgreementDataBaseDAO::add() error", query.lastError().text()));
    }
}

void ReservByAgreementDataBaseDAO::update(ReservByAgreement *model) {
    QSqlQuery query;
    query.prepare("UPDATE ReservByAgreement SET date_of_begining=:date_of_begining, id_hotel_room=:id_hotel_room, "
                  "id_contract=:id_contract WHERE id=:id");
    query.bindValue(":date_of_begining", model->getDateOfBegining()->toString("dd.MM.yyyy"));
    query.bindValue(":id_hotel_room", model->getIdHotelRoom());
    query.bindValue(":id_contract", model->getIdContract());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservByAgreementDataBaseDAO::update() error", query.lastError().text()));
    }
}

void ReservByAgreementDataBaseDAO::del(ReservByAgreement *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM ReservByAgreement WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ReservByAgreementDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<ReservByAgreement *> ReservByAgreementDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<ReservByAgreement *> list;
    if (query.exec(
            "SELECT ReservByAgreement.id, ReservByAgreement.date_of_begining, ReservByAgreement.id_hotel_room, "
            "ReservByAgreement.id_contract, Contract.contract_name, HotelRoom.hotel_room_name  "
            "  FROM ReservByAgreement "
            " LEFT JOIN HotelRoom ON (ReservByAgreement.id_hotel_room=HotelRoom.id)"
            "LEFT JOIN Contract ON (ReservByAgreement.id_contract=Contract.id)"
            "ORDER BY id")) {
        while (query.next()) {
            ReservByAgreement *reserv = new ReservByAgreement(
                    query.value("id").toInt(),
                    query.value("date_of_begining").toDate(),
                    query.value("id_hotel_room").toInt(),
                    query.value("id_contract").toInt()
            );
            reserv->setContract(new QString(query.value("contract_name").toString()));
            reserv->setHotelRoom(new QString(query.value("hotel_room_name").toString()));
            list << reserv;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(
                QString("%1 %2").arg("ReservByAgreementDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
