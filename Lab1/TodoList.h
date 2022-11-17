#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class TodoList
{
public:
    vector<string> tasks;
    TodoList()
    {
        // cout << "TodoList constructor" << endl;

        // Open the file
        ifstream infile("TODOList.txt");
        string line;
        if (infile.is_open())
        {
            while (getline(infile, line))
            {
                // cout << line << endl;
                tasks.push_back(line);
            }
            infile.close();
        }
        else
        {
            cout << "Unable to open file" << endl;
        }
    }
    ~TodoList()
    {
        // cout << "TodoList destructor" << endl;
        ofstream outfile;
        outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);
        for (int i = 0; i < tasks.size(); i++)
        {
            outfile << tasks[i] << endl;
        }
        outfile.close();
    }

    /*
     *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
     */
    void add(string _duedate, string _task)
    {
        // cout << "In add " << _duedate << " " << _task << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].find(_duedate) != string::npos)
            {
                tasks.insert(tasks.begin() + i + 1, _task);
                return;
            }
        }
        tasks.push_back(_duedate);
        tasks.push_back(_task);
    }

    /*
     *   Removes an item from the todo list with the specified task name
     *
     *   Returns 1 if it removes an item, 0 otherwise
     */
    int remove(string _task)
    {
        // cout << "In remove" << endl;

        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].find(_task) != string::npos)
            {
                tasks.erase(tasks.begin() + i);
                return 1;
            }
        }
        return 0;
    }

    /*
     *   Prints out the full todo list to the console
     */
    void printTodoList()
    {
        // cout << "In list" << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << tasks[i] << endl;
        }
    }

    /*
     *   Prints out all items of a todo list with a particular due date (specified by _duedate)
     */
    void printDaysTasks(string _date)
    {
        // cout << "In daysTasks" << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (tasks[i].find(_date) != string::npos)
            {
                while (tasks[i + 1] != "Monday" && tasks[i + 1] != "Tuesday" && tasks[i + 1] != "Wednesday" && tasks[i + 1] != "Thursday" && tasks[i + 1] != "Friday" && tasks[i + 1] != "Saturday" && tasks[i + 1] != "Sunday" && i + 1 < tasks.size())
                {
                    cout << tasks[i + 1] << endl;
                    i++;
                }
            }
        }
    }
};

#endif