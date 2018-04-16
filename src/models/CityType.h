//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CITYTYPE_H
#define PSQLWORK_CITYTYPE_H

#include <QtCore>
#include "Model.h"

class CityType: public Model {
private:
    QString *name;
public:
    CityType(int id, QString *name);

    CityType(QString *name);

    CityType(int id);

    CityType();

    virtual ~CityType();

    QString *getName() const;

    void setName(QString *name);
};


#endif //PSQLWORK_CITYTYPE_H
