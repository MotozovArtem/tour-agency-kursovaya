//
// Created by rienel on 14.04.18.
//

#include "DocumentsForTour.h"

DocumentsForTour::DocumentsForTour(int id, int idDocument, int idClient, int idDocumentType) : Model(id),
                                                                                               idDocument(idDocument),
                                                                                               idClient(idClient),
                                                                                               idDocumentType(
                                                                                                       idDocumentType) {}

DocumentsForTour::DocumentsForTour(int idDocument, int idClient, int idDocumentType) : idDocument(idDocument),
                                                                                       idClient(idClient),
                                                                                       idDocumentType(idDocumentType) {}

DocumentsForTour::DocumentsForTour(int id) : Model(id) {}

DocumentsForTour::DocumentsForTour() {}

DocumentsForTour::~DocumentsForTour() {

}

int DocumentsForTour::getIdDocument() const {
    return idDocument;
}

void DocumentsForTour::setIdDocument(int idDocument) {
    DocumentsForTour::idDocument = idDocument;
}

int DocumentsForTour::getIdClient() const {
    return idClient;
}

void DocumentsForTour::setIdClient(int idClient) {
    DocumentsForTour::idClient = idClient;
}

int DocumentsForTour::getIdDocumentType() const {
    return idDocumentType;
}

void DocumentsForTour::setIdDocumentType(int idDocumentType) {
    DocumentsForTour::idDocumentType = idDocumentType;
}

QStringList DocumentsForTour::columnList = {"ID", "Document_f", "Client_f","Document type_f"};