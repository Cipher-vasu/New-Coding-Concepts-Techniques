#include<bits/stdc++.h>
using namespace std;

void remove_middle(stack<int>& st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    remove_middle(st, k - 1);
    st.push(temp);
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
    int k = st.size() / 2 + (st.size() % 2 == 0 ? 0 : 1);
    remove_middle(st, k);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

