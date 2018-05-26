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
    int idHotelRoom;
    QDate *dateOfEnding;
    int idContract;

    QString *hotelRoom;
    QString *contract;
public:
    static QStringList columnList;
    Reservation(QDate *dateOfBegining, int idHotelRoom, QDate *dateOfEnding, int idContract);

    Reservation(const QDate &dateOfBegining, int idHotelRoom, const QDate &dateOfEnding, int idContract);

    Reservation(int id, QDate *dateOfBegining, int idHotelRoom, QDate *dateOfEnding, int idContract);

    Reservation(int id, const QDate &dateOfBegining, int idHotelRoom, const QDate &dateOfEnding, int idContract);

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
};


#endif //PSQLWORK_RESERVATION_H
