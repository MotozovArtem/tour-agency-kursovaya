//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_CLIENTDAO_H
#define PSQLWORK_CLIENTDAO_H


#include "ModelDAO.h"
#include "../Client.h"

class ClientDAO : public ModelDAO<Client *> {
public:
    virtual std::list<Client *> getAll() =0;

    virtual Client *getById(int id) =0;

    virtual void add(Client *model) =0;

    virtual void update(Client *model) =0;

    virtual void del(Client *model) =0;
};


#endif //PSQLWORK_CLIENTDAO_H
