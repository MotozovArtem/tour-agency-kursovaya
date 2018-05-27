//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_TOURTYPE_H
#define PSQLWORK_TOURTYPE_H

#include <QtCore>
#include "Model.h"

class TourType : public Model {
private:
    QString *tourTypeName;
public:
    static QStringList columnList;
    TourType(int id, QString *name);

    TourType(int id, const QString &name);

    TourType(QString *name);

    TourType(const QString &name);

    TourType(int id);

    TourType();

    virtual ~TourType();

    QString *getName() const;

    void setName(QString *name);

    virtual QStringList *getValueList();

};


#endif //PSQLWORK_TOURTYPE_H
