#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <list>
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> tokens;
    set<string> unique;
    string next_line; // Each data line
    string filename = argv[1];
    ifstream in(argv[1]);
    while (getline(in, next_line))
    {
        istringstream iss(next_line);
        string token;
        while (iss >> token)
        {
            string nopunct = "";
            for (auto &c : token)
            { // Remove Punctuation
                if (isalpha(c))
                {
                    nopunct += c;
                }
            }
            tokens.push_back(nopunct);
            unique.insert(nopunct);
            // cout << token<<endl;
        }
    }
    cout << "Number of words " << tokens.size() << endl;
    cout << "Number of unique words " << unique.size() << endl;

    ofstream setFile(filename + "_set.txt");

    for (set<string>::iterator it = unique.begin(); it != unique.end(); ++it)
    {
        setFile << *it << endl;
    }
    cout << endl;

    // put the values into a map

    // map<string, string> wordMap;
    // string last = "";
    // for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    // {
    //     wordMap[last] = *it;
    //     last = *it;
    // }

    // ofstream mapFile(filename + "_map.txt");
    // for (map<string, string>::iterator it = wordMap.begin(); it != wordMap.end(); ++it)
    // {
    //     cout << "first"
    //          << " => " << it->first << " second " << it->second << endl;
    //     mapFile << it->first << "," << it->second << endl;
    // }

    // map<string, vector<string>> wordMap;
    // string state = "";
    // for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    // {
    //     wordMap[state].push_back(*it);
    //     state = *it;
    // }

    map<list<string>, vector<string>> wordMap;
    list<string> state;
    const int M = 3;
    for (int i = 0; i < M; i++)
    {
        state.push_back("");
    }

    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        wordMap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }

    srand(time(NULL)); // this line initializes the random number generated
                       // so you dont get the same thing every time

    state.clear();
    for (int i = 0; i < M; i++)
    {
        state.push_back("");
    }
    for (int i = 0; i < 100; i++)
    {
        int ind = rand() % wordMap[state].size();
        cout << wordMap[state][ind] << " ";
        state.push_back(wordMap[state][ind]);
        state.pop_front();
    }

    // state = "";
    // for (int i = 0; i < 100; i++)
    // {
    //     int ind = rand() % wordMap[state].size();
    //     cout << wordMap[state][ind] << " ";
    //     state = wordMap[state][ind];
    // }
    // cout << endl;
}