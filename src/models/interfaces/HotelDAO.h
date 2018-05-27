//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_HOTELDAO_H
#define PSQLWORK_HOTELDAO_H

#include "ModelDAO.h"
#include "../Hotel.h"

class HotelDAO : public ModelDAO<Hotel *> {
public:
    QList<Hotel *> getAll() =0;

    Hotel *getById(int id) =0;

    void add(Hotel *model) =0;

    void update(Hotel *model) =0;

    void del(Hotel *model) =0;

    virtual QList<Hotel *> getAllFilled() =0;
};


#endif //PSQLWORK_HOTELDAO_H
