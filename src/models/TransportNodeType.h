//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_TRANSPORTNODETYPE_H
#define PSQLWORK_TRANSPORTNODETYPE_H

#include "Model.h"
#include <QString>
#include <QtCore/QStringList>

class TransportNodeType : public Model {
private:
    QString *transportNodeTypeName;
public:
    static QStringList columnList;

    TransportNodeType(int id, QString *name);

    TransportNodeType(int id, const QString &name);

    TransportNodeType(QString *name);

    TransportNodeType(const QString &name);

    TransportNodeType(int id);

    TransportNodeType();

    virtual ~TransportNodeType();

    QString *getName() const;

    void setName(QString *name);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_TRANSPORTNODETYPE_H
