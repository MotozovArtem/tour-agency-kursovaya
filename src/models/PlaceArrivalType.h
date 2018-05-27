//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_PLACEARRIVALTYPE_H
#define PSQLWORK_PLACEARRIVALTYPE_H


#include <QtCore>
#include "Model.h"

class PlaceArrivalType : public Model {
private:
    QString *placeArrivalTypeName;
public:
    static QStringList columnList;

    PlaceArrivalType(int id, QString *name);

    PlaceArrivalType(int id, const QString &name);

    PlaceArrivalType(QString *name);

    PlaceArrivalType(const QString &name);

    PlaceArrivalType(int id);

    PlaceArrivalType();

    virtual ~PlaceArrivalType();

    QString *getName() const;

    void setName(QString *name);

    virtual QStringList *getValueList();
};


#endif //PSQLWORK_PLACEARRIVALTYPE_H
