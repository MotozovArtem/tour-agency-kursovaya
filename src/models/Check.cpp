//
// Created by rienel on 04.03.18.
//

#include "Check.h"

Check::Check(int id, std::string *dateOfPayment, float total, int idStatus) : Model(id), dateOfPayment(dateOfPayment),
                                                                              total(total), idStatus(idStatus) {}

Check::Check(std::string *dateOfPayment, float total, int idStatus) : dateOfPayment(dateOfPayment), total(total),
                                                                      idStatus(idStatus) {}

Check::Check(int id) : Model(id) {}

Check::Check() = default;

std::string *Check::getDateOfPayment() const {
    return dateOfPayment;
}

void Check::setDateOfPayment(std::string *dateOfPayment) {
    Check::dateOfPayment = dateOfPayment;
}

float Check::getTotal() const {
    return total;
}

void Check::setTotal(float total) {
    Check::total = total;
}

std::string *Check::getStatus() const {
    return status;
}

void Check::setStatus(std::string *status) {
    Check::status = status;
}

int Check::getIdStatus() const {
    return idStatus;
}

void Check::setIdStatus(int idStatus) {
    Check::idStatus = idStatus;
}

Check::~Check() = default;
