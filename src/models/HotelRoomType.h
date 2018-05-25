//
// Created by rienel on 08.04.18.
//

#ifndef PSQLWORK_HOTELROOMTYPE_H
#define PSQLWORK_HOTELROOMTYPE_H

#include "Model.h"
#include <QtCore>

class HotelRoomType : public Model {
private:
    QString *name;
public:
    static QStringList columnList;
    
    HotelRoomType(int id, QString *name);

    HotelRoomType(int id, const QString &name);

    HotelRoomType(QString *name);

    HotelRoomType(const QString &name);

    HotelRoomType(int id);

    HotelRoomType();

    virtual ~HotelRoomType();

    QString *getName() const;

    void setName(QString *name);
};


#endif //PSQLWORK_HOTELROOMTYPE_H
