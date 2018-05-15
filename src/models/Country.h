//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_COUNTRY_H
#define PSQLWORK_COUNTRY_H

#include <QtCore>
#include "Model.h"

class Country : public Model{
private:
    QString *name;
    QDate *foundationDate;
public:
    Country(int id, QString *name, QDate *foundationDate);

    Country(int id, const QString &name,const QDate &foundationDate);

    Country(QString *name, QDate *foundationDate);

    Country(const QString &name, const QDate &foundationDate);

    Country(int id);

    Country();

    virtual ~Country();

    QString *getName() const;

    void setName(QString *name);

    QDate *getFoundationDate() const;

    void setFoundationDate(QDate *foundationDate);
};


#endif //PSQLWORK_COUNTRY_H
