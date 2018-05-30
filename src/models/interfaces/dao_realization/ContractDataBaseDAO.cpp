//
// Created by rienel on 27.05.18.
//

#include "ContractDataBaseDAO.h"
#include <QtSql/QtSql>
#include "utils/Logger.h"

QList<Contract *> ContractDataBaseDAO::getAll() {
    QSqlQuery query;
    QList<Contract *> list;
    if (query.exec("SELECT id, contract_name, date_of_payment, "
                   "date_of_issue, total, id_status, id_tour_type, id_documents FROM Contract ORDER BY id")) {
        while (query.next()) {
            list << new Contract(
                    query.value("id").toInt(),
                    query.value("contract_name").toString(),
                    query.value("date_of_payment").toDate(),
                    query.value("date_of_issue").toDate(),
                    query.value("total").toFloat(),
                    query.value("id_status").toInt(),
                    query.value("id_tour_type").toInt(),
                    query.value("id_documents").toInt()
            );
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ContractDataBaseDAO::getAll() error", query.lastError().text()));
    }
    return list;
}

Contract *ContractDataBaseDAO::getById(int id) {
    QSqlQuery query;
    query.prepare(
            "SELECT Contract.id, Contract.contract_name, Contract.date_of_payment, Contract.date_of_issue, "
            "Contract.total, Contract.id_status, Contract.id_tour_type, Contract.id_documents, "
            "Status.status_name, TourType.tour_type_name, Documents.document_serial"
            "FROM Contract "
            "LEFT JOIN Status ON (Contract.id_status=Status.id) "
            "LEFT JOIN TourType ON (Contract.id_tour_type=TourType.id) "
            "LEFT JOIN Documents ON (Contract.id_documents=Documents.id) "
            "WHERE Contract.id=:id");
    query.bindValue(":id", id);
    Contract *contract = nullptr;
    if (query.exec()) {
        while (query.next()) {
            contract = new Contract(
                    query.value("id").toInt(),
                    query.value("contract_name").toString(),
                    query.value("date_of_payment").toDate(),
                    query.value("date_of_issue").toDate(),
                    query.value("total").toFloat(),
                    query.value("id_status").toInt(),
                    query.value("id_tour_type").toInt(),
                    query.value("id_documents").toInt()
            );
            contract->setStatusName(new QString(query.value("status_name").toString()));
            contract->setTourTypeName(new QString(query.value("tour_type_name").toString()));
            contract->setDocuements(new QString(query.value("document_serial").toString()));
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ContractDataBaseDAO::getById() error", query.lastError().text()));
    }
    return contract;
}

void ContractDataBaseDAO::add(Contract *model) {
    QSqlQuery query;
    query.prepare(
            "INSERT INTO Contract(contract_name, date_of_payment, date_of_issue, total, id_status, id_tour_type, id_documents) "
            "VALUES (:contract_name, :date_of_payment, :date_of_issue, :total, :id_status, :id_tour_type, :id_documents)");
    query.bindValue(":contract_name", *model->getName());
    query.bindValue(":date_of_payment", *model->getDateOfPayment());
    query.bindValue(":date_of_issue", *model->getDateOfIssue());
    query.bindValue(":total", model->getTotal());
    query.bindValue(":id_status", model->getIdStatus());
    query.bindValue(":id_tour_type", model->getIdTourType());
    query.bindValue(":id_documents", model->getIdDocuments());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ContractDataBaseDAO::add() error", query.lastError().text()));
    }
}

void ContractDataBaseDAO::update(Contract *model) {
    QSqlQuery query;
    query.prepare("UPDATE Contract SET contract_name=:contract_name, date_of_payment=:date_of_payment, "
                  "date_of_issue=:date_of_issue, total=:total, id_status=:id_status, "
                  "id_tour_type=:id_tour_type, id_documents=:id_documents WHERE id=:id");
    query.bindValue(":contract_name", *model->getName());
    query.bindValue(":date_of_payment", *model->getDateOfPayment());
    query.bindValue(":date_of_issue", *model->getDateOfIssue());
    query.bindValue(":total", model->getTotal());
    query.bindValue(":id_status", model->getIdStatus());
    query.bindValue(":id_tour_type", model->getIdTourType());
    query.bindValue(":id_documents", model->getIdDocuments());
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ContractDataBaseDAO::update() error", query.lastError().text()));
    }
}

void ContractDataBaseDAO::del(Contract *model) {
    QSqlQuery query;
    query.prepare("DELETE FROM Contract WHERE id=:id");
    query.bindValue(":id", model->getId());
    if (!query.exec()) {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ContractDataBaseDAO::del() error", query.lastError().text()));
    }
}

QList<Contract *> ContractDataBaseDAO::getAllFilled() {
    QSqlQuery query;
    QList<Contract *> list;
    if (query.exec(
            "SELECT Contract.id, Contract.contract_name, Contract.date_of_payment, Contract.date_of_issue, "
            "Contract.total, Contract.id_status, Contract.id_tour_type, Contract.id_documents, "
            "Status.status_name, TourType.tour_type_name, Documents.document_serial FROM Contract "
            "LEFT JOIN Status ON (Contract.id_status=Status.id)"
            "LEFT JOIN TourType ON (Contract.id_tour_type=TourType.id)"
            "LEFT JOIN Documents ON (Contract.id_documents=Documents.id)"
            "ORDER BY id")) {
        while (query.next()) {
            Contract *contract = new Contract(
                    query.value("id").toInt(),
                    query.value("contract_name").toString(),
                    query.value("date_of_payment").toDate(),
                    query.value("date_of_issue").toDate(),
                    query.value("total").toFloat(),
                    query.value("id_status").toInt(),
                    query.value("id_tour_type").toInt(),
                    query.value("id_documents").toInt()
            );
            contract->setStatusName(new QString(query.value("status_name").toString()));
            contract->setTourTypeName(new QString(query.value("tour_type_name").toString()));
            contract->setDocuements(new QString(query.value("document_serial").toString()));
            list << contract;
        }
    } else {
        Logger logger(nullptr, "log.txt", nullptr);
        logger.write(QString("%1 %2").arg("ContractDataBaseDAO::getAllFilled() error", query.lastError().text()));
    }
    return list;
}
