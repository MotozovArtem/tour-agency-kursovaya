//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_PLACEARRIVALDATABASEDAO_H
#define PSQLWORK_PLACEARRIVALDATABASEDAO_H

#include "interfaces/PlaceArrivalDAO.h"


class PlaceArrivalDataBaseDAO: public PlaceArrivalDAO {
public:
    virtual QList<PlaceArrival *> getAll();

    virtual PlaceArrival *getById(int id);

    virtual void add(PlaceArrival *model);

    virtual void update(PlaceArrival *model);

    virtual void del(PlaceArrival *model);

    virtual QList<PlaceArrival *> getAllFilled();
};


#endif //PSQLWORK_PLACEARRIVALDATABASEDAO_H
