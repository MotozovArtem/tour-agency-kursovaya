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
public:
    ClientsRest(int id, int idContract, int idClient);

    ClientsRest(int idContract, int idClient);

    ClientsRest(int id);

    ClientsRest();

    virtual ~ClientsRest();

    int getIdContract() const;

    void setIdContract(int idContract);

    int getIdClient() const;

    void setIdClient(int idClient);
};


#endif //PSQLWORK_CLIENTSREST_H
