//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_CITYDAO_H
#define PSQLWORK_CITYDAO_H


#include "ModelDAO.h"
#include "../City.h"

class CityDAO : public ModelDAO<City *> {
public:
    virtual std::list<City *> getAll() =0;

    virtual City *getById(int id) =0;

    virtual void add(City *model) =0;

    virtual void update(City *model) =0;

    virtual void del(City *model) =0;
};


#endif //PSQLWORK_CITYDAO_H
