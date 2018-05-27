//
// Created by rienel on 27.05.18.
//

#include "TransportNodeDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<TransportNode *> TransportNodeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<TransportNode *> list;
    if (query.exec("SELECT id, node_name, id_flight, id_transport_node_type FROM TransportNode ORDER BY id")) {
        while (query.next()) {
            list << new TransportNode(
                    query.value("id").toInt(),
                    query.value("node_name").toString(),
                    query.value("id_flight").toInt(),
                    query.value("id_transport_node_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

TransportNode *TransportNodeDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, node_name, id_flight, id_transport_node_type  "
                  "FROM TransportNode WHERE id=:id");
    query.bindValue(":id", id);
    TransportNode *transportNode = nullptr;
    if (query.exec()) {
        while (query.next()) {
            transportNode = new TransportNode(
                    query.value("id").toInt(),
                    query.value("node_name").toString(),
                    query.value("id_flight").toInt(),
                    query.value("id_transport_node_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeDataBaseDAO::getById() error", query.lastError().text()));
    }
    return transportNode;
}

void TransportNodeDataBaseDAO::add(TransportNode *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO TransportNode(node_name, id_flight, id_transport_node_type) "
                  "VALUES (:node_name, :id_flight, :id_transport_node_type )");
    query.bindValue(":node_name", *model->getNodeName());
    query.bindValue(":id_flight", model->getIdFlight());
    query.bindValue(":id_transport_node_type", model->getIdTransportNodeType());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeDataBaseDAO::add() error", query.lastError().text()));
    }
}

void TransportNodeDataBaseDAO::update(TransportNode *model) {
    QSqlQuery query;
    query.prepare("UPDATE TransportNode SET node_name=:node_name, id_flight=:id_flight, "
                  "id_transport_node_type=:id_transport_node_type, toponym=:=:id_city WHERE id=:id");
    query.bindValue(":node_name", *model->getNodeName());
    query.bindValue(":id_flight", model->getIdFlight());
    query.bindValue(":id_transport_node_type", model->getIdTransportNodeType());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeDataBaseDAO::update() error", query.lastError().text()));
    }
}

void TransportNodeDataBaseDAO::del(TransportNode *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM TransportNode WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<TransportNode *> TransportNodeDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<TransportNode *> list;
    if (query.exec("SELECT TransportNode.id, TransportNode.node_name, TransportNode.id_flight, "
                   "TransportNodeType.transport_node_type_name FROM TransportNode "
                   "LEFT JOIN TransportNodeType ON (TransportNode.id_transport_node_type=TransportNodeType.id)"
                   "ORDER BY id")) {
        while (query.next()) {
            TransportNode *transportNode = new TransportNode(
                    query.value("id").toInt(),
                    query.value("node_name").toString(),
                    0,0
            );
            transportNode->setFlight(new QString(query.value("id_flight").toString()));
            transportNode->setTransportNodeType(new QString(query.value("transport_node_type_name").toString()));
            list << transportNode;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TransportNodeDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}

