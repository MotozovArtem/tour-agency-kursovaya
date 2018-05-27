//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_SIGHTDATABASEDAO_H
#define PSQLWORK_SIGHTDATABASEDAO_H

#include "interfaces/SightDAO.h"


class SightDataBaseDAO: SightDAO {
    virtual QList<Sight *> getAll();

    virtual Sight *getById(int id);

    virtual void add(Sight *model);

    virtual void update(Sight *model);

    virtual void del(Sight *model);

    virtual QList<Sight *> getAllFilled();
};


#endif //PSQLWORK_SIGHTDATABASEDAO_H
