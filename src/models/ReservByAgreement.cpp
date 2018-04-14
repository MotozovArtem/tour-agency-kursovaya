//
// Created by rienel on 14.04.18.
//

#include "ReservByAgreement.h"

ReservByAgreement::ReservByAgreement(int id, QDate *dateOfBegining, int idHotelRoom, int idContract) : Model(id),
                                                                                                       dateOfBegining(
                                                                                                               dateOfBegining),
                                                                                                       idHotelRoom(
                                                                                                               idHotelRoom),
                                                                                                       idContract(
                                                                                                               idContract) {}

ReservByAgreement::ReservByAgreement(QDate *dateOfBegining, int idHotelRoom, int idContract) : dateOfBegining(
        dateOfBegining), idHotelRoom(idHotelRoom), idContract(idContract) {}

ReservByAgreement::ReservByAgreement(int id) : Model(id) {}

ReservByAgreement::ReservByAgreement() {}

ReservByAgreement::~ReservByAgreement() {
    delete this->dateOfBegining;
}

QDate *ReservByAgreement::getDateOfBegining() const {
    return dateOfBegining;
}

void ReservByAgreement::setDateOfBegining(QDate *dateOfBegining) {
    ReservByAgreement::dateOfBegining = dateOfBegining;
}

int ReservByAgreement::getIdHotelRoom() const {
    return idHotelRoom;
}

void ReservByAgreement::setIdHotelRoom(int idHotelRoom) {
    ReservByAgreement::idHotelRoom = idHotelRoom;
}

int ReservByAgreement::getIdContract() const {
    return idContract;
}

void ReservByAgreement::setIdContract(int idContract) {
    ReservByAgreement::idContract = idContract;
}
