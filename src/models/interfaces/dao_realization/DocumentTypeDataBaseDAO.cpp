//
// Created by rienel on 27.05.18.
//

#include "DocumentTypeDataBaseDAO.h"
#include "utils/Logger.h"
#include <QtSql/QtSql>

QList<DocumentType *> DocumentTypeDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<DocumentType *> list;
    if (query.exec("SELECT id, document_type_name FROM DocumentType ORDER BY id")) {
        while (query.next()) {
            list << new DocumentType(
                    query.value("id").toInt(),
                    query.value("document_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentTypeDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

DocumentType *DocumentTypeDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, document_type_name FROM DocumentType WHERE id=:id");
    query.bindValue(":id", id);
    DocumentType *documentType = nullptr;
    if (query.exec()) {
        while (query.next()) {
            documentType = new DocumentType(
                    query.value("id").toInt(),
                    query.value("document_type_name").toString()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentTypeDataBaseDAO::getById() error", query.lastError().text()));
    }
    return documentType;
}

void DocumentTypeDataBaseDAO::add(DocumentType *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO DocumentType(document_type_name) "
                  "VALUES (:document_type_name)");
    query.bindValue(":document_type_name", *model->getName());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentTypeDataBaseDAO::add() error", query.lastError().text()));
    }
}

void DocumentTypeDataBaseDAO::update(DocumentType *model) {
    QSqlQuery query;
    query.prepare("UPDATE DocumentType SET document_type_name=:document_type_name WHERE id=:id");
    query.bindValue(":document_type_name", *model->getName());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentTypeDataBaseDAO::update() error", query.lastError().text()));
    }
}

void DocumentTypeDataBaseDAO::del(DocumentType *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM DocumentType WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentTypeDataBaseDAO::del() error", query.lastError().text()));
    }
}


QList<DocumentType *> DocumentTypeDataBaseDAO::getAllFilled() {
    return DocumentTypeDataBaseDAO::getAll();
}
