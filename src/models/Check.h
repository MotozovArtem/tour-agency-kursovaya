//
// Created by rienel on 04.03.18.
//

#ifndef PSQLWORK_CHECK_H
#define PSQLWORK_CHECK_H

#include "Model.h"
#include <string>

class Check: public Model {
private:
    std::string* dateOfPayment;
    float total;
    std::string* status;
    int idStatus;
public:
    virtual ~Check();

    Check(int id, std::string *dateOfPayment, float total, int idStatus);

    Check(std::string *dateOfPayment, float total, int idStatus);

    Check(int id);

    Check();

    std::string *getDateOfPayment() const;

    void setDateOfPayment(std::string *dateOfPayment);

    float getTotal() const;

    void setTotal(float total);

    std::string *getStatus() const;

    void setStatus(std::string *status);

    int getIdStatus() const;

    void setIdStatus(int idStatus);
};


#endif //PSQLWORK_CHECK_H
