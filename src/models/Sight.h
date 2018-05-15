//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_SIGHT_H
#define PSQLWORK_SIGHT_H

#include <QtCore>
#include "Model.h"

class Sight : public Model {
private:
    QString *name;
    QString *address;
    QDate *yearOfCreation;
    QString *toponym;
    int idCity;
public:
    Sight(int id, QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity);

    Sight(int id, const QString &name, const QString &address, const QDate &yearOfCreation, const QString &toponym,
          int idCity);

    Sight(QString *name, QString *address, QDate *yearOfCreation, QString *toponym, int idCity);

    Sight(const QString &name, const QString &address, const QDate &yearOfCreation, const QString &toponym, int idCity);

    Sight(int id);

    Sight();

    virtual ~Sight();

    QString *getName() const;

    void setName(QString *name);

    QString *getAddress() const;

    void setAddress(QString *address);

    QDate *getYearOfCreation() const;

    void setYearOfCreation(QDate *yearOfCreation);

    QString *getToponym() const;

    void setToponym(QString *toponym);

    int getIdCity() const;

    void setIdCity(int idCity);
};


#endif //PSQLWORK_SIGHT_H
