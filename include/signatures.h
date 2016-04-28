#ifndef SIGNATURES_H
#define SIGNATURES_H

#include <string>
#include <iostream>
#include <cstdlib>

#include "arrayList.h"
#include "signaturesMng.h"

#ifdef __unix__
 #define CLEAR "clear"
#else
 #define CLEAR "cls"
#endif

//CONSTANTS
#define SIG_ADD 1
#define SIG_LIST 2
#define SIG_SHOW 3
#define SIG_EDIT 4
#define SIG_DELTE 5
#define SIG_SAVE 6
#define SIG_EXIT 7

using namespace std;

class Signatures {
private:
    SignaturesMng signatures;


public:
    Signatures();
    void showMenu();

    void add();
    void listS();
    void save();
    void edit();

};

#endif // SIGNATURES_H
