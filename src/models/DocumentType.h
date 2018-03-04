//
// Created by rienel on 04.03.18.
//

#ifndef PSQLWORK_DOCUMENTTYPE_H
#define PSQLWORK_DOCUMENTTYPE_H


#include "Model.h"
#include <string>

class DocumentType: public Model {
private:
    std::string* name;
public:
    std::string *getName() const;

    DocumentType(int id, std::string *name);

    DocumentType(std::string *name);

    DocumentType(int id);

    DocumentType();

    void setName(std::string *name);
};


#endif //PSQLWORK_DOCUMENTTYPE_H
