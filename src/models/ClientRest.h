//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CLIENTSREST_H
#define PSQLWORK_CLIENTSREST_H

#include <QtCore>
#include "Model.h"

class ClientRest: public Model {
private:
    int idContract;
    int idClient;

    QString *contract;
    QString *clientName;
public:
    static QStringList columnList;
    ClientRest(int id, int idContract, int idClient);

    ClientRest(int idContract, int idClient);

    ClientRest(int id);

    ClientRest();

    virtual ~ClientRest();

    int getIdContract() const;

    void setIdContract(int idContract);

    int getIdClient() const;

    void setIdClient(int idClient);

    QString *getContract() const;

    void setContract(QString *contract);

    QString *getClientName() const;

    void setClientName(QString *clientName);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_CLIENTSREST_H
