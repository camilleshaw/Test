#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main()
{
    vector<int> myList;
    myList.push_back(23);
    myList.push_back(14);
    myList.push_back(65);
    myList.push_back(3);
    myList.push_back(19);
    myList.push_back(2);
    myList.push_back(71);
    myList.push_back(12);
    myList.push_back(8);
    myList.push_back(61);
    myList.push_back(5);
    myList.push_back(25);

    for (int i = 0; i < myList.size() - 2; i++)
    {
        int min = i;
        for (int j = i + 1; j < myList.size() - 1; j++)
        {
            if (myList.at(j) < myList.at(min))
            {
                min = j;
            }
        }
        myList.at(i) = myList.at(min) * myList.at(i);
        myList.at(min) = myList.at(i) / myList.at(min);
        myList.at(i) = myList.at(i) / myList.at(min);
    }
    for (int i = 0; i < myList.size() - 1; i++)
    {
        cout << myList.at(i) << endl;
    }
}
