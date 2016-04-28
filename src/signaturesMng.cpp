#include "signaturesMng.h"

ArrayList<Signature> SignaturesMng::signatures;

SignaturesMng::SignaturesMng() {
    load();
}


void SignaturesMng::add(const Signature& s) {
    try {
        signatures.insertData(signatures.getLastPos(), s);
    } catch(ArrayListException ex) {
        throw SignaturesMngException(ex.what());
    }
}

void SignaturesMng::del(const int& pos) {
    try {
        signatures.deleteData(pos);
    } catch(ArrayListException ex) {
        throw SignaturesMngException(ex.what());
    }
}

Signature SignaturesMng::get(const int& pos) {
    try {
        return signatures.retrieve(pos);
    } catch(ArrayListException ex) {
        throw SignaturesMngException(ex.what());
    }
}

void SignaturesMng::edit(const int& pos, const Signature& s) {
    try {
        signatures.insertData(pos, s);
        signatures.deleteData(pos);
    } catch(ArrayListException ex) {
        throw SignaturesMngException(ex.what());
    }
}

int SignaturesMng::length() {
    return signatures.length();
}

int SignaturesMng::firstPos() {
    int p = signatures.getFirstPos();
    return p;
}

bool SignaturesMng::isValidPos(const int& pos) {
    return signatures.isValidPos(pos);
}

int SignaturesMng::findS(Signature& s) {
    return signatures.findData(s);
}

void SignaturesMng::save() {
    try {
        signatures.writeToDisk(SIG_MNG_FILE);
    } catch(ArrayListException ex) {
        SignaturesMngException(ex.what());
    }
}

void SignaturesMng::load()
{
    try{
        signatures.readFromDisk(SIG_MNG_FILE);
    } catch (ArrayListException ex) {
        SignaturesMngException(ex.what());
    }
}
