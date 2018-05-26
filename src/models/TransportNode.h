//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_TRANSPORTNODE_H
#define PSQLWORK_TRANSPORTNODE_H


#include "Model.h"
#include <QtCore>

class TransportNode: public Model {
private:
    QString *nodeName;
    int idFlight;
    int idTransportNodeType;

    QString *flight;
    QString *transportNodeType;
public:
    static QStringList columnList;
    TransportNode(int id, QString *nodeName, int idFlight, int idTransportNodeType);

    TransportNode(int id, const QString &nodeName, int idFlight, int idTransportNodeType);

    TransportNode(QString *nodeName, int idFlight, int idTransportNodeType);

    TransportNode(const QString &nodeName, int idFlight, int idTransportNodeType);

    TransportNode(int id);

    TransportNode();

    QString *getNodeName() const;

    void setNodeName(QString *nodeName);

    int getIdFlight() const;

    void setIdFlight(int idFlight);

    int getIdTransportNodeType() const;

    void setIdTransportNodeType(int idTransportNodeType);

    QString *getFlight() const;

    void setFlight(QString *flight);

    QString *getTransportNodeType() const;

    void setTransportNodeType(QString *transportNodeType);

    virtual QStringList *getValueList();
};


#endif //PSQLWORK_TRANSPORTNODE_H
