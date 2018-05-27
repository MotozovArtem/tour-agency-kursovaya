//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_TRANSPORTNODEDATABASEDAO_H
#define PSQLWORK_TRANSPORTNODEDATABASEDAO_H

#include "interfaces/TransportNodeDAO.h"


class TransportNodeDataBaseDAO: public TransportNodeDAO {
public:
    virtual QList<TransportNode *> getAll();

    virtual TransportNode *getById(int id);

    virtual void add(TransportNode *model);

    virtual void update(TransportNode *model);

    virtual void del(TransportNode *model);

    virtual QList<TransportNode *> getAllFilled();
};


#endif //PSQLWORK_TRANSPORTNODEDATABASEDAO_H
