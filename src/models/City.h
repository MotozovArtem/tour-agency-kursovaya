//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CITY_H
#define PSQLWORK_CITY_H

#include <QtCore>
#include "Model.h"

class City : public Model {
private:
    QString *name;
    int idCityType;
    int idCountry;
public:
    City(int id, QString *name, int idCityType, int idCountry);

    City(QString *name, int idCityType, int idCountry);

    City(int id);

    City();

    QString *getName() const;

    void setName(QString *name);

    int getIdCityType() const;

    void setIdCityType(int idCityType);

    int getIdCountry() const;

    void setIdCountry(int idCountry);

    virtual ~City();
};


#endif //PSQLWORK_CITY_H
