//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_TRANSPORTNODETYPEDATABASEDAO_H
#define PSQLWORK_TRANSPORTNODETYPEDATABASEDAO_H

#include "interfaces/TransportNodeTypeDAO.h"


class TransportNodeTypeDataBaseDAO: public TransportNodeTypeDAO {
public:
    virtual QList<TransportNodeType *> getAll();

    virtual TransportNodeType *getById(int id);

    virtual void add(TransportNodeType *model);

    virtual void update(TransportNodeType *model);

    virtual void del(TransportNodeType *model);

    virtual QList<TransportNodeType *> getAllFilled();
};


#endif //PSQLWORK_TRANSPORTNODETYPEDATABASEDAO_H
