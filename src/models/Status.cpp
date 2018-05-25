//
// Created by rienel on 25.05.18.
//

#include "Status.h"

Status::Status(int id, QString *name) : Model(id), name(name) {}

Status::Status(QString *name) : name(name) {}

Status::Status(int id, QString &name) : Model(id) {
    this->name = new QString(name);
}

Status::Status(QString &name) : {
    this->name = new QString(name);
}

Status::Status(int id) : Model(id) {}

Status::Status() {}

Status::~Status() {
    delete this->name;
}

QString *Status::getName() const {
    return name;
}

void Status::setName(QString *name) {
    Status::name = name;
}

QStringList Status::columnList = {"ID", "Name"};