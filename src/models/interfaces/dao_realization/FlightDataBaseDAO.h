//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_FLIGHTDATABASEDAO_H
#define PSQLWORK_FLIGHTDATABASEDAO_H


#include "interfaces/FlightDAO.h"

class FlightDataBaseDAO: public FlightDAO {
public:
    virtual QList<Flight *> getAll();

    virtual Flight *getById(int id);

    virtual void add(Flight *model);

    virtual void update(Flight *model);

    virtual void del(Flight *model);

    virtual QList<Flight *> getAllFilled();
};


#endif //PSQLWORK_FLIGHTDATABASEDAO_H
