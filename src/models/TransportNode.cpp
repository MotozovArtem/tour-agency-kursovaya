//
// Created by rienel on 14.04.18.
//

#include "TransportNode.h"

TransportNode::TransportNode(int id, QString *nodeName, int idFlight, int idTransportNodeType) :
        Model(id),
        transportNodeName(nodeName),
        idFlight(idFlight),
        idTransportNodeType(idTransportNodeType) {
    this->flight = nullptr;
    this->transportNodeType = nullptr;
}

TransportNode::TransportNode(QString *nodeName, int idFlight, int idTransportNodeType) :
        transportNodeName(nodeName),
        idFlight(idFlight),
        idTransportNodeType(idTransportNodeType) {
    this->flight = nullptr;
    this->transportNodeType = nullptr;
}

TransportNode::TransportNode(int id) : Model(id) {
    this->flight = nullptr;
    this->transportNodeType = nullptr;
}

TransportNode::TransportNode() {
    this->flight = nullptr;
    this->transportNodeType = nullptr;
}

TransportNode::TransportNode(int id, const QString &nodeName, int idFlight, int idTransportNodeType) : Model(id) {
    this->transportNodeName = new QString(nodeName);
    this->idFlight = idFlight;
    this->idTransportNodeType = idTransportNodeType;

    this->flight = nullptr;
    this->transportNodeType = nullptr;
}


TransportNode::TransportNode(const QString &nodeName, int idFlight, int idTransportNodeType) : Model() {
    this->transportNodeName = new QString(nodeName);
    this->idFlight = idFlight;
    this->idTransportNodeType = idTransportNodeType;

    this->flight = nullptr;
    this->transportNodeType = nullptr;
}

TransportNode::~TransportNode() {
    delete this->transportNodeName;

    if (this->flight != nullptr) {
        delete this->flight;
        this->flight = nullptr;
    }
    if (this->transportNodeType != nullptr) {
        delete this->transportNodeType;
        this->transportNodeType = nullptr;
    }
}

QString *TransportNode::getNodeName() const {
    return transportNodeName;
}

void TransportNode::setNodeName(QString *nodeName) {
    TransportNode::transportNodeName = nodeName;
}

int TransportNode::getIdFlight() const {
    return idFlight;
}

void TransportNode::setIdFlight(int idFlight) {
    TransportNode::idFlight = idFlight;
}

int TransportNode::getIdTransportNodeType() const {
    return idTransportNodeType;
}

void TransportNode::setIdTransportNodeType(int idTransportNodeType) {
    TransportNode::idTransportNodeType = idTransportNodeType;
}

QString *TransportNode::getFlight() const {
    return flight;
}

void TransportNode::setFlight(QString *flight) {
    TransportNode::flight = flight;
}

QString *TransportNode::getTransportNodeType() const {
    return transportNodeType;
}

void TransportNode::setTransportNodeType(QString *transportNodeType) {
    TransportNode::transportNodeType = transportNodeType;
}

QStringList TransportNode::columnList = {"ID_i", "Node name_s", "Flight_f", "Transport Node Type_f"};

QStringList *TransportNode::getValueList() {
    return new QStringList(
            {QString::number(this->id), *this->transportNodeName, *this->flight, *this->transportNodeType});
}

QStringList *TransportNode::getValForAdd() {
    return new QStringList(
            {QString::number(this->id), *this->transportNodeName, *this->transportNodeType});
}
