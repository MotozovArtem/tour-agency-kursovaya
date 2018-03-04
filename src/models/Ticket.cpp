//
// Created by rienel on 04.03.18.
//

#include "Ticket.h"

Ticket::Ticket(int id, int ticketSer, int seatNum, std::string *date, float price) : Model(id), ticketSer(ticketSer),
                                                                                     seatNum(seatNum), date(date),
                                                                                     price(price) {}

Ticket::Ticket(int ticketSer, int seatNum, std::string *date, float price) : ticketSer(ticketSer), seatNum(seatNum),
                                                                             date(date), price(price) {}

Ticket::Ticket(int id) : Model(id) {}

Ticket::Ticket() = default;

int Ticket::getTicketSer() const {
    return ticketSer;
}

void Ticket::setTicketSer(int ticketSer) {
    Ticket::ticketSer = ticketSer;
}

int Ticket::getSeatNum() const {
    return seatNum;
}

void Ticket::setSeatNum(int seatNum) {
    Ticket::seatNum = seatNum;
}

std::string *Ticket::getDate() const {
    return date;
}

void Ticket::setDate(std::string *date) {
    Ticket::date = date;
}

float Ticket::getPrice() const {
    return price;
}

void Ticket::setPrice(float price) {
    Ticket::price = price;
}

Ticket::~Ticket() {

}
