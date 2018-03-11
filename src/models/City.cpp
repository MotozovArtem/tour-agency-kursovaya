//
// Created by rienel on 11.03.18.
//

#include "City.h"

City::City(int id, const std::string &name, double price, const std::string &duration, const std::string &country)
        : Model(id), name(name), price(price), duration(duration), country(country) {}

City::City(const std::string &name, double price, const std::string &duration, const std::string &country) : name(name),
                                                                                                             price(price),
                                                                                                             duration(
                                                                                                                     duration),
                                                                                                             country(country) {}

City::City(int id) : Model(id) {}

City::City() {}

const std::string &City::getName() const {
    return name;
}

void City::setName(const std::string &name) {
    City::name = name;
}

double City::getPrice() const {
    return price;
}

void City::setPrice(double price) {
    City::price = price;
}

const std::string &City::getDuration() const {
    return duration;
}

void City::setDuration(const std::string &duration) {
    City::duration = duration;
}

const std::string &City::getCountry() const {
    return country;
}

void City::setCountry(const std::string &country) {
    City::country = country;
}
