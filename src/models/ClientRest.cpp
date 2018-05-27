//
// Created by rienel on 11.04.18.
//

#include "ClientRest.h"

ClientRest::ClientRest(int id, int idContract, int idClient) : Model(id), idContract(idContract),
                                                                 idClient(idClient) {}

ClientRest::ClientRest(int idContract, int idClient) : idContract(idContract), idClient(idClient) {}

ClientRest::ClientRest(int id) : Model(id) {}

ClientRest::ClientRest() {}

ClientRest::~ClientRest() {

}

int ClientRest::getIdContract() const {
    return idContract;
}

void ClientRest::setIdContract(int idContract) {
    ClientRest::idContract = idContract;
}

int ClientRest::getIdClient() const {
    return idClient;
}

void ClientRest::setIdClient(int idClient) {
    ClientRest::idClient = idClient;
}

QString *ClientRest::getContract() const {
    return contract;
}

void ClientRest::setContract(QString *contract) {
    ClientRest::contract = contract;
}

QString *ClientRest::getClientName() const {
    return clientName;
}

void ClientRest::setClientName(QString *clientName) {
    ClientRest::clientName = clientName;
}

QStringList ClientRest::columnList = {"ID", "Contract_f", "Client_f"};

QStringList *ClientRest::getValueList() {
    return new QStringList({QString::number(this->id), *this->contract, *this->clientName});
}
