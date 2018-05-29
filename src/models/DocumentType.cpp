//
// Created by rienel on 14.04.18.
//

#include "DocumentType.h"

DocumentType::DocumentType(int id, QString *name) : Model(id), documentTypeName(name) {}

DocumentType::DocumentType(QString *name) : documentTypeName(name) {}

DocumentType::DocumentType(int id) : Model(id) {}

DocumentType::DocumentType() {}

DocumentType::~DocumentType() {
    delete this->documentTypeName;
}

QString *DocumentType::getName() const {
    return documentTypeName;
}

void DocumentType::setName(QString *name) {
    DocumentType::documentTypeName = name;
}

DocumentType::DocumentType(int id, const QString &name) : Model(id) {
    this->documentTypeName = new QString(name);
}

DocumentType::DocumentType(const QString &name) : Model() {
    this->documentTypeName = new QString(name);
}

QStringList DocumentType::columnList = {"ID_i", "Name_s"};

QStringList *DocumentType::getValueList() {
    return new QStringList({QString::number(this->id), *this->documentTypeName});
}

QStringList *DocumentType::getValForAdd() {
    return getValueList();
}

DocumentType::DocumentType(const QStringList &args) : Model(args) {
    this->documentTypeName = new QString(args[1]);
}
