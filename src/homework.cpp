#include "homework.h"

Homework::Homework() {
    subject = "";
    description = "";
    signature =  "";
}

string Homework::getSubject() {
    return subject;
}

string Homework::getDescription() {
    return description;
}

string Homework::getSignature() {
    return signature;
}

void Homework::setSubject(const string& s) {
    subject = s;
}

void Homework::setDescription(const string& d) {
    description = d;
}

void Homework::setSignature(const string& s) {
    signature = s;
}

bool Homework::operator==(const Homework& h) const {
    return (this->subject == h.subject);
}


ostream& operator << (ostream& o, const Homework& h) {

    o << h.subject<< endl
      << h.description << endl
      << h.signature << endl;

    return o;
}

istream& operator >> (istream& input, Homework& h) {
    string myString;

    if(getline(input, myString))
        h.subject = myString;
    if(getline(input, myString))
        h.description = myString;
    if(getline(input, myString))
        h.signature= myString;

    return input;
}
