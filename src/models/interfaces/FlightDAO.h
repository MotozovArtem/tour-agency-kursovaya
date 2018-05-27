//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_FLIGHTDAO_H
#define PSQLWORK_FLIGHTDAO_H

#include "ModelDAO.h"
#include "../Flight.h"

class FlightDAO : public ModelDAO<Flight *> {
public:
    virtual QList<Flight *> getAll() =0;

    virtual Flight *getById(int id) =0;

    virtual void add(Flight *model) =0;

    virtual void update(Flight *model) =0;

    virtual void del(Flight *model) =0;

    virtual QList<Flight *> getAllFilled() =0;
};


#endif //PSQLWORK_FLIGHTDAO_H
