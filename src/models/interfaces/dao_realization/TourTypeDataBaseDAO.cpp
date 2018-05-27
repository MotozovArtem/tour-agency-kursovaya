//
// Created by rienel on 27.05.18.
//

#include "TourTypeDataBaseDAO.h"
#include "utils/Logger.h"
#include <QtSql/QtSql>

QList<TourType *> TourTypeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<TourType *> list;
    if (query.exec("SELECT id, tour_type_name FROM TourType ORDER BY id")) {
        while (query.next()) {
            list << new TourType(
                    query.value("id").toInt(),
                    query.value("tour_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourTypeDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

TourType *TourTypeDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, tour_type_name FROM TourType WHERE id=:id");
    query.bindValue(":id", id);
    TourType *tourType = nullptr;
    if (query.exec()) {
        while (query.next()) {
            tourType = new TourType(
                    query.value("id").toInt(),
                    query.value("tour_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourTypeDataBaseDAO::getById() error", query.lastError().text()));
    }
    return tourType;
}

void TourTypeDataBaseDAO::add(TourType *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO TourType(tour_type_name) "
                  "VALUES (:tour_type_name)");
    query.bindValue(":tour_type_name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourTypeDataBaseDAO::add() error", query.lastError().text()));
    }
}

void TourTypeDataBaseDAO::update(TourType *model) {
    QSqlQuery query;
    query.prepare("UPDATE TourType SET tour_type_name=:tour_type_name WHERE id=:id");
    query.bindValue(":tour_type_name", *model->getName());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourTypeDataBaseDAO::update() error", query.lastError().text()));
    }
}

void TourTypeDataBaseDAO::del(TourType *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM TourType WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("TourTypeDataBaseDAO::del() error", query.lastError().text()));
    }
}


QList<TourType *> TourTypeDataBaseDAO::getAllFilled() {
    return TourTypeDataBaseDAO::getAll();
}
