//
// Created by rienel on 11.03.18.
//

#include "TourType.h"

TourType::TourType(int id, const std::string &name) : Model(id), name(name) {}

TourType::TourType(const std::string &name) : name(name) {}

TourType::TourType(int id) : Model(id) {}

TourType::TourType() {}

const std::string &TourType::getName() const {
    return name;
}

void TourType::setName(const std::string &name) {
    TourType::name = name;
}
