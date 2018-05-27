//
// Created by rienel on 27.05.18.
//

#ifndef PSQLWORK_TICKETDATABASEDAO_H
#define PSQLWORK_TICKETDATABASEDAO_H

#include "interfaces/TicketDAO.h"


class TicketDataBaseDAO: public TicketDAO {
public:
    virtual QList<Ticket *> getAll();

    virtual Ticket *getById(int id);

    virtual void add(Ticket *model);

    virtual void update(Ticket *model);

    virtual void del(Ticket *model);

    virtual QList<Ticket *> getAllFilled();
};


#endif //PSQLWORK_TICKETDATABASEDAO_H
