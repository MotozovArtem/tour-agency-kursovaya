//
// Created by rienel on 11.04.18.
//

#include "Contract.h"

Contract::Contract(int id, QString *name, QDate *dateOfPayment, QDate *dateOfIssue, double total, int idStatus,
                   int idTourType,
                   int idDocuments) : Model(id), contractName(name), dateOfPayment(dateOfPayment),
                                      dateOfIssue(dateOfIssue),
                                      total(total), idStatus(idStatus), idTourType(idTourType),
                                      idDocuments(idDocuments) {
    this->docuements = nullptr;
    this->statusName = nullptr;
    this->tourTypeName = nullptr;
}

Contract::Contract(QString *name, QDate *dateOfPayment, QDate *dateOfIssue, double total, int idStatus, int idTourType,
                   int idDocuments) : contractName(name), dateOfPayment(dateOfPayment), dateOfIssue(dateOfIssue),
                                      total(total),
                                      idStatus(idStatus), idTourType(idTourType), idDocuments(idDocuments) {
    this->docuements = nullptr;
    this->statusName = nullptr;
    this->tourTypeName = nullptr;
}

Contract::Contract(int id) : Model(id) {
    this->docuements = nullptr;
    this->statusName = nullptr;
    this->tourTypeName = nullptr;
}

Contract::Contract() {
    this->docuements = nullptr;
    this->statusName = nullptr;
    this->tourTypeName = nullptr;
}

Contract::~Contract() {

    if(this->contractName!=nullptr){
        delete this->contractName;
        this->contractName=nullptr;
    }
    if(this->dateOfIssue!=nullptr){
        delete this->dateOfIssue;
        this->dateOfIssue=nullptr;
    }
    if(this->dateOfPayment!=nullptr){
        delete this->dateOfPayment;
        this->dateOfPayment=nullptr;
    }

    if (this->docuements != nullptr) {
        delete this->docuements;
        this->docuements = nullptr;
    }
    if (this->tourTypeName != nullptr) {
        delete this->tourTypeName;
        this->tourTypeName = nullptr;
    }
    if (this->statusName != nullptr) {
        delete this->statusName;
        this->statusName = nullptr;
    }
}

QString *Contract::getName() const {
    return contractName;
}

void Contract::setName(QString *name) {
    Contract::contractName = name;
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

double Contract::getTotal() const {
    return total;
}

void Contract::setTotal(double total) {
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

Contract::Contract(int id, const QString &name, const QDate &dateOfPayment, const QDate &dateOfIssue, double total,
                   int idStatus, int idTourType, int idDocuments) : Model(id) {
    this->contractName = new QString(name);
    this->dateOfPayment = new QDate(dateOfPayment);
    this->dateOfIssue = new QDate(dateOfIssue);
    this->total = total;
    this->idStatus = idStatus;
    this->idTourType = idTourType;
    this->idDocuments = idDocuments;
}

Contract::Contract(const QString &name, const QDate &dateOfPayment, const QDate &dateOfIssue, double total, int idStatus,
                   int idTourType, int idDocuments) : Model() {
    this->contractName = new QString(name);
    this->dateOfPayment = new QDate(dateOfPayment);
    this->dateOfIssue = new QDate(dateOfIssue);
    this->total = total;
    this->idStatus = idStatus;
    this->idTourType = idTourType;
    this->idDocuments = idDocuments;
}

QString *Contract::getStatusName() const {
    return statusName;
}

void Contract::setStatusName(QString *statusName) {
    Contract::statusName = statusName;
}

QString *Contract::getTourTypeName() const {
    return tourTypeName;
}

void Contract::setTourTypeName(QString *tourTypeName) {
    Contract::tourTypeName = tourTypeName;
}

QString *Contract::getDocuements() const {
    return docuements;
}

void Contract::setDocuements(QString *docuements) {
    Contract::docuements = docuements;
}

QStringList Contract::columnList = {"ID_i", "Name_s", "Date of payment_d", "Date of issue_d", "Total_n", "Status_f",
                                    "Tour type_f", "Documents_f"};

QStringList *Contract::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->contractName, this->dateOfPayment->toString("dd.MM.yyyy"),
             this->dateOfIssue->toString("dd.MM.yyyy"),
             QString::number(this->total), *this->statusName, *this->tourTypeName, *this->docuements});
}

QStringList *Contract::getValForAdd() {
    return new QStringList({QString::number(this->id), *this->contractName});
}

Contract::Contract(const QStringList &args) : Model(args) {
    this->contractName = new QString(args[1]);
    this->dateOfPayment = toDate(args[2]);
    this->dateOfIssue = toDate(args[3]);
    this->total = args[4].toDouble();
    this->idStatus = args[5].toInt();
    this->idTourType = args[6].toInt();
    this->idDocuments = args[7].toInt();

    this->docuements = nullptr;
    this->statusName = nullptr;
    this->tourTypeName = nullptr;
}
