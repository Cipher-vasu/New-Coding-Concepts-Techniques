/*For question refernce see episode 16 of Luv sir
this question is of hard type and is a concept of prefix and hashing combination
In this question we are givena string and for each query two indexes l and r are given
we have to check whether the substring from l to r   is palindrome or not*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int hash[27][n + 1];
        memset(hash, 0, sizeof(hash));
        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 96][i + 1] = 1;
        }

        for (int i = 1; i <= 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hash[i][j] += hash[i][j - 1];
            }
        }
        /*for (int i = 1; i <= 5; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << hash[i][j] << " ";
            }
            cout << endl;
        }*/
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int odd = 0;
            for (int i = 1; i <= 26; i++)
            {
                if ((hash[i][r] - hash[i][l - 1]) % 2 == 1)
                {
                    odd++;
                }
            }
            //cout << odd << endl;
            if (odd > 1)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}