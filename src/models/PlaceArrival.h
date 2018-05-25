//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_PLACEARRIVAL_H
#define PSQLWORK_PLACEARRIVAL_H


#include "Model.h"
#include <QtCore>

class PlaceArrival : public Model {
private:
    QString *name;
    QString *address;
    int idCity;
    int idPlaceArrivalType;
public:
    static QStringList columnList;
    PlaceArrival(int id, QString *name, QString *address, int idCity, int idPlaceArrivalType);

    PlaceArrival(int id, const QString &name, const QString &address, int idCity, int idPlaceArrivalType);

    PlaceArrival(QString *name, QString *address, int idCity, int idPlaceArrivalType);

    PlaceArrival(const QString &name, const QString &address, int idCity, int idPlaceArrivalType);

    PlaceArrival(int id);

    PlaceArrival();

    virtual ~PlaceArrival();

    QString *getName() const;

    void setName(QString *name);

    QString *getAddress() const;

    void setAddress(QString *address);

    int getIdCity() const;

    void setIdCity(int idCity);

    int getIdPlaceArrivalType() const;

    void setIdPlaceArrivalType(int idPlaceArrivalType);
};


#endif //PSQLWORK_PLACEARRIVAL_H
