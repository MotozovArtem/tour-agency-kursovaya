//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_COUNTRY_H
#define PSQLWORK_COUNTRY_H

#include <QString>
#include <QDate>
#include "Model.h"

class Country : public Model{
private:
    QString *countryName;
    QDate *foundationDate;
public:
    static QStringList columnList;
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

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_COUNTRY_H
