/*

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string st1, st2;      // n -> size of string1
	cin >> st1 >> st2;    // m -> size of string2
	int ind1 = st1.size();
	int ind2 = st2.size();
	int max_len = 0;
	//Tabulation - T.C - O(n*m) and S.C - O(n*m)
	vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, 0));
	int ans = 0;
	for (int i = 1; i <= ind1; i++)
	{
		for (int j = 1; j <= ind2; j++)
		{
			if (st1[i - 1] == st2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	cout << ans;
}