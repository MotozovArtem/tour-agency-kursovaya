//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_RESERVATION_H
#define PSQLWORK_RESERVATION_H

#include "Model.h"
#include <QtCore>

class Reservation : public Model {
private:
    QDate *dateOfBegining;
    int idHotelRoom;
    QDate *dateOfEnding;
    int idContract;
public:
    Reservation(QDate *dateOfBegining, int idHotelRoom, QDate *dateOfEnding, int idContract);

    Reservation(int id, QDate *dateOfBegining, int idHotelRoom, QDate *dateOfEnding, int idContract);

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
};


#endif //PSQLWORK_RESERVATION_H
