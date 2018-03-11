//
// Created by rienel on 11.03.18.
//

#ifndef PSQLWORK_TOUR_H
#define PSQLWORK_TOUR_H

#include <string>
#include "Model.h"

class Tour : public Model {
private:
    std::string name;
    std::string duration;
    std::string transfer;
public:
    Tour(int id, const std::string &name, const std::string &duration, const std::string &transfer);

    Tour(const std::string &name, const std::string &duration, const std::string &transfer);

    Tour(int id);

    Tour();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDuration() const;

    void setDuration(const std::string &duration);

    const std::string &getTransfer() const;

    void setTransfer(const std::string &transfer);
};


#endif //PSQLWORK_TOUR_H
