//
// Created by rienel on 27.05.18.
//

#include "DocumentsDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<Documents *> DocumentsDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Documents *> list;
    if (query.exec("SELECT id, document_serial, date_of_issue, "
                   "issuance_department FROM Documents ORDER BY id")) {
        while (query.next()) {
            list << new Documents(
                    query.value("id").toInt(),
                    query.value("document_serial").toString(),
                    query.value("date_of_issue").toDate(),
                    query.value("issuance_department").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Documents *DocumentsDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, document_serial, date_of_issue, issuance_department "
                  "FROM Documents WHERE id=:id");
    query.bindValue(":id", id);
    Documents *documents = nullptr;
    if (query.exec()) {
        while (query.next()) {
            documents = new Documents(
                    query.value("id").toInt(),
                    query.value("document_serial").toString(),
                    query.value("date_of_issue").toDate(),
                    query.value("issuance_department").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsDataBaseDAO::getById() error", query.lastError().text()));
    }
    return documents;
}

void DocumentsDataBaseDAO::add(Documents *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO Documents(document_serial, date_of_issue, issuance_department) "
                  "VALUES (:document_serial, :date_of_issue, :issuance_department)");
    query.bindValue(":document_serial", *model->getSerial());
    query.bindValue(":date_of_issue", model->getDateOfIssue()->toString("dd.MM.yyyy"));
    query.bindValue(":issuance_department", *model->getIssuanceDepartment());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsDataBaseDAO::add() error", query.lastError().text()));
    }
}

void DocumentsDataBaseDAO::update(Documents *model) {
    QSqlQuery query;
    query.prepare("UPDATE Documents SET document_serial=:document_serial, date_of_issue=:date_of_issue, "
                  "issuance_department=:issuance_department WHERE id=:id");
    query.bindValue(":document_serial", *model->getSerial());
    query.bindValue(":date_of_issue", model->getDateOfIssue()->toString("dd.MM.yyyy"));
    query.bindValue(":issuance_department", *model->getIssuanceDepartment());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsDataBaseDAO::update() error", query.lastError().text()));
    }
}

void DocumentsDataBaseDAO::del(Documents *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Documents WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Documents *> DocumentsDataBaseDAO::getAllFilled() {
    return DocumentsDataBaseDAO::getAll();
}

