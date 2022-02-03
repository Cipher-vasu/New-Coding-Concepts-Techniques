// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& vec, int val)
{
    if (vec.size() == 0 || vec[vec.size() - 1] <= val)
    {
        vec.push_back(val);
        return;
    }
    int temp = vec[vec.size() - 1];
    vec.pop_back();
    insert(vec, val);
    vec.push_back(temp);
}

void sorting(vector<int>& vec)
{
    if (vec.size() == 1)
    {
        return;
    }
    int temp = vec[vec.size() - 1];
    vec.pop_back();
    sorting(vec);
    insert(vec, temp);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    sorting(vec);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}
// } Driver Code Ends

//Count Common words with one occurrence
