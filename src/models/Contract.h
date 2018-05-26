//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_CHECK_H
#define PSQLWORK_CHECK_H

#include "Model.h"
#include <QString>
#include <QDate>

class Contract: public Model {
private:
    QString *name;
    QDate *dateOfPayment;
    QDate *dateOfIssue;
    float total;
    int idStatus;
    int idTourType;
    int idDocuments;

    QString *statusName;
    QString *tourTypeName;
    QString *docuements;
public:
    static QStringList columnList;
    Contract(int id, QString *name, QDate *dateOfPayment, QDate *dateOfIssue, float total, int idStatus, int idTourType,
          int idDocuments);

    Contract(int id,const QString &name,const QDate &dateOfPayment,const QDate &dateOfIssue, float total, int idStatus, int idTourType,
             int idDocuments);

    Contract(QString *name, QDate *dateOfPayment, QDate *dateOfIssue, float total, int idStatus, int idTourType,
          int idDocuments);

    Contract(const QString &name,const QDate &dateOfPayment,const QDate &dateOfIssue, float total, int idStatus, int idTourType,
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

    QString *getStatusName() const;

    void setStatusName(QString *statusName);

    QString *getTourTypeName() const;

    void setTourTypeName(QString *tourTypeName);

    QString *getDocuements() const;

    void setDocuements(QString *docuements);

    virtual QStringList *getValueList();
};


#endif //PSQLWORK_CHECK_H
