#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ./chiste [add/remove/tellme] "dad joke"
// Example: ./chiste add "Hi Hungry, I'm Dad"
// Example: ./chiste remove "Hi Hungry"
// Example: ./chiste tellme
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "You didn't supply a dad joke!" << endl;
        return -1;
    }

    string mandamento = argv[1];
    string dadJoke1 = argv[2];

    if (mandamento == "add")
    {
        ofstream myfile;
        myfile.open("dad_jokes.txt", ios::app);
        myfile << argv[2] << endl;
        myfile.close();

        cout << "You just supplied me with a hilarious dad joke: " << argv[2] << endl;
    }
    else if (mandamento == "remove")
    {
        string line;
        ifstream myfile("dad_jokes.txt");
        ofstream temp("temp.txt");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                if (line != dadJoke1)
                {
                    temp << line << endl;
                }
            }
            myfile.close();
            temp.close();
            remove("dad_jokes.txt");
            rename("temp.txt", "dad_jokes.txt");
        }
    }
    else if (mandamento == "tellme")
    {
        string line;
        ifstream myfile("dad_jokes.txt");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                cout << line << endl;
            }
            myfile.close();
        }
    }
    else
    {
        cout << "Invalid command" << endl;
    }
    // string dadJoke1 = argv[1];

    // // open the file
    // ofstream output;
    // output.open("dadjokes.txt", ios_base::app);

    // output << dadJoke1 << endl;

    // // close the file
    // output.close();

    // cout << "argc: " << argc << endl;

    // cout << "argv[0]: " << argv[0] << endl;

    // for (int i = 0; i < argc; i++)
    //  {
    //      cout << "the " << i << "the argument is " << argv[i] << endl;
    //  }

    // string dadJoke1;
    // cout << "Enter a GOOD dad joke: " << endl;

    // cin >> dadJoke1;
    // getline(cin, dadJoke1);

    // cout << "This is the dad joke: " << dadJoke1 << endl;

    // return 0;
}