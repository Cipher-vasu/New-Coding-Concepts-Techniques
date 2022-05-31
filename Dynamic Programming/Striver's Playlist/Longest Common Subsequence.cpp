/*

*/
#include<bits/stdc++.h>
using namespace std;

// Recursion - TC - O(2^n * 2^m)exponential and SC-O(n+m)
// Memoization - TC - O(n*m) and SC - O(n*m) + O(n+m)
/*
int lcs(string st1, string st2, int ind1, int ind2, vector<vector<int>>& dp)
{
	if (ind1 == 0 || ind2 == 0)
	{
		return 0;
	}
	if (dp[ind1][ind2] != -1)
	{
		return dp[ind1][ind2];
	}

	if (st1[ind1 - 1] == st2[ind2 - 1])
	{
		return dp[ind1][ind2] = 1 + lcs(st1, st2, ind1 - 1, ind2 - 1, dp);
	}
	return dp[ind1][ind2] = max(lcs(st1, st2, ind1 - 1, ind2, dp), lcs(st1, st2, ind1, ind2 - 1, dp));
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string st1, st2;      // n -> size of string1
	cin >> st1 >> st2;    // m -> size of string2
	int ind1 = st1.size();
	int ind2 = st2.size();

	//Tabulation - T.C - O(n*m) and S.C - O(n*m)
	/*vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, 0));
	//cout << lcs(st1, st2, ind1, ind2, dp);

	for (int i = 1; i <= ind1; i++)
	{
		for (int j = 1; j <= ind2; j++)
		{
			if (st1[i - 1] == st2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[ind1][ind2];*/

	// Space Optimization - T.C - O(n*m) and S.C - O(1)
	vector<int> prev(ind2 + 1, 0);
	for (int i = 1; i <= ind1; i++)
	{
		vector<int> curr(ind2 + 1, 0);
		for (int j = 1; j <= ind2; j++)
		{
			if (st1[i - 1] == st2[j - 1])
			{
				curr[j] = 1 + prev[j - 1];
			}
			else
			{
				curr[j] = max(prev[j], curr[j - 1]);
			}
		}
		prev = curr;
	}
	cout << prev[ind2];
}