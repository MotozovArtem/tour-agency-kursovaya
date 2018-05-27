//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_TOURTYPEDATABASEDAO_H
#define PSQLWORK_TOURTYPEDATABASEDAO_H


#include "interfaces/TourTypeDAO.h"

class TourTypeDataBaseDAO: public TourTypeDAO {
public:
    virtual QList<TourType *> getAll();

    virtual TourType *getById(int id);

    virtual void add(TourType *model);

    virtual void update(TourType *model);

    virtual void del(TourType *model);

    virtual QList<TourType *> getAllFilled();
};


#endif //PSQLWORK_TOURTYPEDATABASEDAO_H
