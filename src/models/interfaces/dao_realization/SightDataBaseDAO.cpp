//
// Created by rienel on 27.05.18.
//

#include "SightDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<Sight *> SightDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Sight *> list;
    if (query.exec("SELECT id, sight_name, address, "
                   "year_of_foundation, toponym, id_city FROM Sight ORDER BY id")) {
        while (query.next()) {
            list << new Sight(
                    query.value("id").toInt(),
                    query.value("sight_name").toString(),
                    query.value("address").toString(),
                    query.value("year_of_foundation").toDate(),
                    query.value("toponym").toString(),
                    query.value("id_city").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("SightDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Sight *SightDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, sight_name, address, year_of_foundation, toponym, id_city "
                  "FROM Sight WHERE id=:id");
    query.bindValue(":id", id);
    Sight *sight = nullptr;
    if (query.exec()) {
        while (query.next()) {
            sight = new Sight(
                    query.value("id").toInt(),
                    query.value("sight_name").toString(),
                    query.value("address").toString(),
                    query.value("year_of_foundation").toDate(),
                    query.value("toponym").toString(),
                    query.value("id_city").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("SightDataBaseDAO::getById() error", query.lastError().text()));
    }
    return sight;
}

void SightDataBaseDAO::add(Sight *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Sight(sight_name, address, year_of_foundation, toponym, id_city) "
                  "VALUES (:sight_name, :address, :year_of_foundation, :toponym, :id_city)");
    query.bindValue(":sight_name", *model->getName());
    query.bindValue(":address", *model->getAddress());
    query.bindValue(":year_of_foundation", *model->getYearOfCreation());
    query.bindValue(":toponym", *model->getToponym());
    query.bindValue(":id_city", model->getIdCity());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("SightDataBaseDAO::add() error", query.lastError().text()));
    }
}

void SightDataBaseDAO::update(Sight *model) {
    QSqlQuery query;
    query.prepare("UPDATE Sight SET sight_name=:sight_name, address=:address, "
                  "year_of_foundation=:year_of_foundation, toponym=:toponym, id_city=:id_city WHERE id=:id");
    query.bindValue(":sight_name", *model->getName());
    query.bindValue(":address", *model->getAddress());
    query.bindValue(":year_of_foundation", *model->getYearOfCreation());
    query.bindValue(":toponym", *model->getToponym());
    query.bindValue(":id_city", model->getIdCity());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("SightDataBaseDAO::update() error", query.lastError().text()));
    }
}

void SightDataBaseDAO::del(Sight *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Sight WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("SightDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Sight *> SightDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<Sight *> list;
    if (query.exec("SELECT Sight.id, Sight.sight_name, Sight.address, "
                   "Sight.year_of_foundation, Sight.toponym, Sight.id_city, "
                   "City.city_name FROM Sight "
                   "LEFT JOIN City ON (Sight.id_city=City.id)"
                   "ORDER BY id")) {
        while (query.next()) {
            Sight *sight = new Sight(
                    query.value("id").toInt(),
                    query.value("sight_name").toString(),
                    query.value("address").toString(),
                    query.value("year_of_foundation").toDate(),
                    query.value("toponym").toString(),
                    query.value("id_city").toInt()
            );
            sight->setCity(new QString(query.value("city_name").toString()));
            list << sight;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("SightDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
