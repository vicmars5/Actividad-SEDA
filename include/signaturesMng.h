#ifndef SIGNATURESMNG_H
#define SIGNATURESMNG_H

#include <exception>

#include "arrayList.h"
#include "signature.h"

#define SIG_MNG_FILE "signatures.txt"

class SignaturesMngException : public std::exception {
private:
    std::string msg;
public:
    explicit SignaturesMngException(const char* message) : msg(message) {}
    explicit SignaturesMngException(const std::string& message) :msg(message) {}
    virtual ~SignaturesMngException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

class SignaturesMng
{
    private:
        static ArrayList<Signature> signatures;
    public:
        SignaturesMng();

        void add(const Signature& s);
        void del(const int& pos);
        Signature get(const int& pos);
        void edit(const int& pos, const Signature& s);

        int length();
        int firstPos();
        bool isValidPos(const int& pos);
        int findS(Signature& n);

        void save();
        void load();
};

#endif // SIGNATURESMNG_H
