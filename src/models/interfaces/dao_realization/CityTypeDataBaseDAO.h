//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_CITYTYPEDATABASEDAO_H
#define PSQLWORK_CITYTYPEDATABASEDAO_H


#include "interfaces/CityTypeDAO.h"

class CityTypeDataBaseDAO: public CityTypeDAO {
public:
    virtual QList<CityType *> getAll();

    virtual CityType *getById(int id);

    virtual void add(CityType *model);

    virtual void update(CityType *model);

    virtual void del(CityType *model);

    virtual QList<CityType *> getAllFilled();
};


#endif //PSQLWORK_CITYTYPEDATABASEDAO_H
