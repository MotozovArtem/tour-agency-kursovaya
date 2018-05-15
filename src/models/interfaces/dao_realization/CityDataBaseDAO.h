//
// Created by rienel on 15.05.18.
//

#ifndef PSQLWORK_CITYDATABASEDAO_H
#define PSQLWORK_CITYDATABASEDAO_H

#include "../CityDAO.h"

class CityDataBaseDAO : public CityDAO {
public:
    virtual QList<City *> getAll();

    virtual City *getById(int id);

    virtual void add(City *model);

    virtual void update(City *model);

    virtual void del(City *model);
};


#endif //PSQLWORK_CITYDATABASEDAO_H
