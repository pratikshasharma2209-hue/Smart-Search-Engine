#ifndef HISTORY_H
#define HISTORY_H

#include <queue>
#include <string>
#include <iostream>

using namespace std;

class History
{
private:
    queue<string> searches;

public:
    void addSearch(string word);
    void displayHistory();
};

#endif