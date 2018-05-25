//
// Created by rienel on 14.04.18.
//

#include "TransportNode.h"

TransportNode::TransportNode(int id, QString *nodeName, int idFlight, int idTransportNodeType) : Model(id),
                                                                                                 nodeName(nodeName),
                                                                                                 idFlight(idFlight),
                                                                                                 idTransportNodeType(
                                                                                                         idTransportNodeType) {}

TransportNode::TransportNode(QString *nodeName, int idFlight, int idTransportNodeType) : nodeName(nodeName),
                                                                                         idFlight(idFlight),
                                                                                         idTransportNodeType(
                                                                                                 idTransportNodeType) {}

TransportNode::TransportNode(int id) : Model(id) {}

TransportNode::TransportNode() {}

TransportNode::TransportNode(int id, const QString &nodeName, int idFlight, int idTransportNodeType) : Model(id) {
    this->nodeName = new QString(nodeName);
    this->idFlight = idFlight;
    this->idTransportNodeType = idTransportNodeType;
}

TransportNode::TransportNode(const QString &nodeName, int idFlight, int idTransportNodeType) : Model() {
    this->nodeName = new QString(nodeName);
    this->idFlight = idFlight;
    this->idTransportNodeType = idTransportNodeType;
}

QString *TransportNode::getNodeName() const {
    return nodeName;
}

void TransportNode::setNodeName(QString *nodeName) {
    TransportNode::nodeName = nodeName;
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

QStringList TransportNode::columnList = {"ID", "Node name", "Flight_f", "Transport Node Type_f"};