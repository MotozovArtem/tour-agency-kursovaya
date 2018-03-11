//
// Created by rienel on 11.03.18.
//

#include "Tour.h"

const std::string &Tour::getName() const {
    return name;
}

void Tour::setName(const std::string &name) {
    Tour::name = name;
}

const std::string &Tour::getDuration() const {
    return duration;
}

void Tour::setDuration(const std::string &duration) {
    Tour::duration = duration;
}

const std::string &Tour::getTransfer() const {
    return transfer;
}

void Tour::setTransfer(const std::string &transfer) {
    Tour::transfer = transfer;
}

Tour::Tour(int id, const std::string &name, const std::string &duration, const std::string &transfer) : Model(id),
                                                                                                        name(name),
                                                                                                        duration(
                                                                                                                duration),
                                                                                                        transfer(
                                                                                                                transfer) {}

Tour::Tour(const std::string &name, const std::string &duration, const std::string &transfer) : name(name),
                                                                                                duration(duration),
                                                                                                transfer(transfer) {}

Tour::Tour(int id) : Model(id) {}

Tour::Tour() {}
