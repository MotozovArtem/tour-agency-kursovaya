//
// Created by rienel on 14.04.18.
//

#include "Documents.h"

Documents::Documents(int id, QString *serial, QDate *dateOfIssue, QDate *issuanceDepartment) : Model(id),
                                                                                               serial(serial),
                                                                                               dateOfIssue(dateOfIssue),
                                                                                               issuanceDepartment(
                                                                                                       issuanceDepartment) {}

Documents::Documents(QString *serial, QDate *dateOfIssue, QDate *issuanceDepartment) : serial(serial),
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

QDate *Documents::getIssuanceDepartment() const {
    return issuanceDepartment;
}

void Documents::setIssuanceDepartment(QDate *issuanceDepartment) {
    Documents::issuanceDepartment = issuanceDepartment;
}
