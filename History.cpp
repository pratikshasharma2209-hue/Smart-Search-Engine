#include "History.h"

void History::addSearch(string word)
{
    searches.push(word);
}
void History::displayHistory()
{
    if (searches.empty())
    {
        cout << "No Search History\n";
        return;
    }

    queue<string> temp = searches;

    cout << "\n===== Search History =====\n";

    while (!temp.empty())
    {
        cout << temp.front() << endl;
        temp.pop();
    }
}
