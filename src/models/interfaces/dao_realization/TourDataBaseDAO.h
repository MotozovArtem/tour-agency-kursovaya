//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_TOURDATABASEDAO_H
#define PSQLWORK_TOURDATABASEDAO_H


#include "interfaces/TourDAO.h"

class TourDataBaseDAO: public TourDAO {
public:
    virtual QList<Tour *> getAll();

    virtual Tour *getById(int id);

    virtual void add(Tour *model);

    virtual void update(Tour *model);

    virtual void del(Tour *model);

    virtual QList<Tour *> getAllFilled();

};


#endif //PSQLWORK_TOURDATABASEDAO_H
