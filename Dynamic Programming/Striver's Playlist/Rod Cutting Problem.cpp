/*

*/
#include<bits/stdc++.h>
using namespace std;

// Recursion - TC - exponential and SC-O(n)
// Memoization - TC - O(n*n) and SC - O(n*n) + O(n)
/*
int max_profit(int index, vector<int>& price, int len, vector<vector<int>>& dp)
{
	if (index == 0)
	{
		return price[0] * len;
	}
	if (dp[index][len] != -1)
	{
		return dp[index][len];
	}
	int cut = 0;
	if (index + 1 <= len)
	{
		cut = price[index] + max_profit(index, price, len - (index + 1), dp);
	}
	int not_cut = max_profit(index - 1, price, len, dp);
	return dp[index][len] = max(cut, not_cut);
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> price(n);
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	vector<vector<int>> dp(n, vector<int>(n + 1, 0));
	//cout << max_profit(n - 1, price, n, dp);

	//Tabulation - TC - O(n*n) and SC - O(n*n)
	/*for (int i = 0; i <= n; i++)
	{
		dp[0][i] = price[0] * i;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int cut = 0;
			if (i + 1 <= j)
			{
				cut = price[i] + dp[i][j - (i + 1)];
			}
			int not_cut = dp[i - 1][j];
			dp[i][j] = max(cut, not_cut);
		}
	}
	cout << dp[n - 1][n];*/

	// Space Optimised using two rows
	/*vector<int> prev(n + 1, 0);
	for (int i = 0; i <= n; i++)
	{
		prev[i] = price[0] * i;
	}

	for (int i = 1; i < n; i++)
	{
		vector<int> curr(n + 1, 0);
		for (int j = 0; j <= n; j++)
		{
			int cut = 0;
			if (i + 1 <= j)
			{
				cut = price[i] + curr[j - (i + 1)];
			}
			int not_cut = prev[j];
			curr[j] = max(cut, not_cut);
		}
		prev = curr;
	}
	cout << prev[n];*/

	// Space Optimised using 1 row
	vector<int> prev(n + 1, 0);
	for (int i = 0; i <= n; i++)
	{
		prev[i] = price[0] * i;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int cut = 0;
			if (i + 1 <= j)
			{
				cut = price[i] + prev[j - (i + 1)];
			}
			int not_cut = prev[j];
			prev[j] = max(cut, not_cut);
		}
	}
	cout << prev[n];
}