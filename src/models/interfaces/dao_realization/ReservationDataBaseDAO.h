//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_RESERVATIONDATABASEDAO_H
#define PSQLWORK_RESERVATIONDATABASEDAO_H


#include "interfaces/ReservationDAO.h"

class ReservationDataBaseDAO: public ReservationDAO {
public:
    virtual QList<Reservation *> getAll();

    virtual Reservation *getById(int id);

    virtual void add(Reservation *model);

    virtual void update(Reservation *model);

    virtual void del(Reservation *model);

    virtual QList<Reservation *> getAllFilled();

};


#endif //PSQLWORK_RESERVATIONDATABASEDAO_H
