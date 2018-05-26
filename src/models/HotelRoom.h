//
// Created by rienel on 08.04.18.
//

#ifndef PSQLWORK_HOTELROOM_H
#define PSQLWORK_HOTELROOM_H

#include <QtCore>
#include "Model.h"

class HotelRoom: public Model {
private:
    QString* hotelRoomName;
    int places;
    bool shower;
    bool secondRestroom;
    bool balcony;
    int idHotel;
    int idHotelRoomType;

    QString *hotel;
    QString *hotelRoomType;
public:
    static QStringList columnList;
    HotelRoom(int id, QString *hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony, int idHotel,
              int idHotelRoomType);

    HotelRoom(QString *hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony, int idHotel,
              int idHotelRoomType);

    HotelRoom(const QString &hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony, int idHotel,
              int idHotelRoomType);

    HotelRoom(int id, const QString &hotelRoomName, int places, bool shower, bool secondRestroom, bool balcony, int idHotel,
              int idHotelRoomType);

    HotelRoom(int id);

    HotelRoom();

    virtual ~HotelRoom();

    QString *getHotelRoomName() const;

    void setHotelRoomName(QString *hotelRoomName);

    int getPlaces() const;

    void setPlaces(int places);

    bool isShower() const;

    void setShower(bool shower);

    bool isSecondRestroom() const;

    void setSecondRestroom(bool secondRestroom);

    bool isBalcony() const;

    void setBalcony(bool balcony);

    int getIdHotel() const;

    void setIdHotel(int idHotel);

    int getIdHotelRoomType() const;

    void setIdHotelRoomType(int idHotelRoomType);

    QString *getHotel() const;

    void setHotel(QString *hotel);

    QString *getHotelRoomType() const;

    void setHotelRoomType(QString *hotelRoomType);

    virtual QStringList *getValueList();
};


#endif //PSQLWORK_HOTELROOM_H
