// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int val)
{
    if (st.empty() || st.top() <= val)
    {
        st.push(val);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st, val);
    st.push(temp);
}

void sorting(stack<int>& st)
{
    if (st.size() == 1)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sorting(st);
    insert(st, temp);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        st.push(a);
    }
    sorting(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
// } Driver Code Ends

//Count Common words with one occurrence
