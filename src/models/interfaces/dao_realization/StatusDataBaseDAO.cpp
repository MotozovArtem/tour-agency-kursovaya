//
// Created by rienel on 27.05.18.
//

#include "StatusDataBaseDAO.h"
#include "utils/Logger.h"
#include <QtSql/QtSql>

QList<Status *> StatusDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Status *> list;
    if (query.exec("SELECT id, status_name FROM Status ORDER BY id")) {
        while (query.next()) {
            list << new Status(
                    query.value("id").toInt(),
                    query.value("status_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("StatusDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Status *StatusDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, status_name FROM Status WHERE id=:id");
    query.bindValue(":id", id);
    Status *tourType = nullptr;
    if (query.exec()) {
        while (query.next()) {
            tourType = new Status(
                    query.value("id").toInt(),
                    query.value("status_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("StatusDataBaseDAO::getById() error", query.lastError().text()));
    }
    return tourType;
}

void StatusDataBaseDAO::add(Status *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Status(status_name) "
                  "VALUES (:status_name)");
    query.bindValue(":status_name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("StatusDataBaseDAO::add() error", query.lastError().text()));
    }
}

void StatusDataBaseDAO::update(Status *model) {
    QSqlQuery query;
    query.prepare("UPDATE Status SET status_name=:status_name WHERE id=:id");
    query.bindValue(":status_name", *model->getName());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("StatusDataBaseDAO::update() error", query.lastError().text()));
    }
}

void StatusDataBaseDAO::del(Status *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Status WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("StatusDataBaseDAO::del() error", query.lastError().text()));
    }
}


QList<Status *> StatusDataBaseDAO::getAllFilled() {
    return StatusDataBaseDAO::getAll();
}
