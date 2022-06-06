#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string text, pat;
    cin >> text >> pat;

    // Brute Force TC - O(text.size()*pat.size()) and SC - O(1)
    /*int flag = 0;
    for (int i = 0; i <= text.size() - pat.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < pat.size(); j++)
        {
            temp.push_back(text[i + j]);
        }
        if (temp == pat)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "pattern found" << endl;
    }
    else
    {
        cout << "pattern not found" << endl;
    }*/

    // Efficient Approach
    int flag = 0;
    string temp = "";
    for (int i = 0; i < pat.size(); i++)
    {
        temp.push_back(text[i]);
    }
    for (int i = 0; i <= text.size() - pat.size(); i++)
    {
        if (i != 0)
        {
            temp.push_back(text[i + pat.size()]);
        }
        if (temp == pat)
        {
            flag = 1;
            break;
        }
        temp.erase(temp.begin() + 0);
    }
    if (flag == 1)
    {
        cout << "pattern found" << endl;
    }
    else
    {
        cout << "pattern not found" << endl;
    }
}

