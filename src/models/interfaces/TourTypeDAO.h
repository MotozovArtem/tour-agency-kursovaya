//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_TOURTYPEDAO_H
#define PSQLWORK_TOURTYPEDAO_H

#include "ModelDAO.h"
#include "../TourType.h"


class TourTypeDAO : public ModelDAO<TourType *> {
public:
    virtual QList<TourType *> getAll() =0;

    virtual TourType *getById(int id) =0;

    virtual void add(TourType *model) =0;

    virtual void update(TourType *model) =0;

    virtual void del(TourType *model) =0;

};


#endif //PSQLWORK_TOURTYPEDAO_H
