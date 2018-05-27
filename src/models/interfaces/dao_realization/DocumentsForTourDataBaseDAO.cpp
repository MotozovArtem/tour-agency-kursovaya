//
// Created by rienel on 27.05.18.
//

#include "DocumentsForTourDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<DocumentsForTour *> DocumentsForTourDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<DocumentsForTour *> list;
    if (query.exec("SELECT id, id_document, id_client, id_document_type FROM DocumentsForTour ORDER BY id")) {
        while (query.next()) {
            list << new DocumentsForTour(
                    query.value("id").toInt(),
                    query.value("id_document").toInt(),
                    query.value("id_client").toInt(),
                    query.value("id_document_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsForTourDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

DocumentsForTour *DocumentsForTourDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, id_document, id_client, id_document_type "
                  "FROM DocumentsForTour WHERE id=:id");
    query.bindValue(":id", id);
    DocumentsForTour *documentsForTour = nullptr;
    if (query.exec()) {
        while (query.next()) {
            documentsForTour = new DocumentsForTour(
                    query.value("id").toInt(),
                    query.value("id_document").toInt(),
                    query.value("id_client").toInt(),
                    query.value("id_document_type").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsForTourDataBaseDAO::getById() error", query.lastError().text()));
    }
    return documentsForTour;
}

void DocumentsForTourDataBaseDAO::add(DocumentsForTour *model) {
    QSqlQuery query;
    query.prepare("INSERT INTO DocumentsForTour(id_document, id_client, id_document_type) "
                  "VALUES (:id_document, :id_client, :id_document_type)");
    query.bindValue(":id_document", model->getIdDocument());
    query.bindValue(":id_client", model->getIdClient());
    query.bindValue(":id_document_type", model->getIdDocumentType());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsForTourDataBaseDAO::add() error", query.lastError().text()));
    }
}

void DocumentsForTourDataBaseDAO::update(DocumentsForTour *model) {
    QSqlQuery query;
    query.prepare("UPDATE DocumentsForTour SET id_document=:id_document, id_client=:id_client, "
                  "id_document_type=:id_document_type WHERE id=:id");
    query.bindValue(":id_document", model->getIdDocument());
    query.bindValue(":id_client", model->getIdClient());
    query.bindValue(":id_document_type", model->getIdDocumentType());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsForTourDataBaseDAO::update() error", query.lastError().text()));
    }
}

void DocumentsForTourDataBaseDAO::del(DocumentsForTour *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM DocumentsForTour WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("DocumentsForTourDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<DocumentsForTour *> DocumentsForTourDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<DocumentsForTour *> list;
    if (query.exec(
            "SELECT DocumentsForTour.id, DocumentsForTour.id_document, DocumentsForTour.id_client, DocumentsForTour.id_document_type,"
            "Documents.document_serial, Client.surname, DocumentType.document_type_name"
            "FROM DocumentsForTour "
            "LEFT JOIN Documents ON (DocumentsForTour.id_documents=Documents.id)"
            "LEFT JOIN Client ON (DocumentsForTour.id_client=Client.id)"
            "LEFT JOIN DocumentType ON (DocumentsForTour.id_document_type=DocumentType.id)"
            "ORDER BY id")) {
        while (query.next()) {
            DocumentsForTour *documentsForTour = new DocumentsForTour(
                    query.value("id").toInt(),
                    query.value("id_document").toInt(),
                    query.value("id_client").toInt(),
                    query.value("id_document_type").toInt()
            );
            documentsForTour->setDocument(new QString(query.value("document_serial").toString()));
            documentsForTour->setClientName(new QString(query.value("surname").toString()));
            documentsForTour->setDocumentType(new QString(query.value("document_type_name").toString()));
            list << documentsForTour;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(
                QString("%1 %2").arg("DocumentsForTourDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
