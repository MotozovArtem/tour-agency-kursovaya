//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_PLACEARRIVALTYPE_H
#define PSQLWORK_PLACEARRIVALTYPE_H


#include <QtCore>
#include "Model.h"

class PlaceArrivalType: public Model {
private:
    QString *name;
public:
    PlaceArrivalType(int id, QString *name);

    PlaceArrivalType(QString *name);

    PlaceArrivalType(int id);

    PlaceArrivalType();

    virtual ~PlaceArrivalType();

    QString *getName() const;

    void setName(QString *name);
};


#endif //PSQLWORK_PLACEARRIVALTYPE_H
