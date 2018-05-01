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
    float price;
    int idCityType;
public:
    City(int id, QString *name, float price, int idCityType);

    City(QString *name, float price, int idCityType);

    City(int id);

    City(QString *name);

    virtual ~City();

    QString *getName() const;

    void setName(QString *name);

    float getPrice() const;

    void setPrice(float price);

    int getIdCityType() const;

    void setIdCityType(int idCityType);
};


#endif //PSQLWORK_CITY_H
