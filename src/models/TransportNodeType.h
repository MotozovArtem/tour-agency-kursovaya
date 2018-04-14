//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_TRANSPORTNODETYPE_H
#define PSQLWORK_TRANSPORTNODETYPE_H

#include "Model.h"
#include <QString>

class TransportNodeType: public Model {
private:
    QString *name;
public:
    TransportNodeType(int id, QString *name);

    TransportNodeType(QString *name);

    TransportNodeType(int id);

    TransportNodeType();

    virtual ~TransportNodeType();

    QString *getName() const;

    void setName(QString *name);
};


#endif //PSQLWORK_TRANSPORTNODETYPE_H
