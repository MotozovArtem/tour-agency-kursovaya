//
// Created by rienel on 11.04.18.
//

#include "Reservation.h"

Reservation::Reservation(int id, QDate *dateOfBegining, QDate *dateOfEnding, int idHotelRoom, int idContract) : Model(
        id), dateOfBegining(dateOfBegining), idHotelRoom(idHotelRoom), dateOfEnding(dateOfEnding), idContract(
        idContract) {
    this->hotelRoom = nullptr;
    this->contract = nullptr;
}

Reservation::Reservation(QDate *dateOfBegining, QDate *dateOfEnding, int idHotelRoom, int idContract) : dateOfBegining(
        dateOfBegining), idHotelRoom(idHotelRoom), dateOfEnding(dateOfEnding), idContract(idContract) {
    this->hotelRoom = nullptr;
    this->contract = nullptr;
}

Reservation::Reservation(int id) : Model(id) {
    this->hotelRoom = nullptr;
    this->contract = nullptr;
}

Reservation::Reservation() {
    this->hotelRoom = nullptr;
    this->contract = nullptr;
}

Reservation::Reservation(int id, const QDate &dateOfBegining, const QDate &dateOfEnding, int idHotelRoom,
                         int idContract) : Model(id) {
    this->dateOfEnding = new QDate(dateOfEnding);
    this->dateOfBegining = new QDate(dateOfBegining);
    this->idContract = idContract;
    this->idHotelRoom = idHotelRoom;

    this->hotelRoom = nullptr;
    this->contract = nullptr;
}

Reservation::Reservation(const QDate &dateOfBegining, const QDate &dateOfEnding, int idHotelRoom, int idContract)
        : Model() {
    this->dateOfBegining = new QDate(dateOfBegining);
    this->dateOfEnding = new QDate(dateOfEnding);
    this->idContract = idContract;
    this->idHotelRoom = idHotelRoom;

    this->hotelRoom = nullptr;
    this->contract = nullptr;
}

Reservation::~Reservation() {
    if(this->dateOfBegining!=nullptr){
        delete this->dateOfBegining;
        this->dateOfBegining=nullptr;
    }
    if(this->dateOfEnding!=nullptr){
        delete this->dateOfEnding;
        this->dateOfEnding=nullptr;
    }

    if (this->hotelRoom != nullptr) {
        delete this->hotelRoom;
        this->hotelRoom = nullptr;
    }
    if (this->contract != nullptr) {
        delete this->contract;
        this->contract = nullptr;
    }
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


QString *Reservation::getHotelRoom() const {
    return hotelRoom;
}

void Reservation::setHotelRoom(QString *hotelRoom) {
    Reservation::hotelRoom = hotelRoom;
}

QString *Reservation::getContract() const {
    return contract;
}

void Reservation::setContract(QString *contract) {
    Reservation::contract = contract;
}

QStringList Reservation::columnList = {"ID_i", "Date of begining_d", "Date of Ending_d", "Hotel room_f", "Contract_f"};

QStringList *Reservation::getValueList() {
    return new QStringList({QString::number(this->id), this->dateOfBegining->toString("dd.MM.yyyy"), this->dateOfEnding->toString("dd.MM.yyyy"),
                            *this->hotelRoom, *this->contract});
}

QStringList *Reservation::getValForAdd() {
    return new QStringList({QString::number(this->id), *this->hotelRoom, *this->contract, this->dateOfBegining->toString("dd.MM.yyyy"), this->dateOfEnding->toString("dd.MM.yyyy")});
}

Reservation::Reservation(const QStringList &args) : Model(args) {
    this->dateOfBegining = toDate(args[1]);
    this->dateOfEnding = toDate(args[2]);
    this->idHotelRoom = args[3].toInt();
    this->idContract = args[4].toInt();

    this->hotelRoom = nullptr;
    this->contract = nullptr;
}
