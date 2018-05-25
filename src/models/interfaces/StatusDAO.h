//
// Created by rienel on 25.05.18.
//

#ifndef PSQLWORK_STATUSDAO_H
#define PSQLWORK_STATUSDAO_H

#include "models/interfaces/ModelDAO.h"
#include "models/Status.h"

class StatusDAO : public ModelDAO<Status *> {
public:
    virtual QList<Status *> getAll() =0;

    virtual Status *getById(int id) =0;

    virtual void add(Status *model) =0;

    virtual void update(Status *model) =0;

    virtual void del(Status *model) =0;
};

#endif //PSQLWORK_STATUSDAO_H
