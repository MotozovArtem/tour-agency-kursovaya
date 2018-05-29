//
// Created by rienel on 14.04.18.
//

#ifndef PSQLWORK_DOCUMENTSFORTOUR_H
#define PSQLWORK_DOCUMENTSFORTOUR_H

#include <QtCore>
#include "Model.h"

class DocumentsForTour: public Model {
private:
    int idDocument;
    int idClient;
    int idDocumentType;

    QString *document;
    QString *clientName;
    QString *documentType;
public:
    static QStringList columnList;
    DocumentsForTour(int id, int idDocument, int idClient, int idDocumentType);

    DocumentsForTour(int idDocument, int idClient, int idDocumentType);

    DocumentsForTour(int id);

    DocumentsForTour();

    DocumentsForTour(const QStringList &args);

    virtual ~DocumentsForTour();

    int getIdDocument() const;

    void setIdDocument(int idDocument);

    int getIdClient() const;

    void setIdClient(int idClient);

    int getIdDocumentType() const;

    void setIdDocumentType(int idDocumentType);

    QString *getDocument() const;

    void setDocument(QString *document);

    QString *getClientName() const;

    void setClientName(QString *clientName);

    QString *getDocumentType() const;

    void setDocumentType(QString *documentType);

    virtual QStringList *getValueList();

    virtual QStringList *getValForAdd();
};


#endif //PSQLWORK_DOCUMENTSFORTOUR_H
