//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_CLIENTDATABASEDAO_H
#define PSQLWORK_CLIENTDATABASEDAO_H

#include "interfaces/ClientDAO.h"

class ClientDataBaseDAO: public ClientDAO {
public:
    virtual QList<Client *> getAll();

    virtual Client *getById(int id);

    virtual void add(Client *model);

    virtual void update(Client *model);

    virtual void del(Client *model);

    virtual QList<Client *> getAllFilled();
};


#endif //PSQLWORK_CLIENTDATABASEDAO_H
