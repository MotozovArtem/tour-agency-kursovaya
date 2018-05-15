//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_DOCUMENTS_H
#define PSQLWORK_DOCUMENTS_H

#include "Model.h"
#include <QtCore>

class Documents : public Model {
private:
    QString *serial;
    QDate *dateOfIssue;
    QString *issuanceDepartment;
public:
    Documents(int id, QString *serial, QDate *dateOfIssue, QString *issuanceDepartment);

    Documents(int id, const QString &serial, const QDate &dateOfIssue, const QString &issuanceDepartment);

    Documents(QString *serial, QDate *dateOfIssue, QString *issuanceDepartment);

    Documents(const QString &serial, const QDate &dateOfIssue, const QString &issuanceDepartment);

    Documents(int id);

    Documents();

    virtual ~Documents();

    QString *getSerial() const;

    void setSerial(QString *serial);

    QDate *getDateOfIssue() const;

    void setDateOfIssue(QDate *dateOfIssue);

    QString *getIssuanceDepartment() const;

    void setIssuanceDepartment(QString *issuanceDepartment);
};


#endif //PSQLWORK_DOCUMENTS_H
