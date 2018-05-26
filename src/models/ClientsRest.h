//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CLIENTSREST_H
#define PSQLWORK_CLIENTSREST_H

#include <QtCore>
#include "Model.h"

class ClientsRest: public Model {
private:
    int idContract;
    int idClient;

    QString *contract;
    QString *clientName;
public:
    static QStringList columnList;
    ClientsRest(int id, int idContract, int idClient);

    ClientsRest(int idContract, int idClient);

    ClientsRest(int id);

    ClientsRest();

    virtual ~ClientsRest();

    int getIdContract() const;

    void setIdContract(int idContract);

    int getIdClient() const;

    void setIdClient(int idClient);

    QString *getContract() const;

    void setContract(QString *contract);

    QString *getClientName() const;

    void setClientName(QString *clientName);

    virtual QStringList *getValueList();
};


#endif //PSQLWORK_CLIENTSREST_H
