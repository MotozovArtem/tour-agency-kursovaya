//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_CLIENTSRESTDAO_H
#define PSQLWORK_CLIENTSRESTDAO_H

#include "ModelDAO.h"
#include "../ClientsRest.h"

class ClientsRestDAO : public ModelDAO<ClientsRest *> {
public:
    virtual QList<ClientsRest *> getAll() =0;

    virtual ClientsRest *getById(int id) =0;

    virtual void add(ClientsRest *model) =0;

    virtual void update(ClientsRest *model) =0;

    virtual void del(ClientsRest *model) =0;
};


#endif //PSQLWORK_CLIENTSRESTDAO_H
