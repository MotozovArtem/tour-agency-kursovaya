//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_RESERVBYAGREEMENT_H
#define PSQLWORK_RESERVBYAGREEMENT_H

#include <QtCore>
#include "Model.h"


class ReservByAgreement : public Model {
private:
    QDate *dateOfBegining;
    int idHotelRoom;
    int idContract;

    QString *hotelRoom;
    QString *contract;
public:
    static QStringList columnList;
    ReservByAgreement(int id, QDate *dateOfBegining, int idHotelRoom, int idContract);

    ReservByAgreement(int id,const QDate &dateOfBegining, int idHotelRoom, int idContract);

    ReservByAgreement(QDate *dateOfBegining, int idHotelRoom, int idContract);

    ReservByAgreement(const QDate &dateOfBegining, int idHotelRoom, int idContract);

    ReservByAgreement(int id);

    ReservByAgreement();

    virtual ~ReservByAgreement();

    QDate *getDateOfBegining() const;

    void setDateOfBegining(QDate *dateOfBegining);

    int getIdHotelRoom() const;

    void setIdHotelRoom(int idHotelRoom);

    int getIdContract() const;

    void setIdContract(int idContract);

    virtual QStringList *getValueList();
};


#endif //PSQLWORK_RESERVBYAGREEMENT_H
