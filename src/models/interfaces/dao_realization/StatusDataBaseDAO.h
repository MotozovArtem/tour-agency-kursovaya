//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_STATUSDATABASEDAO_H
#define PSQLWORK_STATUSDATABASEDAO_H

#include "interfaces/StatusDAO.h"

class StatusDataBaseDAO: public StatusDAO {
public:
    virtual QList<Status *> getAll();

    virtual Status *getById(int id);

    virtual void add(Status *model);

    virtual void update(Status *model);

    virtual void del(Status *model);

    virtual QList<Status *> getAllFilled();
};


#endif //PSQLWORK_STATUSDATABASEDAO_H
