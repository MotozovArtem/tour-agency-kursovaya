//
// Created by rienel on 04.03.18.
//

#ifndef PSQLWORK_STATUS_H
#define PSQLWORK_STATUS_H

#include "Model.h"
#include <string>

class Status: public Model {
private:
    std::string* name;
public:
    Status(int id, std::string *name);

    Status(std::string *name);

    Status(int id);

    Status();

    std::string *getName() const;

    void setName(std::string *name);
};


#endif //PSQLWORK_STATUS_H
