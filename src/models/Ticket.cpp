//
// Created by rienel on 11.04.18.
//

#include "Ticket.h"

Ticket::Ticket(int id, int place, QDate *date, float price, int idDocuments, QDate *dateOfPurchase, int idFlight)
        : Model(id), place(place), date(date), price(price), idDocuments(idDocuments), dateOfPurchase(dateOfPurchase),
          idFlight(idFlight) {}

Ticket::Ticket(int place, QDate *date, float price, int idDocuments, QDate *dateOfPurchase, int idFlight) : place(
        place), date(date), price(price), idDocuments(idDocuments), dateOfPurchase(dateOfPurchase), idFlight(
        idFlight) {}

Ticket::Ticket(int id) : Model(id) {}

Ticket::Ticket() {}

Ticket::~Ticket() {
    delete this->date;
    delete this->dateOfPurchase;
}
