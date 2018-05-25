//
// Created by rienel on 14.04.18.
//

#include "DocumentType.h"

DocumentType::DocumentType(int id, QString *name) : Model(id), name(name) {}

DocumentType::DocumentType(QString *name) : name(name) {}

DocumentType::DocumentType(int id) : Model(id) {}

DocumentType::DocumentType() {}

DocumentType::~DocumentType() {
    delete this->name;
}

QString *DocumentType::getName() const {
    return name;
}

void DocumentType::setName(QString *name) {
    DocumentType::name = name;
}

DocumentType::DocumentType(int id, const QString &name) : Model(id) {
    this->name = new QString(name);
}

DocumentType::DocumentType(const QString &name) : Model() {
    this->name = new QString(name);
}

QStringList DocumentType::columnList = {"ID", "Name"};