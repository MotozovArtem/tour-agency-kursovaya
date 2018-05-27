//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_SIGHTDAO_H
#define PSQLWORK_SIGHTDAO_H

#include "ModelDAO.h"
#include "../Sight.h"

class SightDAO : public ModelDAO<Sight *> {
public:
    virtual QList<Sight *> getAll() =0;

    virtual Sight *getById(int id) =0;

    virtual void add(Sight *model) =0;

    virtual void update(Sight *model) =0;

    virtual void del(Sight *model) =0;

    virtual QList<Sight *> getAllFilled() =0;
};


#endif //PSQLWORK_SIGHTDAO_H
