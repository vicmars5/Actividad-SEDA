#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <string>
#include <fstream>
#include <iostream> //Delete it when finish the work

#define FIRST_POS -1
#define ARR_FIRST_POS 0

using namespace std;

class ArrayListException : public std::exception {
private:
    std::string msg;
public:
    explicit ArrayListException(const char* message) : msg(message) {}
    explicit ArrayListException(const std::string& message) :msg(message) {}
    virtual ~ArrayListException() throw () {}
    virtual const char* what() const throw () {
        return msg.c_str();
    }
};

template <class T>
class ArrayList {
private:
    T *data;
    int last;


public:
    ArrayList();
    virtual ~ArrayList();

    bool isEmpty();
    bool isValidPos(const int& pos);

    void insertData(const int& pos, const T& dato);
    void deleteData(const int& pos);

    int getFirstPos();
    int getLastPos();
    int& getPrevPos(const int& pos);
    int& getNextPos(const int& pos);

    T retrieve(const int& pos);

    int findData(const T& bus);

    void deleteAll();

    void writeToDisk(const string& fName);
    void readFromDisk(const string& fName);

    int length();

    void print(); //DELETE WHEN FINISH THE WORK
};

template <class T>
bool ArrayList<T>::isValidPos(const int& pos) {
    return pos >= 0 and pos <= last;
}

template <class T>
ArrayList<T>::ArrayList() {
    last = FIRST_POS;
    data = new T[FIRST_POS + 1];
}

template <class T>
ArrayList<T>::~ArrayList() {
    if(data != nullptr)
        delete[] data;
}

template <class T>
bool ArrayList<T>::isEmpty() {
    return (last < 0);
}

template <class T>
int ArrayList<T>::length() {
    return last + 1;
}

template <class T>
void ArrayList<T>::insertData(const int& pos, const T& dato) {
    int i;

    T* aux = new T[length() + 1]; //New array

    if(pos != -1 and !isValidPos(pos)) {
        throw ArrayListException("NO VALID POSTION");
    }

    for(i = last; i > pos; i--){
        aux[i + 1] = data[i];
    }

    aux[i + 1] = dato;

    for(i = i; i >= 0; i--){
        aux[i] = data[i];
    }

    delete[] data;
    data =  aux;

    last++;
}

template <class T>
void ArrayList<T>::deleteData(const int& pos) {
    int i;
    int newLast = last - 1;
    T* aux = new T[length() - 1];

    if(isEmpty()) {
        throw ArrayListException("NO DATA ON ARRAY, CAN'T DELETE IT");
    }

    if(!isValidPos(pos)) {
        throw ArrayListException("INVALID POSITION");
    }

    for(i = 0; i < pos; i++){
        aux[i] = data[i];
    }

    for(i = i; i <= newLast; i++){
        aux[i] = data[i + 1];
    }

    delete[] data;
    data = aux;
    last--;
}

template <class T>
int ArrayList<T>::getFirstPos() {
    if(isEmpty()) {
        return FIRST_POS;
    }
    return ARR_FIRST_POS;
}

template <class T>
int ArrayList<T>::getLastPos() {
    return last;
}

template <class T>
int& ArrayList<T>::getPrevPos(const int& pos) {
    if(!isValidPos() or isEmpty()) {
        return -1;
    }

    return pos - 1;
}

template <class T>
int& ArrayList<T>::getNextPos(const int& pos) {
    if(isEmpty() or !isValidPos(pos) or pos == last) {
        return -1;
    }
    return pos - 1;
}

template <class T>
T ArrayList<T>::retrieve(const int& pos) {
    if(isEmpty()) {
        throw ArrayListException("LIST EMPTY, ERROR TRYING GET DATA");
    }
    if(!isValidPos(pos)) {
        throw ArrayListException("INVALID POSITION, ERROR TRYING TO GET DATA");
    }
    return data[pos];
}

template <class T>
int ArrayList<T>::findData(const T& bus) {
    for(int i = (ARR_FIRST_POS) ; i <= last; i++) {
        if (data[i] == bus){
            return i;
        }
    }

    return FIRST_POS;
}

template <class T>
void ArrayList<T>::deleteAll() {
    if(last == FIRST_POS){
        last = FIRST_POS;
        delete data;
        data = new T[FIRST_POS + 1];
    }
}


template <class T>
void ArrayList<T>::writeToDisk(const string& fName) {
    ofstream file;
    file.open(fName.c_str(), ios_base::out);
    int i;
    if(isEmpty()) {
        throw ArrayListException("NO DATA, CAN'T WRITE IN DISK");
    }

    if(file.is_open()) {
        for(i = (ARR_FIRST_POS); i <= last; i++){
            file << data[i];
        }

        file.close();
    } else {
        throw ArrayListException("CAN'T OPEN THE FILE");
    }
}

template <class T>
void ArrayList<T>::readFromDisk(const string& fName) {
    ifstream file;
    file.open(fName.c_str(), ios_base::in);

    T d;

    if(!file.is_open()) {
        throw ArrayListException("ERROR, CAN'T READ THE DISK");
    }


    try {
        while(file >> d) {
            insertData(getLastPos(), d);
        }
    } catch (ArrayListException ex) {
        ArrayListException("ERROR, CAN'T INSERT DISK DATA");
    }
}

///Delete it
template <class T>
void ArrayList<T>::print() {
    for(int i = 0; i <= last; i++) {
        cout << data[i] << endl;
    }
}

#endif // ARRAYLIST_H
