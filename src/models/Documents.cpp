//
// Created by rienel on 14.04.18.
//

#include "Documents.h"

Documents::Documents(int id, QString *serial, QDate *dateOfIssue, QString *issuanceDepartment) : Model(id),
                                                                                                 serial(serial),
                                                                                                 dateOfIssue(
                                                                                                         dateOfIssue),
                                                                                                 issuanceDepartment(
                                                                                                         issuanceDepartment) {}

Documents::Documents(QString *serial, QDate *dateOfIssue, QString *issuanceDepartment) : serial(serial),
                                                                                         dateOfIssue(dateOfIssue),
                                                                                         issuanceDepartment(
                                                                                                 issuanceDepartment) {}

Documents::Documents(int id) : Model(id) {}

Documents::Documents() {}

Documents::~Documents() {
    delete this->dateOfIssue;
    delete this->issuanceDepartment;
    delete this->serial;
}

QString *Documents::getSerial() const {
    return serial;
}

void Documents::setSerial(QString *serial) {
    Documents::serial = serial;
}

QDate *Documents::getDateOfIssue() const {
    return dateOfIssue;
}

void Documents::setDateOfIssue(QDate *dateOfIssue) {
    Documents::dateOfIssue = dateOfIssue;
}

QString *Documents::getIssuanceDepartment() const {
    return issuanceDepartment;
}

void Documents::setIssuanceDepartment(QString *issuanceDepartment) {
    Documents::issuanceDepartment = issuanceDepartment;
}

Documents::Documents(int id, const QString &serial, const QDate &dateOfIssue, const QString &issuanceDepartment)
        : Model(
        id) {
    this->serial = new QString(serial);
    this->dateOfIssue = new QDate(dateOfIssue);
    this->issuanceDepartment = new QString(issuanceDepartment);
}
