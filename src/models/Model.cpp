//
// Created by rienel on 02.03.18.
//

#include "Model.h"

int Model::getId() {
    return this->id;
}

void Model::setId(int id) {
    this->id = id;
}

Model::Model() = default;

Model::Model(int id) {
    this->id = id;
}

Model::~Model() = default;