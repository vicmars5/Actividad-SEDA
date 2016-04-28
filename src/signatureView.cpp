#include "signatureView.h"

SignatureView::SignatureView()
{
    signtrs.load(SIG_FILE);
}

void SignatureView::showMenu() {
    int op;

    do {
        system(CLEAR);
        cout << "\tGestion de Materias" << endl;
        cout << " 1.- Agregar materia" << endl
             << " 2.- Listar materias" << endl
             << " 3.- Mostrar detalles de una materia" << endl
             << " 4.- Modificar una materia" << endl
             << " 5.- Eliminar materia" << endl
             << " 6.- Guardar cambios" << endl
             << " 7.- Regresar al menu anterior" << endl
             << "Elige una opcion: ";
        cin >> op;
        cin.ignore();

        switch(op) {
        case SIG_ADD:
            add();
            break;
        case SIG_LIST:
            listS();
            break;
        case SIG_SAVE:
            save();
            break;
        case SIG_SHOW:
            show();
            break;
        case SIG_DELTE:
            del();
            break;
        case SIG_EDIT:
            edit();
            break;
        case SIG_EXIT:
            break;
        default:
            break;
        }

    } while(op != SIG_EXIT);
}
void SignatureView::add() {
    Signature s;
    string txt;
    system(CLEAR);
    cout << "\t Añadiendo asignatura" << endl;

    cout << "Nombre: ";
    getline(cin, txt);
    s.setName(txt);

    cout << "Acronimo: ";
    getline(cin, txt);
    s.setAcronym(txt);

    cout << "Profesor: ";
    getline(cin, txt);
    s.setTeacher(txt);

    cout << "Horario: ";
    getline(cin, txt);
    s.setSchedule(txt);


    try {
        signtrs.add(s);
    } catch(ArrayListException ex) {
        cout << "No se pudo guardar" << endl;
        return;
    }

    cout << "Se guardo la materia... " << endl;
    cin.get();
}

void SignatureView::listS() {
    Signature s;

    system(CLEAR);
    cout << "\tMaterias" << endl << endl;
    try {
        if(signtrs.length() >= 0)
            for(int i = 0; i < signtrs.length(); i++) {
                s = signtrs.get(i);
                cout << " Nombre: " << s.getName() << endl
                     << " Acronimo: " << s.getAcronym() << endl
                     << " Maestro: " << s.getTeacher() << endl
                     << " Horario: " << s.getSchedule() << endl << endl;
            }
    } catch(ArrayListException ex) {
        cout << "No se pudieron leer los datos" << ex.what() << endl;
    }
    cin.get();
}

void SignatureView::show() {
    Signature s;
    string txt;
    int pos;

    system(CLEAR);
    cout << "\tMostrar Detalles de Materia" << endl << endl;
    cout << " Acronimo de la materia: ";
    getline(cin, txt);
    cout << endl;

    s.setAcronym(txt);
    pos = signtrs.findD(s);

    if(pos >= 0) {
        try {
            s = signtrs.get(pos);
        } catch(ArrayListException ex) {
            cout << "No se pudo obtener la asignatura" << endl << endl;
            cin.get();
        }

        cout << " Nombre: " << s.getName() << endl
             << " Acronimo: " << s.getAcronym() << endl
             << " Maestro: " << s.getTeacher() << endl
             << " Horario: " << s.getSchedule() << endl << endl;
    } else {
        cout << "No se encontro la asignatura" << endl;
    }
    cin.get();
}

void SignatureView::del() {
    Signature s;
    string txt;
    int pos;

    system(CLEAR);
    cout << "\tEliminando Materia" << endl << endl;
    cout << " Acronimo de la asignatura: ";
    getline(cin, txt);
    cout << endl;

    s.setAcronym(txt);
    pos = signtrs.findD(s);

    if(pos >= 0) {
        try {
            s = signtrs.get(pos);
        } catch(ArrayListException ex) {
            cout << "No se pudo obtener la asignatura" << endl << endl;
        }

        cout << " Nombre: " << s.getName() << endl
             << " Acronimo: " << s.getAcronym() << endl
             << " Maestro: " << s.getTeacher() << endl
             << " Horario: " << s.getSchedule() << endl << endl;
        try {
            signtrs.del(pos);
        } catch (ArrayListException ex) {
            cout << "No se pudo eliminar la materia." << endl;
            cin.get();
        }

    } else {
        cout << "No se encontro la materia" << endl;
    }

    cin.get();
}

void SignatureView::edit() {
    Signature s;
    string txt;
    int pos;

    system(CLEAR);
    cout << "\tEditando Materia" << endl << endl;
    cout << " Acronimo de la asignatura: ";
    getline(cin, txt);
    cout << endl;

    s.setAcronym(txt);
    pos = signtrs.findD(s);

    if(pos >= 0) {
        try {
            s = signtrs.get(pos);
        } catch(ArrayListException ex) {
            cout << "No se pudo obtener la asignatura" << endl << endl;
        }

        cout << " Nombre: " << s.getName() << endl
             << " Acronimo: " << s.getAcronym() << endl
             << " Maestro: " << s.getTeacher() << endl
             << " Horario: " << s.getSchedule() << endl << endl;

        cout << " Nombre: ";
        getline(cin, txt);
        s.setName(txt);

        cout << " Acronimo: ";
        getline(cin, txt);
        s.setAcronym(txt);

        cout << " Profesor: ";
        getline(cin, txt);
        s.setTeacher(txt);

        cout << " Horario: ";
        getline(cin, txt);
        s.setSchedule(txt);

        try {
            signtrs.edit(pos, s);
            cout << "Datos guardados" << endl;
            cout << " Nombre: " << s.getName() << endl
                 << " Acronimo: " << s.getAcronym() << endl
                 << " Maestro: " << s.getTeacher() << endl
                 << " Horario: " << s.getSchedule() << endl << endl;
        } catch (ArrayListException ex) {
            cout << "No se pudieron guardar los datos. " << ex.what() << endl;
        }
    } else {
        cout << "El elemento no existe" << endl;
    }
    cin.get();
}

void SignatureView::save() {
    try {
        signtrs.save(SIG_FILE);
    } catch(ArrayListException ex) {
        cout << "No se pudo guardar la información. " << ex.what() << endl;
    }
    cout << "Se guardaron los cambios. Presione ENTRAR para continuar..." << endl;
    cin.get();
}
