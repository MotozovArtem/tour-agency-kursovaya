//
// Created by rienel on 11.04.18.
//

#ifndef PSQLWORK_TOURTYPE_H
#define PSQLWORK_TOURTYPE_H

#include <QtCore>
#include "Model.h"

class TourType : public Model {
private:
    QString *name;
public:
    TourType(int id, QString *name);

    TourType(QString *name);

    TourType(int id);

    TourType();

    virtual ~TourType();

    QString *getName() const;

    void setName(QString *name);

};


#endif //PSQLWORK_TOURTYPE_H
