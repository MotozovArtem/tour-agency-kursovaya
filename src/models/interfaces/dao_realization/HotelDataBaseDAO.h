//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_HOTELDATABASEDAO_H
#define PSQLWORK_HOTELDATABASEDAO_H


#include "../HotelDAO.h"

class HotelDataBaseDAO : public HotelDAO {
public:
    virtual std::list<Hotel *> getAll();

    virtual Hotel *getById(int id);

    virtual void add(Hotel *model);

    virtual void update(Hotel *model);

    virtual void del(Hotel *model);
};


#endif //PSQLWORK_HOTELDATABASEDAO_H
