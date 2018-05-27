//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_CLIENTSRESTDAO_H
#define PSQLWORK_CLIENTSRESTDAO_H

#include "ModelDAO.h"
#include "models/ClientRest.h"

class ClientsRestDAO : public ModelDAO<ClientRest *> {
public:
    virtual QList<ClientRest *> getAll() =0;

    virtual ClientRest *getById(int id) =0;

    virtual void add(ClientRest *model) =0;

    virtual void update(ClientRest *model) =0;

    virtual void del(ClientRest *model) =0;

    virtual QList<ClientRest *> getAllFilled() =0;
};


#endif //PSQLWORK_CLIENTSRESTDAO_H
