#ifndef MANAGER_H
#define MANAGER_H

#include "arrayList.h"

class ManagerException : public std::exception {
private:
    std::string msg;
public:
    explicit ManagerException(const char* message) : msg(message) {}
    explicit ManagerException(const std::string& message) :msg(message) {}
    virtual ~ManagerException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class Manager : public ArrayList<T>{
private:
    void edit(const int& pos, const T& s);
public:
    Manager() {}
    virtual ~Manager() {}
};

#endif // MANAGER_H
