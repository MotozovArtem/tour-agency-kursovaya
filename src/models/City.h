//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CITY_H
#define PSQLWORK_CITY_H

#include <QtCore>
#include "Model.h"

class City : public Model {
private:
    QString *cityName;
    int idCityType;
    int idCountry;

    QString *cityTypeName;
    QString *countryName;
public:
    static QStringList columnList;

    City(int id, QString *name, int idCityType, int idCountry);

    City(int id, const QString &name, int idCityType, int idCountry);

    City(const QString &name, int idCityType, int idCountry);

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

    QString *getCityTypeName() const;

    void setCityTypeName(QString *cityTypeName);

    QString *getCountryName() const;

    void setCountryName(QString *countryName);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_CITY_H
