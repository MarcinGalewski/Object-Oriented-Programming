//
// Created by student on 02.05.23.
//

#ifndef CARRENTAL_CLIENTEXCEPTION_H
#define CARRENTAL_CLIENTEXCEPTION_H

#include <stdexcept>

class ClientException : public std::logic_error{
public:
    explicit ClientException(const std::string &arg);
};


#endif //CARRENTAL_CLIENTEXCEPTION_H