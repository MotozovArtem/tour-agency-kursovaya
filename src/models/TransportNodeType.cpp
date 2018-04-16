//
// Created by rienel on 14.04.18.
//

#include "TransportNodeType.h"

TransportNodeType::TransportNodeType(int id, QString *name) : Model(id), name(name) {}

TransportNodeType::TransportNodeType(QString *name) : name(name) {}

TransportNodeType::TransportNodeType(int id) : Model(id) {}

TransportNodeType::TransportNodeType() {}

TransportNodeType::~TransportNodeType() {
    delete this->name;
}

QString *TransportNodeType::getName() const {
    return name;
}

void TransportNodeType::setName(QString *name) {
    TransportNodeType::name = name;
}