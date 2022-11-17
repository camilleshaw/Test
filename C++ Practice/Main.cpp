#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[])
{
    TodoList myList;
    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]=" << argv[i] << endl;
    }
    string firstarg = argv[1];
    if (firstarg.compare("add") == 0)
    {
        cout << "Doing an add" << endl;
        string duedate = argv[2];
        string task = argv[3];
        cout << "Duedate: " << duedate << endl;
        cout << "Task: " << task << endl;
        myList.add(duedate, task);
    }
    else if (firstarg.compare("remove") == 0)
    {
        cout << "Doing a remove" << endl;
        string task = argv[2];
        cout << "Task: " << task << endl;
        myList.remove(task);
    }
    else if (firstarg.compare("printList") == 0)
    {
        cout << "Doing a printList" << endl;
        myList.printTodoList();
    }
    else if (firstarg.compare("printDay") == 0)
    {
        cout << "Doing a printDay" << endl;
        string date = argv[2];
        cout << "Date: " << date << endl;
        myList.printDaysTasks(date);
    }
    else
    {
        cout << "Unknown command" << endl;
    }

    return 0;
}