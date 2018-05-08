//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_PLACEARRIVALTYPEDAO_H
#define PSQLWORK_PLACEARRIVALTYPEDAO_H


#include "ModelDAO.h"
#include "../PlaceArrivalType.h"

class PlaceArrivalTypeDAO : public ModelDAO<PlaceArrivalType *> {
public:
    virtual QList<PlaceArrivalType *> getAll() =0;

    virtual PlaceArrivalType *getById(int id) =0;

    virtual void add(PlaceArrivalType *model) =0;

    virtual void update(PlaceArrivalType *model) =0;

    virtual void del(PlaceArrivalType *model) =0;
};


#endif //PSQLWORK_PLACEARRIVALTYPEDAO_H
