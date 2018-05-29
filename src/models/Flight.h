//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_FLIGHT_H
#define PSQLWORK_FLIGHT_H

#include <QString>
#include <QDate>
#include "Model.h"

class Flight : public Model {
private:
    QDate *dateOfPurchase;
    QDate *dateOfDeparture;
    QTime *departureTime;
    QTime *arrivalTime;
    QDate *arrivalDate;
public:
    static QStringList columnList;
    Flight(int id, QDate *dateOfPurchase, QDate *dateOfDeparture, QTime *departureTime, QTime *arrivalTime,
           QDate *arrivalDate);

    Flight(int id, const QDate &dateOfPurchase, const QDate &dateOfDeparture, const QTime &departureTime,
           const QTime &arrivalTime,
           const QDate &arrivalDate);

    Flight(QDate *dateOfPurchase, QDate *dateOfDeparture, QTime *departureTime, QTime *arrivalTime, QDate *arrivalDate);

    Flight(const QDate &dateOfPurchase, const QDate &dateOfDeparture, const QTime &departureTime,
           const QTime &arrivalTime,
           const QDate &arrivalDate);

    Flight(int id);

    Flight();

    virtual ~Flight();

    QDate *getDateOfPurchase() const;

    void setDateOfPurchase(QDate *dateOfPurchase);

    QDate *getDateOfDeparture() const;

    void setDateOfDeparture(QDate *dateOfDeparture);

    QTime *getDepartureTime() const;

    void setDepartureTime(QTime *departureTime);

    QTime *getArrivalTime() const;

    void setArrivalTime(QTime *arrivalTime);

    QDate *getArrivalDate() const;

    void setArrivalDate(QDate *arrivalDate);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_FLIGHT_H
