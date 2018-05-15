//
// Created by rienel on 15.05.18.
//

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include "CityDataBaseDAO.h"

QList<City *> CityDataBaseDAO::getAll() {
    QSqlQuery query;
    query.exec("SELECT * FROM City");
//    QSqlRecord rec = query.record();
    QList<City *> list;
    while (query.next()) {
        list << new City(
                query.value("id").toInt(),
                query.value("name").toString(),
                query.value("id_city_type").toInt(),
                query.value("id_country").toInt()
        );
    }
    return list;
}

City *CityDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM City WHERE id=:id");
    query.bindValue(":id", id);
    City *city = nullptr;
    if (query.exec()) {
        while (query.next()) {
            city = new City(
                    id,
                    query.value("name").toString(),
                    query.value("id_city_type").toInt(),
                    query.value("id_country").toInt()
            );
        }
    }
    return city;
}

void CityDataBaseDAO::add(City *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO City(name, id_city_type, id_country) VALUES"
                  "(:name, :id_city_type, :id_country)");
    query.bindValue(":name", *model->getName());
    query.bindValue(":id_city_type", model->getIdCityType());
    query.bindValue(":id_country", model->getIdCountry());
    if (query.exec()) {

    }
}

void CityDataBaseDAO::update(City *model) {
    QSqlQuery query;
    query.prepare("UPDATE City SET name=:name, id_city_type=:id_city_type, id_country=:id_country WHERE id=:id");
    query.bindValue(":name", *model->getName());
    query.bindValue(":id_city_type", model->getIdCityType());
    query.bindValue(":id_country", model->getIdCountry());
    query.bindValue(":id", model->getId());
    if (query.exec()) {

    }
}

void CityDataBaseDAO::del(City *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM City WHERE id=:id");
    query.bindValue(":id", model->getId());
    if(query.exec()){

    }
}
