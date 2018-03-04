//
// Created by rienel on 04.03.18.
//

#include "Status.h"

Status::Status(int id, std::string *name) : Model(id), name(name) {}

Status::Status(std::string *name) : name(name) {}

Status::Status(int id) : Model(id) {}

Status::Status() = default;

std::string *Status::getName() const {
    return name;
}

void Status::setName(std::string *name) {
    Status::name = name;
}
