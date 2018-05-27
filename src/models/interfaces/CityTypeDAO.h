//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_CITYTYPEDAO_H
#define PSQLWORK_CITYTYPEDAO_H

#include "ModelDAO.h"
#include "../CityType.h"


class CityTypeDAO : public ModelDAO<CityType *> {
public:
    virtual QList<CityType *> getAll() =0;

    virtual CityType *getById(int id) =0;

    virtual void add(CityType *model) =0;

    virtual void update(CityType *model) =0;

    virtual void del(CityType *model) =0;

    virtual QList<CityType *> getAllFilled() =0;
};


#endif //PSQLWORK_CITYTYPEDAO_H
