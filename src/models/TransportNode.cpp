//
// Created by rienel on 14.04.18.
//

#include "TransportNode.h"

TransportNode::TransportNode(int id, QDate *dateOfPurchase, int idFlight, QString *nodeName, int idTransportNodeType)
        : Model(id), dateOfPurchase(dateOfPurchase), idFlight(idFlight), nodeName(nodeName),
          idTransportNodeType(idTransportNodeType) {}

TransportNode::TransportNode(QDate *dateOfPurchase, int idFlight, QString *nodeName, int idTransportNodeType)
        : dateOfPurchase(dateOfPurchase), idFlight(idFlight), nodeName(nodeName),
          idTransportNodeType(idTransportNodeType) {}

TransportNode::TransportNode(int id) : Model(id) {}

TransportNode::TransportNode() {}

TransportNode::~TransportNode() {
    delete this->dateOfPurchase;
    delete this->nodeName;
}

QDate *TransportNode::getDateOfPurchase() const {
    return dateOfPurchase;
}

void TransportNode::setDateOfPurchase(QDate *dateOfPurchase) {
    TransportNode::dateOfPurchase = dateOfPurchase;
}

int TransportNode::getIdFlight() const {
    return idFlight;
}

void TransportNode::setIdFlight(int idFlight) {
    TransportNode::idFlight = idFlight;
}

QString *TransportNode::getNodeName() const {
    return nodeName;
}

void TransportNode::setNodeName(QString *nodeName) {
    TransportNode::nodeName = nodeName;
}

int TransportNode::getIdTransportNodeType() const {
    return idTransportNodeType;
}

void TransportNode::setIdTransportNodeType(int idTransportNodeType) {
    TransportNode::idTransportNodeType = idTransportNodeType;
}
