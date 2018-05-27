//
// Created by rienel on 16.05.18.
//

#ifndef PSQLWORK_HOTELROOMTYPEDATABASEDAO_H
#define PSQLWORK_HOTELROOMTYPEDATABASEDAO_H


#include <models/interfaces/HotelRoomTypeDAO.h>

class HotelRoomTypeDataBaseDAO: public HotelRoomTypeDAO {
public:
    virtual QList<HotelRoomType *> getAll();

    virtual HotelRoomType *getById(int id);

    virtual void add(HotelRoomType *model);

    virtual void update(HotelRoomType *model);

    virtual void del(HotelRoomType *model);

    virtual QList<HotelRoomType *> getAllFilled();
};


#endif //PSQLWORK_HOTELROOMTYPEDATABASEDAO_H
