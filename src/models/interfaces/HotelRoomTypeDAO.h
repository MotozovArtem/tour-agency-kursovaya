//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_HOTELROOMTYPEDAO_H
#define PSQLWORK_HOTELROOMTYPEDAO_H

#include "ModelDAO.h"
#include "../HotelRoomType.h"

class HotelRoomTypeDAO : public ModelDAO<HotelRoomType*> {
public:
    QList<HotelRoomType*> getAll() =0;

    HotelRoomType* getById(int id) =0;

    void add(HotelRoomType* model) =0;

    void update(HotelRoomType* model) =0;

    void del(HotelRoomType *model) =0;
};

#endif //PSQLWORK_HOTELROOMTYPEDAO_H
