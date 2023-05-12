#include <iostream>
#include <string>
#include <fstream>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[])
{
    TodoList myList;
    string firstArg = argv[1];

    if (firstArg == "add")
    {
        cout << "menu select: add" << endl;
        string date = argv[2];
        string task = argv[3];
        cout << "date: " << date << endl;
        cout << "task: " << task << endl;
        myList.add(date, task);
    }
    else if (firstArg == "remove")
    {
        cout << "menu select: remove" << endl;
        string task = argv[2];
        cout << "task: " << task << endl;
        myList.remove(task);
    }
    else if (firstArg == "printList")
    {
        cout << "menu select: print list" << endl;
        myList.printTodoList();
    }
    else if (firstArg == "printDay")
    {
        cout << "menu select: Print Day" << endl;
        string day = argv[2];
        cout << "day: " << day << endl;
        myList.printDaysTasks(day);
    }

    return 0;
}