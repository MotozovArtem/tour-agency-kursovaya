//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_CLIENTRESTDATABASEDAO_H
#define PSQLWORK_CLIENTRESTDATABASEDAO_H


#include "interfaces/ClientsRestDAO.h"

class ClientRestDataBaseDAO: public ClientsRestDAO {
public:
    virtual QList<ClientRest *> getAll();

    virtual ClientRest *getById(int id);

    virtual void add(ClientRest *model);

    virtual void update(ClientRest *model);

    virtual void del(ClientRest *model);

    virtual QList<ClientRest *> getAllFilled();
};


#endif //PSQLWORK_CLIENTRESTDATABASEDAO_H
