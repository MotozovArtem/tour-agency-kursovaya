//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_TOUR_H
#define PSQLWORK_TOUR_H

#include "Model.h"
#include <QtCore>

class Tour: public Model{
private:
    QString * name;
    int days;
    int idCity;
    int idTourType;
public:
    static QStringList columnList;
    Tour(int id, QString *name, int days, int idCity, int idTourType);

    Tour(int id,const  QString &name, int days, int idCity, int idTourType);

    Tour(QString *name, int days, int idCity, int idTourType);

    Tour(const QString &name, int days, int idCity, int idTourType);

    Tour(int id);

    Tour();

    virtual ~Tour();

    QString *getName() const;

    void setName(QString *name);

    int getDays() const;

    void setDays(int days);

    int getIdCity() const;

    void setIdCity(int idCity);

    int getIdTourType() const;

    void setIdTourType(int idTourType);
};


#endif //PSQLWORK_TOUR_H
