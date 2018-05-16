//
// Created by rienel on 11.04.18.
//

#include "Ticket.h"

Ticket::Ticket(int id, int place, QDate *date_flight, float price, int idDocuments, QDate *dateOfPurchase, int idFlight)
        : Model(id), place(place), date_flight(date_flight), price(price), idDocuments(idDocuments), dateOfPurchase(dateOfPurchase),
          idFlight(idFlight) {}

Ticket::Ticket(int place, QDate *date_flight, float price, int idDocuments, QDate *dateOfPurchase, int idFlight) : place(
        place), date_flight(date_flight), price(price), idDocuments(idDocuments), dateOfPurchase(dateOfPurchase), idFlight(
        idFlight) {}

Ticket::Ticket(int id) : Model(id) {}

Ticket::Ticket() {}

Ticket::~Ticket() {
    delete this->date_flight;
    delete this->dateOfPurchase;
}

Ticket::Ticket(int id, int place, const QDate &date_flight, float price, int idDocuments, const QDate &dateOfPurchase,
               int idFlight) : Model(id) {
    this->place = place;
    this->date_flight = new QDate(date_flight);
    this->price = price;
    this->idDocuments = idDocuments;
    this->dateOfPurchase = new QDate(dateOfPurchase);
    this->idFlight = idFlight;
}

Ticket::Ticket(int place, const QDate &date_flight, float price, int idDocuments, const QDate &dateOfPurchase, int idFlight) {
    this->place = place;
    this->date_flight = new QDate(date_flight);
    this->price = price;
    this->idDocuments = idDocuments;
    this->dateOfPurchase = new QDate(dateOfPurchase);
    this->idFlight = idFlight;
}

int Ticket::getPlace() const {
    return place;
}

void Ticket::setPlace(int place) {
    Ticket::place = place;
}

QDate *Ticket::getDate_flight() const {
    return date_flight;
}

void Ticket::setDate_flight(QDate *date_flight) {
    Ticket::date_flight = date_flight;
}

float Ticket::getPrice() const {
    return price;
}

void Ticket::setPrice(float price) {
    Ticket::price = price;
}

int Ticket::getIdDocuments() const {
    return idDocuments;
}

void Ticket::setIdDocuments(int idDocuments) {
    Ticket::idDocuments = idDocuments;
}

QDate *Ticket::getDateOfPurchase() const {
    return dateOfPurchase;
}

void Ticket::setDateOfPurchase(QDate *dateOfPurchase) {
    Ticket::dateOfPurchase = dateOfPurchase;
}

int Ticket::getIdFlight() const {
    return idFlight;
}

void Ticket::setIdFlight(int idFlight) {
    Ticket::idFlight = idFlight;
}
