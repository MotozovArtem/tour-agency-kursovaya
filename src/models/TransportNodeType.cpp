//
// Created by rienel on 14.04.18.
//

#include "TransportNodeType.h"

TransportNodeType::TransportNodeType(int id, QString *name) : Model(id), transportNodeTypeName(name) {}

TransportNodeType::TransportNodeType(QString *name) : transportNodeTypeName(name) {}

TransportNodeType::TransportNodeType(int id) : Model(id) {}

TransportNodeType::TransportNodeType() {}

TransportNodeType::~TransportNodeType() {
    if(this->transportNodeTypeName!=nullptr){
        delete this->transportNodeTypeName;
        this->transportNodeTypeName=nullptr;
    }
}

QString *TransportNodeType::getName() const {
    return transportNodeTypeName;
}

void TransportNodeType::setName(QString *name) {
    TransportNodeType::transportNodeTypeName = name;
}

TransportNodeType::TransportNodeType(int id, const QString &name) : Model(id) {
    this->transportNodeTypeName = new QString(name);
}

TransportNodeType::TransportNodeType(const QString &name) : Model() {
    this->transportNodeTypeName = new QString(name);
}

QStringList TransportNodeType::columnList = {"ID_i", "Name_s"};

QStringList *TransportNodeType::getValueList() {
    return new QStringList({QString::number(this->id), *this->transportNodeTypeName});
}

QStringList *TransportNodeType::getValForAdd() {
    return getValueList();
}

TransportNodeType::TransportNodeType(const QStringList &args) : Model(args) {
    this->transportNodeTypeName = new QString(args[1]);
}
