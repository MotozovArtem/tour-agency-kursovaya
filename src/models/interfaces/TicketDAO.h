//
// Created by rienel on 16.04.18.
//

#ifndef PSQLWORK_TICKETDAO_H
#define PSQLWORK_TICKETDAO_H

#include "ModelDAO.h"
#include "../Ticket.h"

class TicketDAO : public ModelDAO<Ticket *> {
public:
    virtual std::list<Ticket *> getAll() =0;

    virtual Ticket *getById(int id) =0;

    virtual void add(Ticket *model) =0;

    virtual void update(Ticket *model) =0;

    virtual void del(Ticket *model) =0;
};


#endif //PSQLWORK_TICKETDAO_H
