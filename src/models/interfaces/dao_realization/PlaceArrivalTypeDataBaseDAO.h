//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_PLACEARRIVALTYPEDATABASEDAO_H
#define PSQLWORK_PLACEARRIVALTYPEDATABASEDAO_H

#include "interfaces/PlaceArrivalTypeDAO.h"

class PlaceArrivalTypeDataBaseDAO: public PlaceArrivalTypeDAO {
public:
    virtual QList<PlaceArrivalType *> getAll();

    virtual PlaceArrivalType *getById(int id);

    virtual void add(PlaceArrivalType *model);

    virtual void update(PlaceArrivalType *model);

    virtual void del(PlaceArrivalType *model);

    virtual QList<PlaceArrivalType *> getAllFilled();
};


#endif //PSQLWORK_PLACEARRIVALTYPEDATABASEDAO_H
