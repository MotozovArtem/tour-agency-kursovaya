//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_CLIENTS_H
#define PSQLWORK_CLIENTS_H

#include "Model.h"
#include <QString>
#include <QDate>

class Client : public Model {
private:
    QString *passportData;
    QString *surname;
    QString *clientName;
    QString *patronymic;
    QDate *dateOfBirth;
    QString *placeOfBirth;
    bool sex;
public:
    static QStringList columnList;
    Client(int id, QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
           QString *placeOfBirth, bool sex);

    Client(int id, const QString &passportData, const QString &surname, const QString &name, const QString &patronymic,
           const QDate &dateOfBirth,
           const QString &placeOfBirth, bool sex);

    Client(QString *passportData, QString *surname, QString *name, QString *patronymic, QDate *dateOfBirth,
           QString *placeOfBirth, bool sex);

    Client(const QString &passportData, const QString &surname, const QString &name, const QString &patronymic,
           const QDate &dateOfBirth,
           const QString *&placeOfBirth, bool sex);

    Client(int id);

    Client();

    virtual ~Client();

    QString *getPassportData() const;

    void setPassportData(QString *passportData);

    QString *getSurname() const;

    void setSurname(QString *surname);

    QString *getName() const;

    void setName(QString *name);

    QString *getPatronymic() const;

    void setPatronymic(QString *patronymic);

    QDate *getDateOfBirth() const;

    void setDateOfBirth(QDate *dateOfBirth);

    QString *getPlaceOfBirth() const;

    void setPlaceOfBirth(QString *placeOfBirth);

    bool isSex() const;

    void setSex(bool sex);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_CLIENTS_H
