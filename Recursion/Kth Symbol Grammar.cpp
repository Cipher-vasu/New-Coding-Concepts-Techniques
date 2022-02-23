
#include<bits/stdc++.h>
using namespace std;

/* My approach gives tle for greater values like 30
string st;

void helper(int n)
{
    if (n == 1)
    {
        st.push_back('0');
        return;
    }
    helper(n - 1);
    string s = "";
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] == '0')
        {
            s.push_back('0');
            s.push_back('1');
        }
        else
        {
            s.push_back('1');
            s.push_back('0');
        }
    }
    st = s;
}
*/

int remove_duplicates(int n, int k)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }
    /*st = "";
    helper(n);
    return st[k - 1] - 48;*/

    //Efficient Approach
    int p = (int)pow(2, n);
    int mid = p / 2;
    if (k <= mid)
    {
        return remove_duplicates(n - 1, k);
    }

    return !remove_duplicates(n - 1, k - mid);

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    int len = remove_duplicates(n, k);
    cout << len;
    return 0;
}

