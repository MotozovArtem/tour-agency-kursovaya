//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_DOCUMENTTYPE_H
#define PSQLWORK_DOCUMENTTYPE_H

#include "Model.h"
#include <QtCore>


class DocumentType : public Model {
private:
    QString *documentTypeName;
public:
    static QStringList columnList;
    DocumentType(int id, QString *name);

    DocumentType(int id, const QString &name);

    DocumentType(QString *name);

    DocumentType(const QString &name);

    DocumentType(int id);

    DocumentType();

    virtual ~DocumentType();

    QString *getName() const;

    void setName(QString *name);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_DOCUMENTTYPE_H
