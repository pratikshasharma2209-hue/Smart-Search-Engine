#include "Trending.h"

void Trending::addSearch(string word)
{
    frequency[word]++;
}
void Trending::showTrending()
{
    if (frequency.empty())
    {
        cout << "No searches performed yet.\n";
        return;
    }

    priority_queue<pair<int, string>> pq;

    for (auto item : frequency)
    {
        pq.push({item.second, item.first});
    }

    cout << "\n===== Trending Searches =====\n";

    int count = 0;

    while (!pq.empty() && count < 5)
    {
        cout << pq.top().second
             << " (" << pq.top().first << " searches)" << endl;

        pq.pop();
        count++;
    }
}
