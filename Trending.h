#ifndef TRENDING_H
#define TRENDING_H

#include <unordered_map>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

class Trending
{
private:
    unordered_map<string, int> frequency;

public:
    void addSearch(string word);
    void showTrending();
};

#endif