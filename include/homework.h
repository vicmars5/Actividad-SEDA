#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <string>
#include <iostream>

using namespace std;

class Homework {
private:
    string subject;
    string description;
    string signature; //SIgnature Acronym
public:
    Homework();

    string getSubject();
    string getDescription();
    string getSignature();

    void setSubject(const string& s);
    void setDescription(const string& d);
    void setSignature(const string& s);


    bool operator == (const Homework& h) const;

    friend ostream& operator << (ostream&, const Homework& h);
    friend istream& operator >> (istream&, Homework& h);
};

#endif // HOMEWORK_H
