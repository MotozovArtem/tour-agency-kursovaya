//
// Created by rienel on 27.05.18.
//

#include "ClientRestDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<ClientRest *> ClientRestDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<ClientRest *> list;
    if (query.exec("SELECT id, id_contract, id_client FROM ClientRest ORDER BY id")) {
        while (query.next()) {
            list << new ClientRest(
                    query.value("id").toInt(),
                    query.value("id_contract").toInt(),
                    query.value("id_client").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientRestDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

ClientRest *ClientRestDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, id_contract, id_client,  "
                  "FROM ClientRest WHERE id=:id");
    query.bindValue(":id", id);
    ClientRest *client = nullptr;
    if (query.exec()) {
        while (query.next()) {
            client = new ClientRest(
                    query.value("id").toInt(),
                    query.value("id_contract").toInt(),
                    query.value("id_client").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientRestDataBaseDAO::getById() error", query.lastError().text()));
    }
    return client;
}

void ClientRestDataBaseDAO::add(ClientRest *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO ClientRest(id_contract, id_client, ) "
                  "VALUES (:id_contract, :id_client, :year_of_foundation, :toponym, :id_city)");
    query.bindValue(":id_contract", model->getIdContract());
    query.bindValue(":id_client", model->getIdClient());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientRestDataBaseDAO::add() error", query.lastError().text()));
    }
}

void ClientRestDataBaseDAO::update(ClientRest *model) {
    QSqlQuery query;
    query.prepare("UPDATE ClientRest SET id_contract=:id_contract, id_client=:id_client, "
                  "year_of_foundation=:year_of_foundation, toponym=:toponym, id_city=:id_city WHERE id=:id");
    query.bindValue(":id_contract", model->getIdContract());
    query.bindValue(":id_client", model->getIdClient());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientRestDataBaseDAO::update() error", query.lastError().text()));
    }
}

void ClientRestDataBaseDAO::del(ClientRest *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM ClientRest WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientRestDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<ClientRest *> ClientRestDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<ClientRest *> list;
    if (query.exec("SELECT ClientRest.id, ClientRest.id_contract, ClientRest.id_client, "
                   "Contract.contract_name, Client.surname FROM ClientRest "
                   "LEFT JOIN Contract ON (ClientRest.id_city=Contract.id) "
                   "LEFT JOIN Client ON (ClientRest.id_city=Client.id) "
                   "ORDER BY id")) {
        while (query.next()) {
            ClientRest *client = new ClientRest(
                    query.value("id").toInt(),
                    query.value("id_contract").toInt(),
                    query.value("id_client").toInt()
            );
            client->setContract(new QString(query.value("contract_name").toString()));
            client->setClientName(new QString(query.value("surname").toString()));
            list << client;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ClientRestDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
