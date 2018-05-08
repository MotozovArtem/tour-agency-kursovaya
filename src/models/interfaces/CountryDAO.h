//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_COUNTRYDAO_H
#define PSQLWORK_COUNTRYDAO_H

#include "ModelDAO.h"
#include "../Country.h"

class CountryDAO : public ModelDAO<Country *> {
public:
    virtual QList<Country *> getAll() =0;

    virtual Country *getById(int id) =0;

    virtual void add(Country *model) =0;

    virtual void update(Country *model) =0;

    virtual void del(Country *model) =0;
};


#endif //PSQLWORK_COUNTRYDAO_H
