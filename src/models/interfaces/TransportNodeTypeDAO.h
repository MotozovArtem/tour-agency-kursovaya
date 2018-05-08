//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_TRANSPORTNODETYPEDAO_H
#define PSQLWORK_TRANSPORTNODETYPEDAO_H

#include "ModelDAO.h"
#include "../TransportNodeType.h"

class TransportNodeTypeDAO : public ModelDAO<TransportNodeType *> {
public:
    virtual QList<TransportNodeType *> getAll() =0;

    virtual TransportNodeType *getById(int id) =0;

    virtual void add(TransportNodeType *model) =0;

    virtual void update(TransportNodeType *model) =0;

    virtual void del(TransportNodeType *model) =0;
};


#endif //PSQLWORK_TRANSPORTNODETYPEDAO_H
