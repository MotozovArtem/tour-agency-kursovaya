//
// Created by rienel on 27.05.18.
//

#include "TransportNodeTypeDataBaseDAO.h"
#include "utils/Logger.h"
#include <QtSql/QtSql>

QList<TransportNodeType *> TransportNodeTypeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<TransportNodeType *> list;
    if (query.exec("SELECT id, transport_node_type_name FROM TransportNodeType ORDER BY id")) {
        while (query.next()) {
            list << new TransportNodeType(
                    query.value("id").toInt(),
                    query.value("transport_node_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeTypeDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

TransportNodeType *TransportNodeTypeDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, transport_node_type_name FROM TransportNodeType WHERE id=:id");
    query.bindValue(":id", id);
    TransportNodeType *transportNodeType = nullptr;
    if (query.exec()) {
        while (query.next()) {
            transportNodeType = new TransportNodeType(
                    query.value("id").toInt(),
                    query.value("transport_node_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeTypeDataBaseDAO::getById() error", query.lastError().text()));
    }
    return transportNodeType;
}

void TransportNodeTypeDataBaseDAO::add(TransportNodeType *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO TransportNodeType(transport_node_type_name) "
                  "VALUES (:transport_node_type_name)");
    query.bindValue(":transport_node_type_name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeTypeDataBaseDAO::add() error", query.lastError().text()));
    }
}

void TransportNodeTypeDataBaseDAO::update(TransportNodeType *model) {
    QSqlQuery query;
    query.prepare("UPDATE TransportNodeType SET transport_node_type_name=:transport_node_type_name WHERE id=:id");
    query.bindValue(":transport_node_type_name", *model->getName());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeTypeDataBaseDAO::update() error", query.lastError().text()));
    }
}

void TransportNodeTypeDataBaseDAO::del(TransportNodeType *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM TransportNodeType WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeTypeDataBaseDAO::del() error", query.lastError().text()));
    }
}


QList<TransportNodeType *> TransportNodeTypeDataBaseDAO::getAllFilled() {
    return TransportNodeTypeDataBaseDAO::getAll();
}

