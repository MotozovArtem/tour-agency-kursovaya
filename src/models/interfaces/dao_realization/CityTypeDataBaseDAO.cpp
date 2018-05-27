//
// Created by rienel on 27.05.18.
//

#include "CityTypeDataBaseDAO.h"
#include "utils/Logger.h"
#include <QtSql/QtSql>

QList<CityType *> CityTypeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<CityType *> list;
    if (query.exec("SELECT id, city_type_name FROM CityType ORDER BY id")) {
        while (query.next()) {
            list << new CityType(
                    query.value("id").toInt(),
                    query.value("city_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityTypeDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

CityType *CityTypeDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, city_type_name FROM CityType WHERE id=:id");
    query.bindValue(":id", id);
    CityType *cityType = nullptr;
    if (query.exec()) {
        while (query.next()) {
            cityType = new CityType(
                    query.value("id").toInt(),
                    query.value("city_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityTypeDataBaseDAO::getById() error", query.lastError().text()));
    }
    return cityType;
}

void CityTypeDataBaseDAO::add(CityType *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO CityType(city_type_name) "
                  "VALUES (:city_type_name)");
    query.bindValue(":city_type_name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityTypeDataBaseDAO::add() error", query.lastError().text()));
    }
}

void CityTypeDataBaseDAO::update(CityType *model) {
    QSqlQuery query;
    query.prepare("UPDATE CityType SET city_type_name=:city_type_name WHERE id=:id");
    query.bindValue(":city_type_name", *model->getName());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityTypeDataBaseDAO::update() error", query.lastError().text()));
    }
}

void CityTypeDataBaseDAO::del(CityType *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM CityType WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityTypeDataBaseDAO::del() error", query.lastError().text()));
    }
}


QList<CityType *> CityTypeDataBaseDAO::getAllFilled() {
    return CityTypeDataBaseDAO::getAll();
}

