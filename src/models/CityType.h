//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CITYTYPE_H
#define PSQLWORK_CITYTYPE_H

#include <QtCore>
#include "Model.h"

class CityType : public Model {
private:
    QString *cityTypeName;
public:
    static QStringList columnList;
    CityType(int id, QString *name);

    CityType(int id, const QString &name);

    CityType(const QString &name);

    CityType(QString *name);

    CityType(int id);

    CityType();

    virtual ~CityType();

    QString *getName() const;

    void setName(QString *name);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_CITYTYPE_H
