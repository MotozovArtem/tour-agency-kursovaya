//
// Created by rienel on 03.03.18.
//

#ifndef PSQLWORK_DOCUMENT_H
#define PSQLWORK_DOCUMENT_H

#include <string>
#include "Model.h"

class Document : public Model {
private:
    std::string *batch;
    std::string *status;
    std::string *dateOfIssue;
    std::string *issuingDepartment;
public:
    Document(int id, std::string *batch, std::string *status, std::string *dateOfIssue, std::string *issuingDepartment);

    Document(std::string *batch, std::string *status, std::string *dateOfIssue, std::string *issuingDepartment);

    Document(int id);

    Document();

    std::string *getIssuingDepartment() const;

    void setIssuingDepartment(std::string *issuingDepartment);

    std::string *getBatch() const;

    void setBatch(std::string *batch);

    std::string *getStatus() const;

    void setStatus(std::string *status);

    std::string *getDateOfIssue() const;

    void setDateOfIssue(std::string *dateOfIssue);
};


#endif //PSQLWORK_DOCUMENT_H
