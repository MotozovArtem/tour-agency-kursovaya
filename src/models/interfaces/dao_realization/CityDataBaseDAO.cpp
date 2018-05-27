//
// Created by rienel on 15.05.18.
//

#include <QtSql/QtSql>
#include <utils/Logger.h>
#include "CityDataBaseDAO.h"

QList<City *> CityDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<City *> list;
    if (query.exec("SELECT id, city_name, id_city_type, id_country FROM City ORDER BY id")) {
        while (query.next()) {
            list << new City(
                    query.value("id").toInt(),
                    query.value("city_name").toString(),
                    query.value("id_city_type").toInt(),
                    query.value("id_country").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityDataBaseDAO::getAll error", query.lastError().text()));
    }
    return list;
}

City *CityDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, city_name, id_city_type, id_country FROM City WHERE id=:id");
    query.bindValue(":id", id);
    City *city = nullptr;
    if (query.exec()) {
        while (query.next()) {
            city = new City(
                    id,
                    query.value("city_name").toString(),
                    query.value("id_city_type").toInt(),
                    query.value("id_country").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityDataBaseDAO::getById error", query.lastError().text()));
    }
    return city;
}

void CityDataBaseDAO::add(City *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO City(city_name, id_city_type, id_country) VALUES"
                  "(:city_name, :id_city_type, :id_country)");
    query.bindValue(":cityName", *model->getName());
    query.bindValue(":id_city_type", model->getIdCityType());
    query.bindValue(":id_country", model->getIdCountry());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityDataBaseDAO::add() error", query.lastError().text()));
    }
}

void CityDataBaseDAO::update(City *model) {
    QSqlQuery query;
    query.prepare(
            "UPDATE City SET cityName=:city_name, id_city_type=:id_city_type, id_country=:id_country WHERE id=:id");
    query.bindValue(":city_name", *model->getName());
    query.bindValue(":id_city_type", model->getIdCityType());
    query.bindValue(":id_country", model->getIdCountry());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityDataBaseDAO::update error", query.lastError().text()));
    }
}

void CityDataBaseDAO::del(City *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM City WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityDataBaseDAO::del error", query.lastError().text()));
    }
}

QList<City *> CityDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<City *> list;
    if (query.exec("SELECT City.id, City.city_name, Country.country_name, "
                   "City.id_city_type, City.id_country, CityType.city_type_name FROM City "
                   "LEFT JOIN Country ON (City.id_country=Country.id) "
                   "LEFT JOIN CityType ON (City.id_city_type=CityType.id)"
                   "ORDER BY id")) {
        while (query.next()) {
            City *city = new City(
                    query.value("id").toInt(),
                    query.value("city_name").toString(),
                    query.value("id_city_type").toInt(),
                    query.value("id_country").toInt()
            );
            city->setCountryName(new QString(query.value("country_name").toString()));
            city->setCityTypeName(new QString(query.value("city_type_name").toString()));
            list << city;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CityDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
