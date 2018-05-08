//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_CONTRACTDAO_H
#define PSQLWORK_CONTRACTDAO_H

#include "ModelDAO.h"
#include "../Contract.h"

class ContractDAO : public ModelDAO<Contract *> {
public:
    virtual QList<Contract *> getAll() =0;

    virtual Contract *getById(int id) =0;

    virtual void add(Contract *model) =0;

    virtual void update(Contract *model) =0;

    virtual void del(Contract *model) =0;
};


#endif //PSQLWORK_CONTRACTDAO_H
