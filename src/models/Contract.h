//
// Created by rienel on 04.03.18.
//

#ifndef PSQLWORK_CONTRACT_H
#define PSQLWORK_CONTRACT_H

#include "Model.h"
#include <string>

class Contract : public Model {
private:
    std::string *name;
public:
    Contract(int id, std::string *name);

    Contract(std::string *name);

    Contract(int id);

    Contract();

    virtual ~Contract();

    std::string *getName() const;

    void setName(std::string *name);

};


#endif //PSQLWORK_CONTRACT_H
