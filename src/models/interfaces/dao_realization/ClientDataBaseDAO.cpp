//
// Created by rienel on 27.05.18.
//

#include "ClientDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<Client *> ClientDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Client *> list;
    if (query.exec("SELECT id, passport_data, surname, "
                   "client_name, patronymic, date_of_birth, place_of_birth, sex FROM Client ORDER BY id")) {
        while (query.next()) {
            list << new Client(
                    query.value("id").toInt(),
                    query.value("passport_data").toString(),
                    query.value("surname").toString(),
                    query.value("client_name").toString(),
                    query.value("patronymic").toString(),
                    query.value("date_of_birth").toDate(),
                    query.value("place_of_birth").toString(),
                    query.value("sex").toBool()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Client *ClientDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, passport_data, surname, client_name, patronymic, date_of_birth, place_of_birth, sex"
                  "FROM Client WHERE id=:id");
    query.bindValue(":id", id);
    Client *client = nullptr;
    if (query.exec()) {
        while (query.next()) {
            client = new Client(
                    query.value("id").toInt(),
                    query.value("passport_data").toString(),
                    query.value("surname").toString(),
                    query.value("client_name").toString(),
                    query.value("patronymic").toString(),
                    query.value("date_of_birth").toDate(),
                    query.value("place_of_birth").toString(),
                    query.value("sex").toBool()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientDataBaseDAO::getById() error", query.lastError().text()));
    }
    return client;
}

void ClientDataBaseDAO::add(Client *model) {
    QSqlQuery query;
    query.prepare(
            "INSERT INTO Client(passport_data, surname, client_name, patronymic, date_of_birth, place_of_birth, sex) "
            "VALUES (:passport_data, :surname, :client_name, :patronymic, :date_of_birth,:place_of_birth, :sex)");
    query.bindValue(":passport_data", *model->getPassportData());
    query.bindValue(":surname", *model->getSurname());
    query.bindValue(":client_name", *model->getName());
    query.bindValue(":patronymic", *model->getPatronymic());
    query.bindValue(":date_of_birth", *model->getDateOfBirth());
    query.bindValue(":place_of_birth", *model->getPlaceOfBirth());
    query.bindValue(":sex", model->isSex());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientDataBaseDAO::add() error", query.lastError().text()));
    }
}

void ClientDataBaseDAO::update(Client *model) {
    QSqlQuery query;
    query.prepare("UPDATE Client SET passport_data=:passport_data, surname=:surname, "
                  "client_name=:client_name, patronymic=:patronymic, date_of_birth=:date_of_birth, "
                  "place_of_birth=:place_of_birth, sex=:sex WHERE id=:id");
    query.bindValue(":passport_data", *model->getPassportData());
    query.bindValue(":surname", *model->getSurname());
    query.bindValue(":client_name", *model->getName());
    query.bindValue(":patronymic", *model->getPatronymic());
    query.bindValue(":date_of_birth", *model->getDateOfBirth());
    query.bindValue(":place_of_birth", *model->getPlaceOfBirth());
    query.bindValue(":sex", model->isSex());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientDataBaseDAO::update() error", query.lastError().text()));
    }
}

void ClientDataBaseDAO::del(Client *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Client WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Client *> ClientDataBaseDAO::getAllFilled() {
    return ClientDataBaseDAO::getAll();
}

