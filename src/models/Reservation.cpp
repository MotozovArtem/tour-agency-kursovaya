//
// Created by rienel on 11.04.18.
//

#include "Reservation.h"

Reservation::Reservation(int id, QDate *dateOfBegining, int idHotelRoom, QDate *dateOfEnding, int idContract) : Model(
        id), dateOfBegining(dateOfBegining), idHotelRoom(idHotelRoom), dateOfEnding(dateOfEnding), idContract(
        idContract) {}

Reservation::Reservation(QDate *dateOfBegining, int idHotelRoom, QDate *dateOfEnding, int idContract) : dateOfBegining(
        dateOfBegining), idHotelRoom(idHotelRoom), dateOfEnding(dateOfEnding), idContract(idContract) {}

Reservation::Reservation(int id) : Model(id) {}

Reservation::Reservation() {}

Reservation::~Reservation() {
    delete this->dateOfBegining;
    delete this->dateOfEnding;
}

QDate *Reservation::getDateOfBegining() const {
    return dateOfBegining;
}

void Reservation::setDateOfBegining(QDate *dateOfBegining) {
    Reservation::dateOfBegining = dateOfBegining;
}

int Reservation::getIdHotelRoom() const {
    return idHotelRoom;
}

void Reservation::setIdHotelRoom(int idHotelRoom) {
    Reservation::idHotelRoom = idHotelRoom;
}

QDate *Reservation::getDateOfEnding() const {
    return dateOfEnding;
}

void Reservation::setDateOfEnding(QDate *dateOfEnding) {
    Reservation::dateOfEnding = dateOfEnding;
}

int Reservation::getIdContract() const {
    return idContract;
}

void Reservation::setIdContract(int idContract) {
    Reservation::idContract = idContract;
}
