//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_RESERVATIONDAO_H
#define PSQLWORK_RESERVATIONDAO_H

#include "ModelDAO.h"
#include "../Reservation.h"

class ReservationDAO : public ModelDAO<Reservation *> {
public:
    virtual std::list<Reservation *> getAll() =0;

    virtual Reservation *getById(int id) =0;

    virtual void add(Reservation *model) =0;

    virtual void update(Reservation *model) =0;

    virtual void del(Reservation *model) =0;
};


#endif //PSQLWORK_RESERVATIONDAO_H
