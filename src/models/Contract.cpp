//
// Created by rienel on 04.03.18.
//

#include "Contract.h"

Contract::Contract(int id, std::string *name) : Model(id), name(name) {}

Contract::Contract(std::string *name) : name(name) {}

Contract::Contract(int id) : Model(id) {}

Contract::Contract() = default;

Contract::~Contract() = default;

std::string *Contract::getName() const {
    return name;
}

void Contract::setName(std::string *name) {
    Contract::name = name;
}
