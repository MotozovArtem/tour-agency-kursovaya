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
    QDate *dateFlight;
    float price;
    QDate *dateOfPurchase;
    int idDocuments;
    int idFlight;

    QString *documents;
    QString *flight;
public:
    static QStringList columnList;

    Ticket(int id, int place, QDate *date_flight, float price, QDate *dateOfPurchase, int idDocuments, int idFlight);

    Ticket(int id, int place, const QDate &date_flight, float price, const QDate &dateOfPurchase, int idDocuments,
           int idFlight);

    Ticket(int place, QDate *date_flight, float price, QDate *dateOfPurchase, int idDocuments, int idFlight);

    Ticket(int place, const QDate &date_flight, float price, const QDate &dateOfPurchase, int idDocuments,
           int idFlight);

    Ticket(int id);

    Ticket();

    virtual ~Ticket();

    int getPlace() const;

    void setPlace(int place);

    QDate *getDateFlight() const;

    void setDateFlight(QDate *dateFlight);

    float getPrice() const;

    void setPrice(float price);

    int getIdDocuments() const;

    void setIdDocuments(int idDocuments);

    QDate *getDateOfPurchase() const;

    void setDateOfPurchase(QDate *dateOfPurchase);

    int getIdFlight() const;

    void setIdFlight(int idFlight);


    QString *getDocuments() const;

    void setDocuments(QString *documents);

    QString *getFlight() const;

    void setFlight(QString *flight);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_TICKET_H
