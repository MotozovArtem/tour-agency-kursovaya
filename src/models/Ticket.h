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
    QDate *date_flight;
    float price;
    int idDocuments;
    QDate *dateOfPurchase;
    int idFlight;
public:
    static QStringList columnList;
    Ticket(int id, int place, QDate *date_flight, float price, int idDocuments, QDate *dateOfPurchase, int idFlight);

    Ticket(int id, int place, const QDate &date_flight, float price, int idDocuments, const QDate &dateOfPurchase,
           int idFlight);

    Ticket(int place, QDate *date_flight, float price, int idDocuments, QDate *dateOfPurchase, int idFlight);

    Ticket(int place, const QDate &date_flight, float price, int idDocuments, const QDate &dateOfPurchase,
           int idFlight);

    Ticket(int id);

    Ticket();

    virtual ~Ticket();

    int getPlace() const;

    void setPlace(int place);

    QDate *getDate_flight() const;

    void setDate_flight(QDate *date_flight);

    float getPrice() const;

    void setPrice(float price);

    int getIdDocuments() const;

    void setIdDocuments(int idDocuments);

    QDate *getDateOfPurchase() const;

    void setDateOfPurchase(QDate *dateOfPurchase);

    int getIdFlight() const;

    void setIdFlight(int idFlight);


};


#endif //PSQLWORK_TICKET_H
