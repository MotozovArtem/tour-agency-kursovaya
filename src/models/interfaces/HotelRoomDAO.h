//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_HOTELROOMDAO_H
#define PSQLWORK_HOTELROOMDAO_H

#include "ModelDAO.h"
#include "../HotelRoom.h"

class HotelRoomDAO : public ModelDAO<HotelRoom*> {
public:
    virtual std::list<HotelRoom*> getAll()=0;

    virtual HotelRoom* getById(int id)=0;

    virtual void add(HotelRoom *model)=0;

    virtual void update(HotelRoom *model)=0;

    virtual void del(HotelRoom *model)=0;
};


#endif //PSQLWORK_HOTELROOMDAO_H
