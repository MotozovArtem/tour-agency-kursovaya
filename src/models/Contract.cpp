//
// Created by rienel on 11.04.18.
//

#include "Contract.h"

Contract::Contract(int id, QString *name, QDate *dateOfPayment, QDate *dateOfIssue, float total, int idStatus,
                   int idTourType,
                   int idDocuments) : Model(id), name(name), dateOfPayment(dateOfPayment), dateOfIssue(dateOfIssue),
                                      total(total), idStatus(idStatus), idTourType(idTourType),
                                      idDocuments(idDocuments) {}

Contract::Contract(QString *name, QDate *dateOfPayment, QDate *dateOfIssue, float total, int idStatus, int idTourType,
                   int idDocuments) : name(name), dateOfPayment(dateOfPayment), dateOfIssue(dateOfIssue), total(total),
                                      idStatus(idStatus), idTourType(idTourType), idDocuments(idDocuments) {}

Contract::Contract(int id) : Model(id) {}

Contract::Contract() {}

Contract::~Contract() {
    delete this->name;
    delete this->dateOfIssue;
    delete this->dateOfPayment;
}

QString *Contract::getName() const {
    return name;
}

void Contract::setName(QString *name) {
    Contract::name = name;
}

QDate *Contract::getDateOfPayment() const {
    return dateOfPayment;
}

void Contract::setDateOfPayment(QDate *dateOfPayment) {
    Contract::dateOfPayment = dateOfPayment;
}

QDate *Contract::getDateOfIssue() const {
    return dateOfIssue;
}

void Contract::setDateOfIssue(QDate *dateOfIssue) {
    Contract::dateOfIssue = dateOfIssue;
}

float Contract::getTotal() const {
    return total;
}

void Contract::setTotal(float total) {
    Contract::total = total;
}

int Contract::getIdStatus() const {
    return idStatus;
}

void Contract::setIdStatus(int idStatus) {
    Contract::idStatus = idStatus;
}

int Contract::getIdTourType() const {
    return idTourType;
}

void Contract::setIdTourType(int idTourType) {
    Contract::idTourType = idTourType;
}

int Contract::getIdDocuments() const {
    return idDocuments;
}

void Contract::setIdDocuments(int idDocuments) {
    Contract::idDocuments = idDocuments;
}

Contract::Contract(int id, const QString &name, const QDate &dateOfPayment, const QDate &dateOfIssue, float total,
                   int idStatus, int idTourType, int idDocuments) : Model(id) {
    this->name = new QString(name);
    this->dateOfPayment = new QDate(dateOfPayment);
    this->dateOfIssue = new QDate(dateOfIssue);
    this->total = total;
    this->idStatus = idStatus;
    this->idTourType = idTourType;
    this->idDocuments = idDocuments;
}

Contract::Contract(const QString &name, const QDate &dateOfPayment, const QDate &dateOfIssue, float total, int idStatus,
                   int idTourType, int idDocuments) : Model() {
    this->name = new QString(name);
    this->dateOfPayment = new QDate(dateOfPayment);
    this->dateOfIssue = new QDate(dateOfIssue);
    this->total = total;
    this->idStatus = idStatus;
    this->idTourType = idTourType;
    this->idDocuments = idDocuments;
}
