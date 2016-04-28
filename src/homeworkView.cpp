#include "homeworkView.h"

HomeworkView::HomeworkView() {
    homeworks.load(HWV_FILE);
}

void HomeworkView::showMenu() {
    int op;

    do {
        system(CLEAR);
        cout << "\tGestion de tareas" << endl;
        cout << " 1.- Agregar tarea" << endl
             << " 2.- Listar tareas" << endl
             << " 3.- Mostrar detalles de una tarea" << endl
             << " 4.- Modificar una tarea" << endl
             << " 5.- Eliminar tarea" << endl
             << " 6.- Guardar cambios" << endl
             << " 7.- Regresar al menu anterior" << endl
             << " Elige una opcion: ";
        cin >> op;
        cin.ignore();
        cout << endl;

        switch(op) {
        case HWV_ADD:
            add();
            break;
        case HWV_LIST:
            listD();
            break;
        case HWV_SAVE:
            save();
            break;
        case HWV_SHOW:
            show();
            break;
        case HWV_DELTE:
            del();
            break;
        case HWV_EDIT:
            edit();
            break;
        case HWV_EXIT:
            break;
        default:
            break;
        }

    } while(op != HWV_EXIT);

}

void HomeworkView::add() {
    Homework h;
    string txt;
    system(CLEAR);
    cout << "\t Añadiendo Tarea" << endl;

    cout << "Asunto: ";
    getline(cin, txt);
    h.setSubject(txt);

    cout << "Description: ";
    getline(cin, txt);
    h.setDescription(txt);

    cout << "Materia (Acronimo): ";
    getline(cin, txt);
    h.setSignature(txt);

    try{
        homeworks.add(h);
    } catch (ArrayListException ex) {
        cout << "No se pudo guardar. " << ex.what() << endl;
        cin.get();
    }

    cout << "Se guardo la tarea. Presione ENTRAR para continuar..." << endl;
    cin.get();
}

void HomeworkView::listD() {
    Homework h;

    system(CLEAR);
    cout << "\tTareas" << endl << endl;
    try {
        if(homeworks.length() >= 0)
            for(int i = 0; i < homeworks.length(); i++) {
                h = homeworks.get(i);
                print(h);
            }
    } catch(ArrayListException ex) {
        cout << "No se pudieron leer los datos" << ex.what() << endl;
    }
    cin.get();
}

void HomeworkView::show() {
    Homework h;
    string txt;
    int pos;

    system(CLEAR);
    cout << "\tMostrar Detalles de Tarea" << endl << endl;
    cout << " Asunto de la tarea: ";
    getline(cin, txt);
    cout << endl;

    h.setSubject(txt);
    pos = homeworks.findD(h);

    if(pos >= 0) {
        try{
            h = homeworks.get(pos);
        } catch(ArrayListException ex) {
            cout << "No se pudo obtener la tarea. " << ex.what() << endl;
            cin.get();
        }

        print(h);
    } else {
        cout << "No se encontro la tarea" << endl;
    }
    cin.get();
}

void HomeworkView::edit() {

}

void HomeworkView::del() {

}

void HomeworkView::save() {
    try{
        homeworks.save(HWV_FILE);
    } catch(ArrayListException ex) {
        cout << " Error al guardar archivos" << endl;
        cin.get();
    }
    cout << " Se guardaron los cambios. Presione ENTRAR para continuar..." << endl;
    cin.get();
}
void HomeworkView::print(Homework& h) {
    cout << " Asunto: " << h.getSubject() << endl
         << " Descripción: " << h.getDescription() << endl
         << " Materia: " << h.getSignature() << endl << endl;
}


