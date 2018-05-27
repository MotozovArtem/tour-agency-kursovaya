//
// Created by rienel on 26.05.18.
//

#ifndef PSQLWORK_HOTELROOMDATABASEDAO_H
#define PSQLWORK_HOTELROOMDATABASEDAO_H

#include "interfaces/HotelRoomDAO.h"

class HotelRoomDataBaseDAO: public HotelRoomDAO {
public:
    virtual QList<HotelRoom *> getAll();

    virtual HotelRoom *getById(int id);

    virtual void add(HotelRoom *model);

    virtual void update(HotelRoom *model);

    virtual void del(HotelRoom *model);

    virtual QList<HotelRoom *> getAllFilled();
};


#endif //PSQLWORK_HOTELROOMDATABASEDAO_H
