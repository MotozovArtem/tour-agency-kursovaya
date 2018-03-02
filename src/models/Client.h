//
// Created by rienel on 02.03.18.
//

#ifndef PSQLWORK_CLIENT_H
#define PSQLWORK_CLIENT_H

#include "Model.h"
#include <string>

class Client : public Model {
private:
    std::string *firstName;
    std::string *name;
    std::string *patronymic;
    std::string *birthday;
    std::string *birthplace;
public:
    Client();

    Client(int id);

    Client(std::string *firstName, std::string *name, std::string *patronymic, std::string *birthday,
           std::string *birthplace);

    Client(int id, std::string *firstName, std::string *name, std::string *patronymic, std::string *birthday,
           std::string *birthplace);

    ~Client();

    std::string *getFirstName() const;

    void setFirstName(std::string *firstName);

    std::string *getName() const;

    void setName(std::string *name);

    std::string *getPatronymic() const;

    void setPatronymic(std::string *patronymic);

    std::string *getBirthday() const;

    void setBirthday(std::string *birthday);

    std::string *getBirthplace() const;

    void setBirthplace(std::string *birthplace);

};


#endif //PSQLWORK_CLIENT_H
