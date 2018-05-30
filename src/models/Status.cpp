//
// Created by rienel on 25.05.18.
//

#include "Status.h"

Status::Status(int id, QString *name) : Model(id), statusName(name) {}

Status::Status(QString *name) : statusName(name) {}

Status::Status(int id, const QString &name) : Model(id) {
    this->statusName = new QString(name);
}

Status::Status(const QString &name) : Model() {
    this->statusName = new QString(name);
}

Status::Status(int id) : Model(id) {}

Status::Status() {}

Status::~Status() {
    if(this->statusName!=nullptr){
        delete this->statusName;
        this->statusName=nullptr;
    }
}

QString *Status::getName() const {
    return statusName;
}

void Status::setName(QString *name) {
    Status::statusName = name;
}

QStringList Status::columnList = {"ID_i", "Name_s"};

QStringList *Status::getValueList() {
    return new QStringList({QString::number(this->id), *this->statusName});
}

QStringList *Status::getValForAdd() {
    return getValueList();
}

Status::Status(const QStringList &args) : Model(args) {
    this->statusName = new QString(args[1]);
}
