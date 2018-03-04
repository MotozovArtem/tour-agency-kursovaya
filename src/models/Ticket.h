//
// Created by rienel on 04.03.18.
//

#ifndef PSQLWORK_TICKET_H
#define PSQLWORK_TICKET_H

#include "Model.h"
#include <string>

class Ticket: public Model {
private:
    int ticketSer;
public:
    virtual ~Ticket();

private:
    int seatNum;
    std::string* date;
    float price;
public:
    Ticket(int id, int ticketSer, int seatNum, std::string *date, float price);

    Ticket(int ticketSer, int seatNum, std::string *date, float price);

    Ticket(int id);

    Ticket();

    int getTicketSer() const;

    void setTicketSer(int ticketSer);

    int getSeatNum() const;

    void setSeatNum(int seatNum);

    std::string *getDate() const;

    void setDate(std::string *date);

    float getPrice() const;

    void setPrice(float price);
};


#endif //PSQLWORK_TICKET_H
