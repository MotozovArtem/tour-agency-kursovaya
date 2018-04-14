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
public:
    DocumentsForTour(int id, int idDocument, int idClient, int idDocumentType);

    DocumentsForTour(int idDocument, int idClient, int idDocumentType);

    DocumentsForTour(int id);

    DocumentsForTour();

    virtual ~DocumentsForTour();

    int getIdDocument() const;

    void setIdDocument(int idDocument);

    int getIdClient() const;

    void setIdClient(int idClient);

    int getIdDocumentType() const;

    void setIdDocumentType(int idDocumentType);
};


#endif //PSQLWORK_DOCUMENTSFORTOUR_H
