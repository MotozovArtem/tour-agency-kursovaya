//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_TICKET_H
#define PSQLWORK_TICKET_H

#include "Model.h"
#include <QtCore>


class Ticket : public Model {
private:
    int place;
    QDate *date;
    float price;
    int idDocuments;
    QDate *dateOfPurchase;
    int idFlight;
public:
    Ticket(int id, int place, QDate *date, float price, int idDocuments, QDate *dateOfPurchase, int idFlight);

    Ticket(int id, int place, const QDate &date, float price, int idDocuments, const QDate &dateOfPurchase,
           int idFlight);

    Ticket(int place, QDate *date, float price, int idDocuments, QDate *dateOfPurchase, int idFlight);

    Ticket(int place, const QDate &date, float price, int idDocuments, const QDate &dateOfPurchase, int idFlight);

    Ticket(int id);

    Ticket();

    virtual ~Ticket();
};


#endif //PSQLWORK_TICKET_H
