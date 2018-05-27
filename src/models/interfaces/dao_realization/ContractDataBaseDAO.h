//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_CONTRACTDATABASEDAO_H
#define PSQLWORK_CONTRACTDATABASEDAO_H

#include "interfaces/ContractDAO.h"

class ContractDataBaseDAO: public ContractDAO {
public:
    virtual QList<Contract *> getAll();

    virtual Contract *getById(int id);

    virtual void add(Contract *model);

    virtual void update(Contract *model);

    virtual void del(Contract *model);

    virtual QList<Contract *> getAllFilled();
};


#endif //PSQLWORK_CONTRACTDATABASEDAO_H
