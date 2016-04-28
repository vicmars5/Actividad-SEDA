#ifndef HOMEWORKVIEW_H
#define HOMEWORKVIEW_H

#include <string>
#include <iostream>
#include <cstdlib>

#include "arrayList.h"
#include "homework.h"

#ifdef __unix__
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif

#define HWV_FILE "homeworks.txt"

//CONSTANTS
#define HWV_ADD 1
#define HWV_LIST 2
#define HWV_SHOW 3
#define HWV_EDIT 4
#define HWV_DELTE 5
#define HWV_SAVE 6
#define HWV_EXIT 7

class HomeworkView {
private:
    ArrayList<Homework> homeworks;

    void add();
    void listD();
    void show();
    void edit();
    void del();
    void save();

    void print(Homework& h);
public:
    HomeworkView();
    void showMenu();
};

#endif // HOMEWORKVIEW_H
