//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CHECK_H
#define PSQLWORK_CHECK_H

#include "Model.h"
#include <QtCore>

class Contract: public Model {
private:
    QString *name;
    QDate *dateOfPayment;
    QDate *dateOfIssue;
    float total;
    int idStatus;
    int idTourType;
    int idDocuments;
public:
    Contract(int id, QString *name, QDate *dateOfPayment, QDate *dateOfIssue, float total, int idStatus, int idTourType,
          int idDocuments);

    Contract(QString *name, QDate *dateOfPayment, QDate *dateOfIssue, float total, int idStatus, int idTourType,
          int idDocuments);

    Contract(int id);

    Contract();

    virtual ~Contract();

    QString *getName() const;

    void setName(QString *name);

    QDate *getDateOfPayment() const;

    void setDateOfPayment(QDate *dateOfPayment);

    QDate *getDateOfIssue() const;

    void setDateOfIssue(QDate *dateOfIssue);

    float getTotal() const;

    void setTotal(float total);

    int getIdStatus() const;

    void setIdStatus(int idStatus);

    int getIdTourType() const;

    void setIdTourType(int idTourType);

    int getIdDocuments() const;

    void setIdDocuments(int idDocuments);
};


#endif //PSQLWORK_CHECK_H
