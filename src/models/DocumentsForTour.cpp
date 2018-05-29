//
// Created by rienel on 14.04.18.
//

#include "DocumentsForTour.h"

DocumentsForTour::DocumentsForTour(int id, int idDocument, int idClient, int idDocumentType) : Model(id),
                                                                                               idDocument(idDocument),
                                                                                               idClient(idClient),
                                                                                               idDocumentType(
                                                                                                       idDocumentType) {
    this->document = nullptr;
    this->clientName = nullptr;
    this->documentType = nullptr;
}

DocumentsForTour::DocumentsForTour(int idDocument, int idClient, int idDocumentType) : idDocument(idDocument),
                                                                                       idClient(idClient),
                                                                                       idDocumentType(idDocumentType) {
    this->document = nullptr;
    this->clientName = nullptr;
    this->documentType = nullptr;
}

DocumentsForTour::DocumentsForTour(int id) : Model(id) {
    this->document = nullptr;
    this->clientName = nullptr;
    this->documentType = nullptr;
}

DocumentsForTour::DocumentsForTour() {
    this->document = nullptr;
    this->clientName = nullptr;
    this->documentType = nullptr;
}

DocumentsForTour::~DocumentsForTour() {
    if (this->documentType != nullptr) {
        delete this->documentType;
        this->documentType = nullptr;
    }
    if (this->document != nullptr) {
        delete this->document;
        this->document = nullptr;
    }
    if (this->clientName != nullptr) {
        delete this->clientName;
        this->clientName = nullptr;
    }
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

QString *DocumentsForTour::getDocument() const {
    return document;
}

void DocumentsForTour::setDocument(QString *document) {
    DocumentsForTour::document = document;
}

QString *DocumentsForTour::getClientName() const {
    return clientName;
}

void DocumentsForTour::setClientName(QString *clientName) {
    DocumentsForTour::clientName = clientName;
}

QString *DocumentsForTour::getDocumentType() const {
    return documentType;
}

void DocumentsForTour::setDocumentType(QString *documentType) {
    DocumentsForTour::documentType = documentType;
}

QStringList DocumentsForTour::columnList = {"ID_i", "Documents_f", "Client_f", "Document type_f"};

QStringList *DocumentsForTour::getValueList() {
    return new QStringList({QString::number(this->id), *this->document, *this->clientName, *this->documentType});
}

QStringList *DocumentsForTour::getValForAdd() {
    return getValueList();
}

DocumentsForTour::DocumentsForTour(const QStringList &args) : Model(args) {
    this->idDocument = args[1].toInt();
    this->idClient = args[2].toInt();
    this->idDocumentType = args[3].toInt();

    this->document = nullptr;
    this->clientName = nullptr;
    this->documentType = nullptr;
}
