#include "Navigation.h"
#include <fstream>

Navigation::Navigation()
{
    numNodes = 0;
    theCosts = vector<vector<int> >();
}
Navigation::~Navigation()
{
}

// This function reads in the contents of the file _mapName.
// The function can assume that the contents of the specified conform with the specs given in the README.txt file
// Returns true if the file is read in successfully, false otherwise
bool Navigation::readNetwork(string _mapName)
{
    ifstream mapFile (_mapName.c_str());
    if (!mapFile.is_open())
    {
        cout << "Unable to open file " << _mapName << endl;
        return false;
    }
    else
    {
        string line;
        getline(mapFile, line);
        numNodes = atoi(line.c_str());
        // cout << "Number of nodes: " << numNodes << endl;
        for(int i=0; i<numNodes; i++)
            {
                vector<int> temp;
                for(int j=0; j<numNodes; j++)
                {
                    mapFile >> line;
                    temp.push_back(atoi(line.c_str()));
                }
                theCosts.push_back(temp);
                temp.clear();
            }


        // cout << "Costs: " << endl;
        // for(int i=0; i<numNodes; i++)
        // {
        //     for(int j=0; j<numNodes; j++)
        //     {
        //         cout << theCosts[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        mapFile.close();
        return true;
     }
}

// This function computes and returns the least-cost path from node indexed _startInd to node indexed as _endInd
// for the map that was last read (in the readMap function).  The resulting path must be stored in an integer queue
// with each entry in the queue denoting the next node in the path.  First front of the queue should be _startInd
// and the back of the queue should be _endInd.
// For example, in map1.txt, solveMap(13, 1) should return the shortest path from node 13 to node 1, which is:
//      13, 9, 10, 7, 3, 2, 1
// You can assume that readNetwork(_mapName) is called before this function and that a path from _startInd to _endInd exists
queue<int> Navigation::computeShortestPath(int _startInd, int _endInd)
{
    queue<int> path;

    priority_queue<Node, vector<Node>, Node> myPriorityQueue;

    Node n;
    n.cost = 0;
    n.path.push(_startInd);
    myPriorityQueue.push(n);

    while(myPriorityQueue.top().path.back() != _endInd)
    {
        Node currentNode = myPriorityQueue.top();
        myPriorityQueue.pop();
        int last = currentNode.path.back();
        for(int i=0; i<numNodes; i++)
        {
            if(theCosts[last][i] > 0)
            {
                Node newNode;
                newNode.cost = currentNode.cost + theCosts[last][i];
                newNode.path = currentNode.path;
                newNode.path.push(i);
                myPriorityQueue.push(newNode);
            }
        }
    }

    return myPriorityQueue.top().path;
}

// prints out to the console the path stored in _path
void Navigation::printPath(queue<int> _path)
{
    while(!_path.empty())
    {
        cout << _path.front() << " ";
        _path.pop();
    }
    cout << endl;
}