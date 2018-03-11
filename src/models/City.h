//
// Created by rienel on 11.03.18.
//

#ifndef PSQLWORK_CITY_H
#define PSQLWORK_CITY_H

#include "Model.h"
#include <string>

class City:public Model {
private:
    std::string name;
    double price;
    std::string duration;
    std::string country;
public:
    City(int id, const std::string &name, double price, const std::string &duration, const std::string &country);

    City(const std::string &name, double price, const std::string &duration, const std::string &country);

    City(int id);

    City();

    const std::string &getName() const;

    void setName(const std::string &name);

    double getPrice() const;

    void setPrice(double price);

    const std::string &getDuration() const;

    void setDuration(const std::string &duration);

    const std::string &getCountry() const;

    void setCountry(const std::string &country);
};


#endif //PSQLWORK_CITY_H
