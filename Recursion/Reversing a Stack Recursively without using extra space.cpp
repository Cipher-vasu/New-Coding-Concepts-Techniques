#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>& st, int temp)
{
    if (st.empty())
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void reverse_stack(stack<int>& st)
{
    if (st.size() <= 1)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverse_stack(st);
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
    print(st);
    reverse_stack(st);
    print(st);
    return 0;
}

