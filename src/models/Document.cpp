//
// Created by rienel on 03.03.18.
//

#include "Document.h"

Document::Document(std::string *batch, std::string *status, std::string *dateOfIssue, std::string *issuingDepartment)
        : batch(batch), status(status), dateOfIssue(dateOfIssue), issuingDepartment(issuingDepartment) {}

Document::Document(int id, std::string *batch, std::string *status, std::string *dateOfIssue,
                   std::string *issuingDepartment) : Model(id), batch(batch), status(status), dateOfIssue(dateOfIssue),
                                                     issuingDepartment(issuingDepartment) {}

Document::Document(int id) : Model(id) {}

Document::Document() = default;


std::string *Document::getBatch() const {
    return batch;
}

void Document::setBatch(std::string *batch) {
    Document::batch = batch;
}

std::string *Document::getStatus() const {
    return status;
}

void Document::setStatus(std::string *status) {
    Document::status = status;
}

std::string *Document::getDateOfIssue() const {
    return dateOfIssue;
}

void Document::setDateOfIssue(std::string *dateOfIssue) {
    Document::dateOfIssue = dateOfIssue;
}

std::string *Document::getIssuingDepartment() const {
    return issuingDepartment;
}

void Document::setIssuingDepartment(std::string *issuingDepartment) {
    Document::issuingDepartment = issuingDepartment;
}
