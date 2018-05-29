//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_RESERVATION_H
#define PSQLWORK_RESERVATION_H

#include "Model.h"
#include <QString>
#include <QDate>

class Reservation : public Model {
private:
    QDate *dateOfBegining;
    QDate *dateOfEnding;
    int idHotelRoom;
    int idContract;

    QString *hotelRoom;
    QString *contract;
public:
    static QStringList columnList;
    Reservation(QDate *dateOfBegining,QDate *dateOfEnding, int idHotelRoom,  int idContract);

    Reservation(const QDate &dateOfBegining, const QDate &dateOfEnding,int idHotelRoom,  int idContract);

    Reservation(int id, QDate *dateOfBegining, QDate *dateOfEnding,int idHotelRoom,  int idContract);

    Reservation(int id, const QDate &dateOfBegining,const QDate &dateOfEnding, int idHotelRoom,  int idContract);

    Reservation(int id);

    Reservation();

    QDate *getDateOfBegining() const;

    void setDateOfBegining(QDate *dateOfBegining);

    int getIdHotelRoom() const;

    void setIdHotelRoom(int idHotelRoom);

    QDate *getDateOfEnding() const;

    void setDateOfEnding(QDate *dateOfEnding);

    int getIdContract() const;

    void setIdContract(int idContract);

    virtual ~Reservation();

    QString *getHotelRoom() const;

    void setHotelRoom(QString *hotelRoom);

    QString *getContract() const;

    void setContract(QString *contract);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_RESERVATION_H
