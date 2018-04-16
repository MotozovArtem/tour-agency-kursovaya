//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_PLACEARRIVALDAO_H
#define PSQLWORK_PLACEARRIVALDAO_H

#include "ModelDAO.h"
#include "../PlaceArrival.h"

class PlaceArrivalDAO : public ModelDAO<PlaceArrival *> {
public:
    virtual std::list<PlaceArrival *> getAll() =0;

    virtual PlaceArrival *getById(int id) =0;

    virtual void add(PlaceArrival *model) =0;

    virtual void update(PlaceArrival *model) =0;

    virtual void del(PlaceArrival *model) =0;
};


#endif //PSQLWORK_PLACEARRIVALDAO_H
