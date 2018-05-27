//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_COUNTRYDATABASEDAO_H
#define PSQLWORK_COUNTRYDATABASEDAO_H

#include "interfaces/CountryDAO.h"


class CountryDataBaseDAO: public CountryDAO {
public:
    virtual QList<Country *> getAll();

    virtual Country *getById(int id);

    virtual void add(Country *model);

    virtual void update(Country *model);

    virtual void del(Country *model);

    virtual QList<Country *> getAllFilled();
};


#endif //PSQLWORK_COUNTRYDATABASEDAO_H
