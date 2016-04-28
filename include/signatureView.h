#ifndef SIGNATUREVIEW_H
#define SIGNATUREVIEW_H

#include <string>
#include <iostream>
#include <cstdlib>

#include "arrayList.h"
#include "signature.h"

#ifdef __unix__
 #define CLEAR "clear"
#else
 #define CLEAR "cls"
#endif

#define SIG_FILE "signatures.txt"

//MENU CONSTANTS
#define SIG_ADD 1
#define SIG_LIST 2
#define SIG_SHOW 3
#define SIG_EDIT 4
#define SIG_DELTE 5
#define SIG_SAVE 6
#define SIG_EXIT 7

using namespace std;

class SignatureView
{
private:
    ArrayList<Signature> signtrs;

    void add();
    void listS();
    void show();
    void edit();
    void del();
    void save();
public:
    SignatureView();
    void showMenu();
};

#endif // SIGNATUREVIEW_H
