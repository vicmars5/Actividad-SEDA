#include "signature.h"

Signature::Signature() {
    name = "";
    acronym = "";
    teacher = "";
    schedule = "";
}

string& Signature::getName() {
    return name;
}

string& Signature::getAcronym() {
    return acronym;
}

string& Signature::getTeacher() {
    return teacher;
}

string& Signature::getSchedule() {
    return schedule;
}

void Signature::setName(const string& n) {
    name = n;
}

void Signature::setAcronym(const string& a) {
    acronym = a;
}

void Signature::setTeacher(const string& t) {
    teacher = t;
}

void Signature::setSchedule(const string& s) {
    schedule = s;
}

bool Signature::operator==(const Signature& s) const {
    return (this->acronym == s.acronym);
}
ostream& operator << (ostream& o, const Signature& s) {
    o << s.name << endl
      << s.acronym << endl
      << s.teacher << endl
      << s.schedule << endl;
    return o;
}

istream& operator >> (istream& input, Signature& s) {
    string myString;

    if(getline(input, myString))
        s.name = myString;
    if(getline(input, myString))
        s.acronym = myString;
    if(getline(input, myString))
        s.teacher = myString;
    if(getline(input, myString))
        s.schedule = myString;

    return input;
}

