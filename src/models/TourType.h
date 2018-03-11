//
// Created by rienel on 11.03.18.
//

#ifndef PSQLWORK_TOURTYPE_H
#define PSQLWORK_TOURTYPE_H

#include "Model.h"
#include <string>

class TourType: public Model {
private:
    std::string name;
public:
    TourType(int id, const std::string &name);

    TourType(const std::string &name);

    TourType(int id);

    TourType();

    const std::string &getName() const;

    void setName(const std::string &name);
};


#endif //PSQLWORK_TOURTYPE_H
