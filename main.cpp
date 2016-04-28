#include <iostream>
#include <cstdlib>

#include "signatures.h"


#ifdef __unix__
 #define CLEAR "clear"
#else
 #define CLEAR "cls"
#endif

#define OP_COURSE_EVAL 1 //Option course evaluation
#define OP_SUBJ_MNG 2 //Option subjects managment
#define OP_HWORK_MNG 3 //Option homework managment
#define EXIT 4 //Option managment

using namespace std;


int main() {
    int op;

    Signatures signatures;
    do {
        system(CLEAR);
        cout << "\tMEN\xe9 PRINCIPAL" << endl
             << " 1. Evaluaci\xa2n del curso" << endl
             << " 2. Gesti\xa2n de materias" << endl
             << " 3. Gesti\xa2n de tareas" << endl
             << " 4. Salir" << endl;
        cin >> op;
        cin.ignore();

        switch(op) {
        case OP_COURSE_EVAL:
            break;

        case OP_SUBJ_MNG:
            signatures.showMenu();
            break;

        case OP_HWORK_MNG:
            break;

        case EXIT:
            break;

        default:
            break;
        }

    } while(op != EXIT);

    return 0;
}
