//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_TRANSPORTNODE_H
#define PSQLWORK_TRANSPORTNODE_H


#include "Model.h"
#include <QtCore>

class TransportNode: public Model {
private:
    QDate *dateOfPurchase;
    int idFlight;
    QString *nodeName;
    int idTransportNodeType;
public:
    TransportNode(int id, QDate *dateOfPurchase, int idFlight, QString *nodeName, int idTransportNodeType);

    TransportNode(int id,const QDate &dateOfPurchase, int idFlight, const QString &nodeName, int idTransportNodeType);

    TransportNode(QDate *dateOfPurchase, int idFlight, QString *nodeName, int idTransportNodeType);

    TransportNode(const QDate &dateOfPurchase, int idFlight, const QString &nodeName, int idTransportNodeType);

    TransportNode(int id);

    TransportNode();

    QDate *getDateOfPurchase() const;

    void setDateOfPurchase(QDate *dateOfPurchase);

    int getIdFlight() const;

    void setIdFlight(int idFlight);

    QString *getNodeName() const;

    void setNodeName(QString *nodeName);

    int getIdTransportNodeType() const;

    void setIdTransportNodeType(int idTransportNodeType);

    virtual ~TransportNode();
};


#endif //PSQLWORK_TRANSPORTNODE_H
