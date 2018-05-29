//
// Created by rienel on 14.04.18.
//

#include "ReservByAgreement.h"

ReservByAgreement::ReservByAgreement(int id, QDate *dateOfBegining, int idHotelRoom, int idContract) :
        Model(id),
        dateOfBegining(dateOfBegining),
        idHotelRoom(idHotelRoom),
        idContract(idContract) {
    this->contract = nullptr;
    this->hotelRoom = nullptr;
}

ReservByAgreement::ReservByAgreement(QDate *dateOfBegining, int idHotelRoom, int idContract) : dateOfBegining(
        dateOfBegining), idHotelRoom(idHotelRoom), idContract(idContract) {
    this->contract = nullptr;
    this->hotelRoom = nullptr;
}

ReservByAgreement::ReservByAgreement(int id) : Model(id) {
    this->contract = nullptr;
    this->hotelRoom = nullptr;
}

ReservByAgreement::ReservByAgreement() {
    this->contract = nullptr;
    this->hotelRoom = nullptr;
}

ReservByAgreement::~ReservByAgreement() {
    delete this->dateOfBegining;

    if (this->contract != nullptr) {
        delete this->contract;
        this->contract = nullptr;
    }
    if (this->hotelRoom != nullptr) {
        delete this->hotelRoom;
        this->hotelRoom = nullptr;
    }
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

ReservByAgreement::ReservByAgreement(const QDate &dateOfBegining, int idHotelRoom, int idContract) : Model() {
    this->dateOfBegining = new QDate(dateOfBegining);
    this->idHotelRoom = idHotelRoom;
    this->idContract = idContract;

    this->contract = nullptr;
    this->hotelRoom = nullptr;
}

ReservByAgreement::ReservByAgreement(int id, const QDate &dateOfBegining, int idHotelRoom, int idContract) : Model(id) {
    this->dateOfBegining = new QDate(dateOfBegining);
    this->idHotelRoom = idHotelRoom;
    this->idContract = idContract;

    this->contract = nullptr;
    this->hotelRoom = nullptr;
}

QStringList ReservByAgreement::columnList = {"ID_i", "Date of begining_d", "Hotel room_f", "Contract_f"};

QStringList *ReservByAgreement::getValueList() {
    return new QStringList(
            {QString::number(this->id), this->dateOfBegining->toString(), *this->hotelRoom, *this->contract});
}

QString *ReservByAgreement::getHotelRoom() const {
    return hotelRoom;
}

void ReservByAgreement::setHotelRoom(QString *hotelRoom) {
    ReservByAgreement::hotelRoom = hotelRoom;
}

QString *ReservByAgreement::getContract() const {
    return contract;
}

void ReservByAgreement::setContract(QString *contract) {
    ReservByAgreement::contract = contract;
}

QStringList *ReservByAgreement::getValForAdd() {
    return new QStringList(
            {QString::number(this->id), *this->hotelRoom, *this->contract, this->dateOfBegining->toString()});
}

ReservByAgreement::ReservByAgreement(const QStringList &args) : Model(args) {
    this->dateOfBegining = new QDate(args[1]);
    this->idHotelRoom = args[2].toInt();
    this->idContract = args[3].toInt();

    this->contract = nullptr;
    this->hotelRoom = nullptr;
}
