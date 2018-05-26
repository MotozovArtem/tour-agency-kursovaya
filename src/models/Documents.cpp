//
// Created by rienel on 14.04.18.
//

#include "Documents.h"

Documents::Documents(int id, QString *serial, QDate *dateOfIssue, QString *issuanceDepartment) : Model(id),
                                                                                                 documentSerial(
                                                                                                         serial),
                                                                                                 dateOfIssue(
                                                                                                         dateOfIssue),
                                                                                                 issuanceDepartment(
                                                                                                         issuanceDepartment) {}

Documents::Documents(QString *serial, QDate *dateOfIssue, QString *issuanceDepartment) : documentSerial(serial),
                                                                                         dateOfIssue(dateOfIssue),
                                                                                         issuanceDepartment(
                                                                                                 issuanceDepartment) {}

Documents::Documents(int id) : Model(id) {}

Documents::Documents() {}

Documents::~Documents() {
    delete this->dateOfIssue;
    delete this->issuanceDepartment;
    delete this->documentSerial;
}

QString *Documents::getSerial() const {
    return documentSerial;
}

void Documents::setSerial(QString *serial) {
    Documents::documentSerial = serial;
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

Documents::Documents(int id, const QString &documentSerial, const QDate &dateOfIssue,
                     const QString &issuanceDepartment)
        : Model(id) {

}

Documents::Documents(const QString &documentSerial, const QDate &dateOfIssue, const QString &issuanceDepartment) {
    this->documentSerial = new QString(documentSerial);
    this->dateOfIssue = new QDate(dateOfIssue);
    this->issuanceDepartment = new QString(issuanceDepartment);
}

QStringList Documents::columnList = {"ID", "Serial", "Date of issue", "Issuance department"};

QStringList *Documents::getValueList() {
    return new QStringList({QString::number(this->id), *this->documentSerial, this->dateOfIssue->toString(),
                            *this->issuanceDepartment});
}
