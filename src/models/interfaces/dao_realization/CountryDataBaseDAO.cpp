//
// Created by rienel on 27.05.18.
//

#include "CountryDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<Country *> CountryDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Country *> list;
    if (query.exec("SELECT id, country_name, foundation_date FROM Country ORDER BY id")) {
        while (query.next()) {
            list << new Country(
                    query.value("id").toInt(),
                    query.value("country_name").toString(),
                    query.value("foundation_date").toDate()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CountryDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Country *CountryDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, country_name FROM Country WHERE id=:id");
    query.bindValue(":id", id);
    Country *country = nullptr;
    if (query.exec()) {
        while (query.next()) {
            country = new Country(
                    query.value("id").toInt(),
                    query.value("country_name").toString(),
                    query.value("foundation_date").toDate()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CountryDataBaseDAO::getById() error", query.lastError().text()));
    }
    return country;
}

void CountryDataBaseDAO::add(Country *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Country(country_name, foundation_date) "
                  "VALUES (:country_name, :foundation_date)");
    query.bindValue(":country_name", *model->getName());
    query.bindValue(":foundation_date", model->getFoundationDate()->toString("dd.MM.yyyy"));
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CountryDataBaseDAO::add() error", query.lastError().text()));
    }
}

void CountryDataBaseDAO::update(Country *model) {
    QSqlQuery query;
    query.prepare("UPDATE Country SET country_name=:country_name, foundation_date=:foundation_date WHERE id=:id");
    query.bindValue(":country_name", *model->getName());
    query.bindValue(":foundation_date", model->getFoundationDate()->toString("dd.MM.yyyy"));
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CountryDataBaseDAO::update() error", query.lastError().text()));
    }
}

void CountryDataBaseDAO::del(Country *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Country WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("CountryDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Country *> CountryDataBaseDAO::getAllFilled() {
    return CountryDataBaseDAO::getAll();
}
