//
// Created by rienel on 04.03.18.
//

#include "DocumentType.h"

DocumentType::DocumentType(int id, std::string *name) : Model(id), name(name) {}

DocumentType::DocumentType(std::string *name) : name(name) {}

DocumentType::DocumentType(int id) : Model(id) {}

DocumentType::DocumentType() = default;

std::string *DocumentType::getName() const {
    return name;
}

void DocumentType::setName(std::string *name) {
    DocumentType::name = name;
}
