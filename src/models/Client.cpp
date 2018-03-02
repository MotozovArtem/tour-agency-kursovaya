//
// Created by rienel on 02.03.18.
//

#include "Client.h"

Client::Client() : Model() {

}

Client::Client(int id) : Model(id) {
    this->birthday = nullptr;
    this->birthplace = nullptr;
    this->firstName = nullptr;
    this->name = nullptr;
    this->patronymic = nullptr;
}

Client::Client(int id, std::string *firstName, std::string *name, std::string *patronymic, std::string *birthday,
               std::string *birthplace) : Model(id) {
    this->firstName = firstName;
    this->name = name;
    this->patronymic = patronymic;
    this->birthday = birthday;
    this->birthplace = birthplace;
}

Client::Client(std::string *firstName, std::string *name, std::string *patronymic, std::string *birthday,
               std::string *birthplace) : Model() {
    this->firstName = firstName;
    this->name = name;
    this->patronymic = patronymic;
    this->birthday = birthday;
    this->birthplace = birthplace;
}

Client::~Client() : ~Model() {
    delete this->firstName;
    delete this->name;
    delete this->patronymic;
    delete this->birthday;
    delete this->birthplace;
}

std::string *Client::getFirstName() const{
    return this->firstName;
}

void Client::setFirstName(std::string *firstName) {
    this->firstName = firstName;
}

std::string *Client::getName() const {
    return this->name;
}

void Client::setName(std::string *name) {
    this->name = name;
}

std::string* Client::getPatronymic() const{
    return this->patronymic;
}

void Client::setPatronymic(std::string *patronymic) {
    this->patronymic=patronymic;
}

std::string* Client::getBirthday() const{
    return this->birthday;
}

void Client::setBirthday(std::string *birthday) {
    this->birthday = birthday;
}

std::string* Client::getBirthplace() const {
    return this->birthplace;
}

void Client::setBirthplace(std::string *birthplace) {
    this->birthplace=birthplace;
}



