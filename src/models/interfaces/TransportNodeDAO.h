//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_TRANSPORTNODEDAO_H
#define PSQLWORK_TRANSPORTNODEDAO_H

#include "ModelDAO.h"
#include "../TransportNode.h"

class TransportNodeDAO : public ModelDAO<TransportNode *> {
public:
    virtual QList<TransportNode *> getAll() =0;

    virtual TransportNode *getById(int id) =0;

    virtual void add(TransportNode *model) =0;

    virtual void update(TransportNode *model) =0;

    virtual void del(TransportNode *model) =0;

    virtual QList<TransportNode *> getAllFilled() =0;
};


#endif //PSQLWORK_TRANSPORTNODEDAO_H
