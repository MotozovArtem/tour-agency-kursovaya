//
// Created by rienel on 11.04.18.
//

#include "ClientsRest.h"

ClientsRest::ClientsRest(int id, int idContract, int idClient) : Model(id), idContract(idContract),
                                                                 idClient(idClient) {}

ClientsRest::ClientsRest(int idContract, int idClient) : idContract(idContract), idClient(idClient) {}

ClientsRest::ClientsRest(int id) : Model(id) {}

ClientsRest::ClientsRest() {}

ClientsRest::~ClientsRest() {

}

int ClientsRest::getIdContract() const {
    return idContract;
}

void ClientsRest::setIdContract(int idContract) {
    ClientsRest::idContract = idContract;
}

int ClientsRest::getIdClient() const {
    return idClient;
}

void ClientsRest::setIdClient(int idClient) {
    ClientsRest::idClient = idClient;
}

QString *ClientsRest::getContract() const {
    return contract;
}

void ClientsRest::setContract(QString *contract) {
    ClientsRest::contract = contract;
}

QString *ClientsRest::getClientName() const {
    return clientName;
}

void ClientsRest::setClientName(QString *clientName) {
    ClientsRest::clientName = clientName;
}

QStringList ClientsRest::columnList = {"ID", "Contract_f", "Client_f"};

QStringList *ClientsRest::getValueList() {
    return new QStringList({QString::number(this->id), *this->contract, *this->clientName});
}
