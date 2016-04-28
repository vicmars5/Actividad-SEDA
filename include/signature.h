#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <string>
#include <iostream>
#include <regex>

using namespace std;

class Signature {
private:
    string name;
    string acronym;
    string teacher;
    string schedule;
public:
    Signature();

    string& getName();
    string& getAcronym();
    string& getTeacher();
    string& getSchedule();

    void setName(const string& n);
    void setAcronym(const string& a);
    void setTeacher(const string& t);
    void setSchedule(const string& s);

    bool operator == (const Signature& s) const;

    friend ostream& operator << (ostream&, const Signature& s);
    friend istream& operator >> (istream&, Signature& s);
};

#endif // SIGNATURE_H
