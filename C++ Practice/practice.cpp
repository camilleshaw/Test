#include <list>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    list<int> nums;
    nums.push_back(1);
    nums.push_back(4); 
    nums.push_back(7);
    nums.push_front(10);
    cout << nums.back() << " ";
    cout << nums.front() << " ";
    nums.pop_front();
    nums.pop_back();
    cout << nums.back() << " ";
    cout << nums.front() << " ";
}