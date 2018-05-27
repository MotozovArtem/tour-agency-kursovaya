//
// Created by rienel on 08.04.18.
//

#ifndef PSQLWORK_HOTEL_H
#define PSQLWORK_HOTEL_H

#include "Model.h"
#include <QtCore>
#include <QDate>

class Hotel : public Model {
private:
    QString *hotelName;
    QString *address;
    int stars;
    QDate *yearOfFoundation;
    int idCity;

    QString *cityName;
public:
    static QStringList columnList;

    Hotel(int id, QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, int idCity);

    Hotel(int id, const QString &hotelName, const QString &address, int stars, const QDate &yearOfFoundation,
          int idCity);

    Hotel(QString *hotelName, QString *address, int stars, QDate *yearOfFoundation, int idCity);

    Hotel(const QString &hotelName, const QString &address, int stars, const QDate &yearOfFoundation, int idCity);

    Hotel(int id);

    Hotel();

    virtual ~Hotel();

    QString *getHotelName() const;

    void setHotelName(QString *hotelName);

    QString *getAddress() const;

    void setAddress(QString *address);

    int getStars() const;

    void setStars(int stars);

    QDate *getYearOfFoundation() const;

    void setYearOfFoundation(QDate *yearOfFoundation);

    int getIdCity() const;

    void setIdCity(int idCity);

    QString *getCityName() const;

    void setCityName(QString *cityName);

    virtual QStringList *getValueList();

};


#endif //PSQLWORK_HOTEL_H
